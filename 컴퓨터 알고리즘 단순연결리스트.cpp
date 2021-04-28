#include <iostream>

using namespace std;

typedef struct ListNode {//노드 타입
	int data;
	ListNode* link;
}ListNode;

typedef struct {//단순연결리스트
	ListNode* head;
}LinkedListType;

void init1(LinkedListType *L) {//초기화
	L->head = NULL;
}

void addFirst1(LinkedListType* L, int item) {//앞 삽입 함수
	ListNode* node = new ListNode;
	node->data = item;
	node->link = L->head;
	L->head = node;
}

void addLast1(LinkedListType* L, int item) {//마지막 삽입 함수
	ListNode* node = new ListNode;
	node->data = item;
	node->link = NULL;

	if (L->head == NULL) {
		L->head = node;
		return;
	}

	ListNode* temp = L->head;

	while (temp->link != NULL)
		temp = temp->link;

	temp->link = node;
}

void add1(LinkedListType* L, int pos, int item) {//특정 위치 삽입 함수
	if (pos == 0) {
		addFirst1(L, item);
		return;
	}

	ListNode* node = new ListNode;
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++) {
		if (before == NULL) {//빈 연결리스트
			printf("빈 연결리스트입니다.");
			exit(1);
		}
		before = before->link;
	}
		
	node->data = item;
	node->link = before->link;
	before->link = node;
}

int get1(LinkedListType* L, int pos) {//특정 위치 데이터 반환
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;

	return p->data;
}

void set1(LinkedListType* L, int pos, int item) {//특정 위치 데이터 변경
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;

	p->data = item;
}

void printList1(LinkedListType* L) {//리스트 출력 함수
	for (ListNode* p = L->head; p != NULL; p = p->link)
		cout << "[" << p->data << "] -> ";
	cout << "NULL" << endl;
}

int removeFirst1(LinkedListType* L) {//앞 제거 함수
	ListNode* element = L->head;
	int data;
	if (L->head == NULL) {
		printf("빈 연결리스트입니다.");
		exit(1);
	}

	data = element->data;
	L->head = L->head->link;

	free(element);

	return data;
}

int removeLast1(LinkedListType* L) {//마지막 제거 함수
	ListNode* before = L->head;
	ListNode* element;
	int data;

	if (before == NULL) {//빈 연결리스트
		printf("빈 연결리스트입니다.");
		exit(1);
	}

	if (before->link == NULL) {//유일한 노드
		data = before->data;
		L->head = NULL;
		return data;
	}

	element = before->link;

	while (element->link != NULL) {
		before = before->link;
		element = before->link;
	}

	data = element->data;
	before->link = NULL;

	free(element);

	return data;
}

int remove1(LinkedListType* L, int pos) {//특정 위치 제거 함수
	ListNode* before = L->head;
	ListNode* element;
	int data;

	if (pos == 0) {//위치가 0이면 removeFirst 호출
		return removeFirst1(L);
	}

	for (int i = 0; i < pos-1; i++) {
		if (before == NULL) {//위치가 길이보다 긴 경우
			printf("유효하지 않은 위치입니다.");
			exit(1);
		}
		before = before->link;
	}

	element = before->link;

	if (element == NULL) {
		printf("유효하지 않은 위치입니다.");
		exit(1);
	}

	data = element->data;
	before->link = element->link;

	free(element);

	return data;
}

void main1() {
	LinkedListType list;
}