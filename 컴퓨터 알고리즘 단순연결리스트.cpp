#include <iostream>

using namespace std;

typedef struct ListNode {//��� Ÿ��
	int data;
	ListNode* link;
}ListNode;

typedef struct {//�ܼ����Ḯ��Ʈ
	ListNode* head;
}LinkedListType;

void init(LinkedListType *L) {//�ʱ�ȭ
	L->head = NULL;
}

void addFirst(LinkedListType* L, int item) {//�� ���� �Լ�
	ListNode* node = new ListNode;
	node->data = item;
	node->link = L->head;
	L->head = node;
}

void addLast(LinkedListType* L, int item) {//������ ���� �Լ�
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

void add(LinkedListType* L, int pos, int item) {//Ư�� ��ġ ���� �Լ�
	if (pos == 0) {
		addFirst(L, item);
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

int get(LinkedListType* L, int pos) {//Ư�� ��ġ ������ ��ȯ
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;

	return p->data;
}

void set(LinkedListType* L, int pos, int item) {//Ư�� ��ġ ������ ����
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;

	p->data = item;
}

void printList(LinkedListType* L) {//����Ʈ ��� �Լ�
	for (ListNode* p = L->head; p != NULL; p = p->link)
		cout << "[" << p->data << "] -> ";
	cout << "NULL" << endl;
}

int removeFirst(LinkedListType* L) {//�� ���� �Լ�
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

int removeLast(LinkedListType* L) {//������ ���� �Լ�
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

int remove(LinkedListType* L, int pos) {//Ư�� ��ġ ���� �Լ�
	ListNode* before = L->head;
	ListNode* element;
	int data;

	if (pos == 0) {//��ġ�� 0�̸� removeFirst ȣ��
		return removeFirst(L);
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

void main() {
	LinkedListType list;
	init(&list);

	cout << "addFirst ����" << endl;
	addFirst(&list, 10); printList(&list);
	addFirst(&list, 20); printList(&list);
	addFirst(&list, 30); printList(&list);

	cout << "add ����" << endl;
	add(&list, 0, 40); printList(&list);
	add(&list, 1, 50); printList(&list);
	add(&list, 3, 60); printList(&list);

	cout << "addLast ����" << endl;
	addLast(&list, 70); printList(&list);
	addLast(&list, 80); printList(&list);
	addLast(&list, 90); printList(&list);

	cout << "removeFirst ����" << endl;
	cout << removeFirst(&list) << " ����" << endl; printList(&list);
	cout << removeFirst(&list) << " ����" << endl; printList(&list);

	cout << "remove ����" << endl;
	cout << remove(&list,3) << " ����" << endl; printList(&list);
	cout << remove(&list,0) << " ����" << endl; printList(&list);

	cout << "removeLast ����" << endl;
	cout << removeLast(&list) << " ����" << endl; printList(&list);
	cout << removeLast(&list) << " ����" << endl; printList(&list);

	int pos;
	cout << endl << "�� �� ����� ���� ��ȯ�ұ��?(�ε���x, ����) ";
	cin >> pos;
	cout << pos << "�� ����� ���� " << get(&list, pos) << endl;
}