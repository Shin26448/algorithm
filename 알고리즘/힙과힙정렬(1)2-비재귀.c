#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int h[100] = { 0 };
int n;

void insertItem(int key);
void removeMax();
void buildheap();
void downHeap(int i);
void printHeap();

int main() {
	scanf("%d", &n);
	for (int j = 1; j <= n; j++) {
		scanf("%d", &h[j]);
	}

	buildHeap();
	printHeap();
	return 0;
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

void printHeap() {
	for (int k = 1; k <= n; k++) {
		printf(" %d", h[k]);
	}
	printf("\n");
}
