#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int h[100] = { 0 };
int n = 0;

void insertItem(int key);
void removeMax();
void upHeap(int i);
void downHeap(int i);
void printHeap();

int main() {
	char command;

	while (1) {
		scanf(" %c", &command);

		if (command == 'q')
			break;

		else if (command == 'i') {
			int key;
			scanf("%d", &key);
			insertItem(key);
		}

		else if (command == 'd') {
			removeMax();
		}

		else if (command == 'p') {
			printHeap();
		}


	}
	return 0;
}


void insertItem(int key) {
	n++;
	h[n] = key;
	upHeap(n);
	printf("0\n");
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

void removeMax() {
	if (n == 0) {
		printf("Heap is empty!");
		return;
	}

	printf("%d\n", h[1]);
	h[1] = h[n];
	h[n] = 0;
	n--;
	downHeap(1);
}

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

void printHeap() {
	for (int j = 1; j <= n; j++) {
		printf(" %d", h[j]);
	}
	printf("\n");
}
