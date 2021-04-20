#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE 100

typedef struct HeapType {//힙 구조체
	int heap[SIZE];
	int heap_size;
}HeapType;

typedef struct StackType {//스택 구조체
	int stack[SIZE];
	int top;
}StackType;

void init_Heap(HeapType& h) {//힙 초기화 함수
	h.heap_size = 0;
}

void upHeap(HeapType& h) {//힙 속성 정렬(최소힙 형태)
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

void insertItem(HeapType& h, int key) {//key 삽입 함수
	h.heap_size++;
	h.heap[h.heap_size] = key;
	upHeap(h);
}

void print_Heap(HeapType& h) {//힙 출력 함수
	cout << "힙 출력" << endl;
	for (int i = 1; i <= h.heap_size; i++)
		cout << "[" << h.heap[i] << "] ";
	cout << endl;
}

void init_Stack(StackType& s) {//스택 초기화 함수
	s.top = -1;
}

bool is_Empty(StackType& s) {//빈 스택 확인 함수
	if (s.top == -1)
		return true;
	else
		return false;
}

void push_Stack(StackType& s, int data) {//스택 push 함수
	s.stack[++s.top] = data;
}

int pop_Stack(StackType& s) {//스택 pop 함수
	if (is_Empty(s)) {
		cout << "빈 스택입니다." << endl;
		exit(-1);
	}

	int data = s.stack[s.top--];

	return data;
}

void print_Stack(StackType& s) {//스택 출력 함수
	cout << "스택 출력" << endl;
	for (int i = 0; i <= s.top; i++)
		cout << "[" << s.stack[i] << "] ";
	cout << endl;
}

void binaryExpansion(int i, StackType& s) {//스택을 이용한 2진법 변환 함수
	while (i >= 2) {
		push_Stack(s, i % 2);
		i /= 2;
	}

	push_Stack(s, i);
	print_Stack(s);
}

int findLastNode(HeapType& h, int n) {//마지막 노드 값 찾기
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

	cout << "힙의 크기를 입력하세요(1~99 사이): ";
	cin >> size;

	for (int i = 0; i < size; i++) {
		insertItem(h, rand() % 100);
	}

	print_Heap(h);

	cout << "마지막 노드: " << findLastNode(h, size) << endl;

	return 0;
}