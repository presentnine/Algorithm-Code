#include <iostream>

using namespace std;

typedef struct ListNode {
	int data;
	ListNode* link;
}ListNode;

typedef struct {
	ListNode* head;
}LinkedListType;

void init(LinkedListType *L) {
	L->head = NULL;
}

void addFirst(LinkedListType* L, int item) {
	ListNode* node = new ListNode;
	node->data = item;
	node->link = L->head;
	L->head = node;
}

void addLast(LinkedListType* L, int item) {
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

void add(LinkedListType* L, int pos, int item) {
	ListNode* node = new ListNode;
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++)
		before = before->link;
	node->data = item;
	node->link = before->link;
	before->link = node;
}

int get(LinkedListType* L, int pos) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;

	return p->data;
}

void set(LinkedListType* L, int pos, int item) {
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;

	p->data = item;
}

void printList(LinkedListType* L) {
	for (ListNode* p = L->head; p != NULL; p = p->link)
		cout << "[" << p->data << "] -> ";
	cout << "NULL" << endl;
}

//remove, remove first, remove last 모두 구현

void main() {
	LinkedListType list;
	init(&list);

	addFirst(&list, 10); printList(&list);
	addFirst(&list, 20); printList(&list);
	addFirst(&list, 30); printList(&list);

	add(&list, 1, 40); printList(&list);
	add(&list, 1, 50); printList(&list);
	add(&list, 3, 60); printList(&list);

	int pos;
	cout << endl << "몇 번 노드의 값을 반환할까요? ";
	cin >> pos;
	cout << pos << "번 노드의 값은 " << get(&list, pos) << endl;
}