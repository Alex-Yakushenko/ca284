#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
    int value;
    Node *next;
    Node *prev;
};

void populate(Node *head, int * n, char **argv);
void printLL(Node *head);
void pop(Node *head);
void push(Node *head, char *argv[], int *index);

int main(int argc, char*argv[]) {

    int length = atoi(argv[1]);
    Node head;
    int index = length + 2;
    populate(&head, &length, argv);
    pop(&head);
    pop(&head);  
    push(&head, argv, &index);
    push(&head, argv, &index);
    printLL(&head);


    return 0;
}

void populate(Node *head, int * n, char **argv) {
    Node *current = head; 
    current->prev = NULL;
    for (int i = 0; i < *n; i++) {
        current->value = atoi(argv[i + 2]);
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
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void pop(Node *head) {
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
}
void push(Node *head, char *argv[], int *index) {;
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(Node));
    current->next->prev = current;
    current = current->next;
    current->value = atoi(argv[*index]);
    current->next = NULL;

    *index += 1;
}

