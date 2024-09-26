#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)



int main() {
    int n, num;
    scanf("%d", &n);  
    int* r = (int*)malloc(n * sizeof(int));


    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }

    for (int i = 1; i < n; i++) {
        int current = r[i];
        int j = i - 1;

        while (j >= 0 && r[j] > current) {
            r[j + 1] = r[j];
            j--;
        }
        r[j + 1] = current;

        
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", r[i]);
    }

    free(r);  
    return 0;
}
