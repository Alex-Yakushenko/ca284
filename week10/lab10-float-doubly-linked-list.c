#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
    float value;
    Node *next;
    Node *prev;
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
    current->prev = NULL;
    for (int i = 0; i < *n; i++) {
        current->value = atof(argv[i + 2]);
        if (i < *n - 1) {
            current->next = malloc(sizeof(Node));
            current->next->prev = current;
            current = current->next;
        }
    }
    current->next = NULL;
}

void printLL(Node *head)
{
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    while (current != NULL) {
        printf("%.2f\n", current->value);
        current = current->prev;
    }
}