#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

typedef struct node {
    struct node* prev;
    char elem;
    struct node* next;
} NODE;

typedef struct list {
    NODE* header;
    NODE* trailer;
    int numofdata;
} LIST;

NODE* getNode() {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->elem = '\0';

    return newNode;
}

LIST* initList() {
    LIST* L = (LIST*)malloc(sizeof(LIST));
    L->header = getNode();
    L->trailer = getNode();
    L->header->next = L->trailer;
    L->trailer->prev = L->header;
    L->numofdata = 0;
    return L;
}

void add(LIST* L, int r, char e) {
    NODE* newNode = getNode();
    newNode->elem = e;
    NODE* current = L->header;

    if (r > L->numofdata + 1) {
        printf("invalid position\n");
        return;
    }

    for (int i = 0; i < r - 1; i++) {
        current = current->next;
    }
    newNode->prev = current;
    newNode->next = (current->next);
    (current->next)->prev = newNode;
    current->next = newNode;

    L->numofdata++;
}

void delete(LIST* L, int r) {
    NODE* current = L->header->next;

    if (r > L->numofdata) {
        printf("invalid position\n");
        return;
    }

    for (int i = 0; i < r - 1; i++) {
        current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    L->numofdata--;
}

void get(LIST* L, int r) {
    NODE* current = L->header->next;

    if (r > L->numofdata) {
        printf("invalid position\n");
        return;
    }

    for (int i = 0; i < r - 1; i++) {
        current = current->next;
    }
    printf("%c\n", current->elem);
}

void print(LIST* L) {
    NODE* current = L->header->next;
    while (current != L->trailer) {
        printf("%c", current->elem);
        current = current->next;
    }
    printf("\n");
}

int main() {

    int n, r;
    char command, e;
    LIST* L = initList();

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {

        scanf(" %c", &command);

        if (command == 'A') {
            scanf("%d %c", &r, &e);
            add(L, r, e);
        }

        else if (command == 'D') {
            scanf("%d", &r);
            delete(L, r);
        }

        else if (command == 'G') {
            scanf("%d", &r);
            get(L, r);
        }

        else if (command == 'P') {
            print(L);
        }
    }

    return 0;
}
