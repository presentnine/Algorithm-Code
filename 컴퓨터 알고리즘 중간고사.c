#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct DListNode {
	int elem;
	struct DListNode* prev, * next;
}DListNode;

typedef struct {
	DListNode* H;
	DListNode* T;
}SetType;

void initNode(DListNode* H, DListNode* T) {
	H->next = T;
	H->prev = NULL;
	T->prev = H;
	T->next = NULL;
}

void initSet(SetType* S) {
	S->H = (DListNode*)malloc(sizeof(DListNode));
	S->T = (DListNode*)malloc(sizeof(DListNode));
	initNode(S->H, S->T);
}

void addLast(SetType* S, int item) {
	DListNode* temp = (DListNode*)malloc(sizeof(DListNode));
	temp->elem = item;

	DListNode* prevLast = S->T->prev;

	prevLast->next = temp;
	temp->prev = prevLast;
	S->T->prev = temp;
	temp->next = S->T;
}

void printSetType(SetType* S) {
	DListNode* temp = S->H->next;

	while (temp != S->T) {
		printf("[%d] ", temp->elem);
		temp = temp->next;
	}
	printf("\n");
}

void deleteDuplicate(SetType* S) {
	DListNode* deleteNode = S->H->next;

	while (deleteNode != S->T->prev) {
		if (deleteNode->elem == deleteNode->next->elem) {
			deleteNode->prev->next = deleteNode->next;
			deleteNode->next->prev = deleteNode->prev;
			
		}
		deleteNode = deleteNode->next;
	}
}

void inPlaceSelectionSort(SetType *S) {
	int temp = 0;
	DListNode* startNode = S->H->next;

	while (startNode != S->T->prev) {
		int min = startNode->elem;
		DListNode* tempNode = startNode->next;
		DListNode* changeNode = startNode;

		while (tempNode != S->T) {
			if (tempNode->elem < min) {
				min = tempNode->elem;
				changeNode = tempNode;
			}
			tempNode = tempNode->next;
		}

		temp = min;
		changeNode->elem = startNode->elem;
		startNode->elem = temp;
		
		startNode = startNode->next;
	}

	deleteDuplicate(S);
}

void inPlaceInsertionSort(SetType* S) {
	DListNode* startNode = S->H->next->next;

	while (startNode != S->T) {
		int save = startNode->elem;

		DListNode* tempNode = startNode->prev;
		while (tempNode != S->H && tempNode->elem > save) {
			tempNode->next->elem = tempNode->elem;
			tempNode = tempNode->prev;
		}
		tempNode->next->elem = save;

		startNode = startNode->next;
	}

	deleteDuplicate(S);
}

SetType* add(SetType* A, SetType* B) {
	SetType* result = (SetType*)malloc(sizeof(SetType));
	initSet(result);

	DListNode* startA = A->H->next;
	DListNode* startB = B->H->next;

	while (startA != A->T && startB != B->T) {
		if (startA->elem < startB->elem) {
			addLast(result, startA->elem);
			startA = startA->next;
		}
		else if (startA->elem > startB->elem) {
			addLast(result, startB->elem);
			startB = startB->next;
		}
		else {
			addLast(result, startA->elem);
			startA = startA->next;
			startB = startB->next;
		}
	}

	while (startA != A->T) {
		addLast(result, startA->elem);
		startA = startA->next;
	}

	while (startB != B->T) {
		addLast(result, startB->elem);
		startB = startB->next;
	}

	return result;
}

SetType* minus(SetType* A, SetType* B) {
	SetType* result = (SetType*)malloc(sizeof(SetType));
	initSet(result);

	DListNode* startA = A->H->next;
	DListNode* startB = B->H->next;

	while (startB != B->T) {
		while (startA->elem < startB->elem) {
			addLast(result, startA->elem);
			startA = startA->next;
		}
			
		if (startA->elem == startB->elem) {
			startA = startA->next;
		}

		startB = startB->next;
	}

	while (startA != A->T) {
		addLast(result, startA->elem);
		startA = startA->next;
	}

	return result;
}

int main() {
	srand(time(NULL));

	SetType* s1 = (SetType*)malloc(sizeof(SetType));
	SetType* s2 = (SetType*)malloc(sizeof(SetType));
	initSet(s1);
	initSet(s2);

	int size;
	printf("원소의 개수 입력: ");
	scanf_s("%d", &size);

	for (int i = 0; i < size; i++) {
		addLast(s1, rand() % 30 + 11);
		addLast(s2, rand() % 30 + 11);
	}

	printf("리스트 A: ");
	printSetType(s1);
	printf("리스트 B: ");
	printSetType(s2);

	printf("\n");

	inPlaceSelectionSort(s1);
	printf("선택정렬 - 집합 A: ");
	printSetType(s1);
	inPlaceInsertionSort(s2);
	printf("삽입정렬 - 집합 B: ");
	printSetType(s2);

	printf("\n");

	SetType* sum = add(s1, s2);
	printf("A와 B의 합집합: ");
	printSetType(sum);

	SetType* diff = minus(s1, s2);
	printf("A와 B의 차집합: ");
	printSetType(diff);

	return 0;
}