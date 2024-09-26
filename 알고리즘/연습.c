#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// downHeap 함수: 특정 인덱스 i에서 시작하여 힙 속성을 만족하도록 재정렬
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

// upHeap 함수: 삽입된 노드가 힙 조건을 만족할 때까지 부모와 비교하여 올라가는 과정
void upHeap(int h[], int i) {
    int parent = i / 2;
    if (i == 1 || h[i] <= h[parent]) return;  // 루트 노드거나 부모보다 작으면 종료

    int tmp = h[i];
    h[i] = h[parent];
    h[parent] = tmp;
    upHeap(h, parent);
}

// insertItem 함수: 힙에 새로운 키를 삽입
int insertItem(int h[], int n, int key) {
    n++;
    h[n] = key;
    upHeap(h, n);
    return n;  // 새로운 힙의 크기 반환
}

// buildHeap 함수: 배열을 상향식으로 힙 구성
void buildHeap(int h[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        downHeap(h, n, i);
    }
}

// 힙 정렬을 제자리에서 수행하는 함수
void inPlaceHeapSort(int h[], int n) {
    buildHeap(h, n);  // 1기 작업: 힙 구성

    // 2기 작업: 힙 정렬 수행
    for (int i = n; i > 1; i--) {
        // 힙에서 가장 큰 값을 마지막으로 보내고 힙 크기를 줄임
        int tmp = h[1];
        h[1] = h[i];
        h[i] = tmp;

        // 크기를 줄인 힙에서 다시 downHeap 수행
        downHeap(h, i - 1, 1);
    }
}

// printArray 함수: 배열을 출력하는 함수
void printArray(int h[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", h[i]);
    }
    printf("\n");
}

// 메인 함수
int main() {
    int h[100], n = 0, key;

    // 키 개수 입력
    int keyCount;
    scanf("%d", &keyCount);

    // 키들 입력 및 힙에 삽입
    for (int i = 0; i < keyCount; i++) {
        scanf("%d", &key);
        n = insertItem(h, n, key);
    }

    // 힙 정렬 수행
    inPlaceHeapSort(h, n);

    // 정렬된 배열 출력
    printArray(h, n);

    return 0;
}
