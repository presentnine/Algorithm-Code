#include <iostream>

using namespace std;

typedef struct ListNode {//노드 타입
	int data;
	ListNode* link;
}ListNode;

typedef struct {//단순연결리스트
	ListNode* head;
}LinkedListType;

void init(LinkedListType *L) {//초기화
	L->head = NULL;
}

void addFirst(LinkedListType* L, int item) {//앞 삽입 함수
	ListNode* node = new ListNode;
	node->data = item;
	node->link = L->head;
	L->head = node;
}

void addLast(LinkedListType* L, int item) {//마지막 삽입 함수
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

void add(LinkedListType* L, int pos, int item) {//특정 위치 삽입 함수
	if (pos == 0) {
		addFirst(L, item);
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

int get(LinkedListType* L, int pos) {//특정 위치 데이터 반환
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;

	return p->data;
}

void set(LinkedListType* L, int pos, int item) {//특정 위치 데이터 변경
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;

	p->data = item;
}

void printList(LinkedListType* L) {//리스트 출력 함수
	for (ListNode* p = L->head; p != NULL; p = p->link)
		cout << "[" << p->data << "] -> ";
	cout << "NULL" << endl;
}

int removeFirst(LinkedListType* L) {//앞 제거 함수
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

int removeLast(LinkedListType* L) {//마지막 제거 함수
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

int remove(LinkedListType* L, int pos) {//특정 위치 제거 함수
	ListNode* before = L->head;
	ListNode* element;
	int data;

	if (pos == 0) {//위치가 0이면 removeFirst 호출
		return removeFirst(L);
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

void main() {
	LinkedListType list;
	init(&list);

	cout << "addFirst 실행" << endl;
	addFirst(&list, 10); printList(&list);
	addFirst(&list, 20); printList(&list);
	addFirst(&list, 30); printList(&list);

	cout << "add 실행" << endl;
	add(&list, 0, 40); printList(&list);
	add(&list, 1, 50); printList(&list);
	add(&list, 3, 60); printList(&list);

	cout << "addLast 실행" << endl;
	addLast(&list, 70); printList(&list);
	addLast(&list, 80); printList(&list);
	addLast(&list, 90); printList(&list);

	cout << "removeFirst 실행" << endl;
	cout << removeFirst(&list) << " 제거" << endl; printList(&list);
	cout << removeFirst(&list) << " 제거" << endl; printList(&list);

	cout << "remove 실행" << endl;
	cout << remove(&list,3) << " 제거" << endl; printList(&list);
	cout << remove(&list,0) << " 제거" << endl; printList(&list);

	cout << "removeLast 실행" << endl;
	cout << removeLast(&list) << " 제거" << endl; printList(&list);
	cout << removeLast(&list) << " 제거" << endl; printList(&list);

	int pos;
	cout << endl << "몇 번 노드의 값을 반환할까요?(인덱스x, 순서) ";
	cin >> pos;
	cout << pos << "번 노드의 값은 " << get(&list, pos) << endl;
}