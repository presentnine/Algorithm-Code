#include <iostream>

using namespace std;

typedef struct ListNode {//노드 타입
	int data;
	ListNode* link;
}ListNode;

typedef struct {//원형연결리스트 타입
	ListNode* head;
}CircularLinkedListType;

void init(CircularLinkedListType* L) {//초기화
	L->head = NULL;
}

void buildList(CircularLinkedListType* L, int n) {//리스트 생성
	ListNode* node = new ListNode;
	
	node->data = 1;
	L->head = node;

	for (int i = 2; i <= n; i++) {
		ListNode* temp = new ListNode;
		temp->data = i;

		node->link = temp;
		node = node->link;
	}

	node->link = L->head;
}

int runSimulationList(CircularLinkedListType* L, int n, int k) {//모의실행
	ListNode* node = L->head;

	while (node != node->link) {
		for (int i = 1; i < k; i++) {
			node = node->link;
		}

		ListNode* temp = node->link;
		node->link = node->link->link;
		free(temp);
		node = node->link;
	}

	return node->data;
}

int main() {
	int n;//초의 총 개수
	int k;//건너뛸 개수

	cout << "초의 개수를 입력하세요: ";
	cin >> n;

	cout << "건너뛸 초의 개수를 입력하세요: ";
	cin >> k;

	CircularLinkedListType cakeCandle;
	buildList(&cakeCandle, n);
	cout << runSimulationList(&cakeCandle, n, k) << "번 째 초입니다." << endl;

	return 0;
}