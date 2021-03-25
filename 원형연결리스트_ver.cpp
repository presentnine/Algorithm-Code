#include <iostream>

using namespace std;

typedef struct ListNode {//��� Ÿ��
	int data;
	ListNode* link;
}ListNode;

typedef struct {//�������Ḯ��Ʈ Ÿ��
	ListNode* head;
}CircularLinkedListType;

void init(CircularLinkedListType* L) {//�ʱ�ȭ
	L->head = NULL;
}

void buildList(CircularLinkedListType* L, int n) {//����Ʈ ����
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

int runSimulationList(CircularLinkedListType* L, int n, int k) {//���ǽ���
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
	int n;//���� �� ����
	int k;//�ǳʶ� ����

	cout << "���� ������ �Է��ϼ���: ";
	cin >> n;

	cout << "�ǳʶ� ���� ������ �Է��ϼ���: ";
	cin >> k;

	CircularLinkedListType cakeCandle;
	buildList(&cakeCandle, n);
	cout << runSimulationList(&cakeCandle, n, k) << "�� ° ���Դϴ�." << endl;

	return 0;
}