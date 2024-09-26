#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// downHeap �Լ�: Ư�� �ε��� i���� �����Ͽ� �� �Ӽ��� �����ϵ��� ������
void downHeap(int h[], int n, int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;

    if (left <= n && h[left] > h[largest]) {
        largest = left;
    }
    if (right <= n && h[right] > h[largest]) {
        largest = right;
    }

    if (largest != i) {
        int tmp = h[i];
        h[i] = h[largest];
        h[largest] = tmp;
        downHeap(h, n, largest);
    }
}

// upHeap �Լ�: ���Ե� ��尡 �� ������ ������ ������ �θ�� ���Ͽ� �ö󰡴� ����
void upHeap(int h[], int i) {
    int parent = i / 2;
    if (i == 1 || h[i] <= h[parent]) return;  // ��Ʈ ���ų� �θ𺸴� ������ ����

    int tmp = h[i];
    h[i] = h[parent];
    h[parent] = tmp;
    upHeap(h, parent);
}

// insertItem �Լ�: ���� ���ο� Ű�� ����
int insertItem(int h[], int n, int key) {
    n++;
    h[n] = key;
    upHeap(h, n);
    return n;  // ���ο� ���� ũ�� ��ȯ
}

// buildHeap �Լ�: �迭�� ��������� �� ����
void buildHeap(int h[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        downHeap(h, n, i);
    }
}

// �� ������ ���ڸ����� �����ϴ� �Լ�
void inPlaceHeapSort(int h[], int n) {
    buildHeap(h, n);  // 1�� �۾�: �� ����

    // 2�� �۾�: �� ���� ����
    for (int i = n; i > 1; i--) {
        // ������ ���� ū ���� ���������� ������ �� ũ�⸦ ����
        int tmp = h[1];
        h[1] = h[i];
        h[i] = tmp;

        // ũ�⸦ ���� ������ �ٽ� downHeap ����
        downHeap(h, i - 1, 1);
    }
}

// printArray �Լ�: �迭�� ����ϴ� �Լ�
void printArray(int h[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", h[i]);
    }
    printf("\n");
}

// ���� �Լ�
int main() {
    int h[100], n = 0, key;

    // Ű ���� �Է�
    int keyCount;
    scanf("%d", &keyCount);

    // Ű�� �Է� �� ���� ����
    for (int i = 0; i < keyCount; i++) {
        scanf("%d", &key);
        n = insertItem(h, n, key);
    }

    // �� ���� ����
    inPlaceHeapSort(h, n);

    // ���ĵ� �迭 ���
    printArray(h, n);

    return 0;
}
