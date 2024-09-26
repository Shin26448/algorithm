/*#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int h[100] = { 0 };
int size;

void insertItem(int key);
void removeMax();
void rBuildheap(int i);
void downHeap(int i);
void printHeap();

int main() {
	scanf("%d", &size);
	for (int j = 1; j <= size; j++) {
		scanf("%d", &h[j]);
	}

	rBuildHeap(1);
	printHeap();
	return 0;
}

void rBuildHeap(int i) {
	if (i > size / 2)
		return;

	rBuildHeap (2 * i);
	rBuildHeap(2 * i + 1);

	downHeap(i);
};

void downHeap(int i) {
	while (i * 2 <= size) {// 자식을 갖고 있을 때까지
		int current = i;
		int left = i * 2;
		int right = i * 2 + 1;

		if (left <= size && h[left] > h[current])
			current = left;
		if (right <= size && h[right] > h[current])
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
	for (int k = 1; k <= size; k++) {
		printf(" %d", h[k]);
	}
	printf("\n");
}*/
