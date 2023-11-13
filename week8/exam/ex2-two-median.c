#include <stdio.h>
#include <stdlib.h>


void bubble(int *arr, int * length);
void populate(char*argv[], int *arr, int * length);

int main(int argc, char*argv[])
{
    int length = argc - 1;
    int numbers[100];
    int *pNumbers = numbers;
    populate(argv, pNumbers, &length);
    bubble(pNumbers, &length);
    int mid = length / 2;
    printf("%d\n", numbers[mid - 1]);
    printf("%d\n", numbers[mid]);

    return 0;
}
void bubble(int *arr, int * length) {
    int temp;
    int sorted;
    do {
        sorted = 0;
        for (int i = 0; i < *length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                sorted = 1;
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    } while (sorted == 1);
}

void populate(char*argv[], int *arr, int *length)
{
    for (int i = 0; i < *length; i++) {
        arr[i] = atoi(argv[i + 1]);
    }
}

