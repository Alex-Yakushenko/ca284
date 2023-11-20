#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
    int value;
    Node *next;
};

void populate(Node *head, int * n, char **argv);
void printLL(Node *head);

int main(int argc, char*argv[]) {

    int length = atoi(argv[1]);
    Node head;
    populate(&head, &length, argv);
    printLL(&head);

    return 0;
}

void populate(Node *head, int * n, char **argv) {
    Node *current = head; 
    for (int i = 0; i < *n; i++) {
        current->value = atoi(argv[i+2]);
        current->next = malloc(sizeof(Node));
        current = current->next;
    }
    current->next = NULL;
}

void printLL(Node *head)
{
    Node *current = head;
    while (current->next != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}