#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE 100

typedef struct HeapType {//�� ����ü
	int heap[SIZE];
	int heap_size;
}HeapType;

typedef struct StackType {//���� ����ü
	int stack[SIZE];
	int top;
}StackType;

void init_Heap(HeapType& h) {//�� �ʱ�ȭ �Լ�
	h.heap_size = 0;
}

void upHeap(HeapType& h) {//�� �Ӽ� ����(�ּ��� ����)
	int position = h.heap_size;
	int key = h.heap[position];

	while (position > 1) {
		if (key >= h.heap[position / 2])
			break;

		h.heap[position] = h.heap[position / 2];
		position /= 2;
	}

	h.heap[position] = key;
}

void insertItem(HeapType& h, int key) {//key ���� �Լ�
	h.heap_size++;
	h.heap[h.heap_size] = key;
	upHeap(h);
}

void print_Heap(HeapType& h) {//�� ��� �Լ�
	cout << "�� ���" << endl;
	for (int i = 1; i <= h.heap_size; i++)
		cout << "[" << h.heap[i] << "] ";
	cout << endl;
}

void init_Stack(StackType& s) {//���� �ʱ�ȭ �Լ�
	s.top = -1;
}

bool is_Empty(StackType& s) {//�� ���� Ȯ�� �Լ�
	if (s.top == -1)
		return true;
	else
		return false;
}

void push_Stack(StackType& s, int data) {//���� push �Լ�
	s.stack[++s.top] = data;
}

int pop_Stack(StackType& s) {//���� pop �Լ�
	if (is_Empty(s)) {
		cout << "�� �����Դϴ�." << endl;
		exit(-1);
	}

	int data = s.stack[s.top--];

	return data;
}

void print_Stack(StackType& s) {//���� ��� �Լ�
	cout << "���� ���" << endl;
	for (int i = 0; i <= s.top; i++)
		cout << "[" << s.stack[i] << "] ";
	cout << endl;
}

void binaryExpansion(int i, StackType& s) {//������ �̿��� 2���� ��ȯ �Լ�
	while (i >= 2) {
		push_Stack(s, i % 2);
		i /= 2;
	}

	push_Stack(s, i);
	print_Stack(s);
}

int findLastNode(HeapType& h, int n) {//������ ��� �� ã��
	int pos = 1;

	StackType s;
	init_Stack(s);
	binaryExpansion(n, s);
	pop_Stack(s);

	while (!is_Empty(s)) {
		int bit = pop_Stack(s);
		if (bit == 0)
			pos = pos * 2;
		else
			pos = pos * 2 + 1;
	}

	return h.heap[pos];
}

int main1() {
	int size;

	srand(time(NULL));

	HeapType h;
	init_Heap(h);

	cout << "���� ũ�⸦ �Է��ϼ���(1~99 ����): ";
	cin >> size;

	for (int i = 0; i < size; i++) {
		insertItem(h, rand() % 100);
	}

	print_Heap(h);

	cout << "������ ���: " << findLastNode(h, size) << endl;

	return 0;
}