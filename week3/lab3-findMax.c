#include <stdio.h>
#include <stdlib.h>

int findMax(int arr[], int length) {
    int i;
    int max = arr[0];
    for (i = 1; i < length; i ++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int main(int argc, char*argv[]) {
    int length = argc - 1;
    int i;
    int numbers[length];
    for (i = 0; i < length; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }
    int max = findMax(numbers, length);
    printf("%d\n", max);

    return 0;
}