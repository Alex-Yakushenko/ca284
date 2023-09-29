#include <stdio.h>
#include <stdlib.h>

int findDup(int arr[], int length) {
    int i, j;
    for (i = 0; i < length - 1; i++) {
        for (j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                return arr[i];
            }
        }
    }
    return -1;
}
int main(int argc, char *argv[]) {
    int length = argc - 1;
    int numbers[length];
    int i;
    for (i = 0; i < length; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }
    
    int duplicate = findDup(numbers, length);
    
    if (duplicate == -1) {
        printf("no duplicated number\n");
    } else {
        printf("%d\n", duplicate);
    }
    
    return 0;
}