#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
    int n, num;
    scanf("%d", &n);
    int* r = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        r[i] = num;  
    }

    int count = n,tmp;
    for (int i = 0; i < n-1; i++) {
        int max = 0, maxpoint = 0;
        for (int j = 0; j < count; j++) {
            if (r[j] > max) {
                max = r[j];
                maxpoint = j;
            }
        }
        tmp = r[maxpoint];
        r[maxpoint] = r[count-1];
        r[count-1] = tmp;
        count--;

        

    }


    for (int i = 0; i < n; i++) {
        printf(" %d", r[i]);
    }
  
    free(r);
    return 0;
}
