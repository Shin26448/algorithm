#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int h[100] = { 0 };
int n;

void inPlaceHeapSort();
void downHeap(int i);
void insertItem(int key);
void upHeap(int i);
void buildHeap();
void printArray();

int main() {
	scanf("%d", &n);
	for (int j = 1; j <= n; j++) {
		scanf("%d", &h[j]);
		insertItem(h[j]);
	}

	inPlaceHeapSort();

	printArray();
	
	return 0;
}

void insertItem(int key) {
	n++;
	h[n] = key;
	upHeap(n);
}

void upHeap(int i) {
	int tmp;
	while (i > 1 && h[i] > h[i / 2]) {
		tmp = h[i];
		h[i] = h[i / 2];
		h[i / 2] = tmp;
		i = i / 2;
	}
}

void inPlaceHeapSort() {
	buildHeap();

	for (int i = n; i > 1; i--) {
		int tmp = h[1];
		h[1] = h[i];
		h[i] = tmp;

		n--;

		downHeap(1);
	}
}


void buildHeap() {
	for (int i = n / 2; i >= 1; i--)
		downHeap(i);
};

void downHeap(int i) {
	while (i * 2 <= n) {// 자식을 갖고 있을 때까지
		int current = i;
		int left = i * 2;
		int right = i * 2 + 1;

		if (left <= n && h[left] > h[current])
			current = left;
		if (right <= n && h[right] > h[current])
			current = right;

		if (current == i)
			break;

		int tmp = h[i];
		h[i] = h[current];
		h[current] = tmp;

		i = current;
	}
}

void printArray() {
	for (int j = 1; j <= n; j++) {
		printf(" %d", h[j]);
	}
}

