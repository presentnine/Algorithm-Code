#include <iostream>

using namespace std;

typedef struct ListNode {//��� Ÿ��
	int data;
	ListNode* link;
}ListNode;

typedef struct {//�ܼ����Ḯ��Ʈ
	ListNode* head;
}LinkedListType;

void init1(LinkedListType *L) {//�ʱ�ȭ
	L->head = NULL;
}

void addFirst1(LinkedListType* L, int item) {//�� ���� �Լ�
	ListNode* node = new ListNode;
	node->data = item;
	node->link = L->head;
	L->head = node;
}

void addLast1(LinkedListType* L, int item) {//������ ���� �Լ�
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

void add1(LinkedListType* L, int pos, int item) {//Ư�� ��ġ ���� �Լ�
	if (pos == 0) {
		addFirst1(L, item);
		return;
	}

	ListNode* node = new ListNode;
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++) {
		if (before == NULL) {//�� ���Ḯ��Ʈ
			printf("�� ���Ḯ��Ʈ�Դϴ�.");
			exit(1);
		}
		before = before->link;
	}
		
	node->data = item;
	node->link = before->link;
	before->link = node;
}

int get1(LinkedListType* L, int pos) {//Ư�� ��ġ ������ ��ȯ
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;

	return p->data;
}

void set1(LinkedListType* L, int pos, int item) {//Ư�� ��ġ ������ ����
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;

	p->data = item;
}

void printList1(LinkedListType* L) {//����Ʈ ��� �Լ�
	for (ListNode* p = L->head; p != NULL; p = p->link)
		cout << "[" << p->data << "] -> ";
	cout << "NULL" << endl;
}

int removeFirst1(LinkedListType* L) {//�� ���� �Լ�
	ListNode* element = L->head;
	int data;
	if (L->head == NULL) {
		printf("�� ���Ḯ��Ʈ�Դϴ�.");
		exit(1);
	}

	data = element->data;
	L->head = L->head->link;

	free(element);

	return data;
}

int removeLast1(LinkedListType* L) {//������ ���� �Լ�
	ListNode* before = L->head;
	ListNode* element;
	int data;

	if (before == NULL) {//�� ���Ḯ��Ʈ
		printf("�� ���Ḯ��Ʈ�Դϴ�.");
		exit(1);
	}

	if (before->link == NULL) {//������ ���
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

int remove1(LinkedListType* L, int pos) {//Ư�� ��ġ ���� �Լ�
	ListNode* before = L->head;
	ListNode* element;
	int data;

	if (pos == 0) {//��ġ�� 0�̸� removeFirst ȣ��
		return removeFirst1(L);
	}

	for (int i = 0; i < pos-1; i++) {
		if (before == NULL) {//��ġ�� ���̺��� �� ���
			printf("��ȿ���� ���� ��ġ�Դϴ�.");
			exit(1);
		}
		before = before->link;
	}

	element = before->link;

	if (element == NULL) {
		printf("��ȿ���� ���� ��ġ�Դϴ�.");
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