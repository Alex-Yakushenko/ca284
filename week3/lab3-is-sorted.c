#include <stdio.h>
#include <stdlib.h>

void bubble(int arr[], int length) {
    int temp;
    int sorted;
    do {
        sorted = 0;
        for (int i = 0; i < length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                sorted = 1;
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    while (sorted == 1);
}
int main(int argc, char*argv[]) {
    int length = argc - 1;
    int i;
    int numbers[length];
    for (i = 0; i < length; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }
    bubble(numbers, length);
    for (i = 0; i < length; i++) {
        printf("%d\n", numbers[i]);
    }
    return 0;
}