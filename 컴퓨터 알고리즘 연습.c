#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct ListNode {
	ListNode* link;
	int data;
}ListNode;

typedef struct QueueType {
	int arr[SIZE];
	int front, rear;

}QueueType;

void init(QueueType* q) {
	q->front = -1;
	q->rear = -1;
}

void inPlaceInsertionSort(int arr[]) {
	for (int i = 1; i < 10; i++) {
		int temp = arr[i];
		int j = i - 1;
		for (; j >= 0 && arr[j] > temp; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = temp;
	}
}

void inPlaceSelectionSort(int A[]) {
	for (int i = 0; i < 9; i++) {
		int minLoc = i;
		for (int j = i + 1; j < 10; j++) {
			if (A[j] < A[minLoc])
				minLoc = j;
		}
		int temp = A[i];
		A[i] = A[minLoc];
		A[minLoc] = temp;
	}
}

int main() {
	srand(time(NULL));

	int arr[10];

	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 100;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	inPlaceSelectionSort(arr);

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

	ListNode* head;


	return 0;
}