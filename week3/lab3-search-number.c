#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {
    int length = argc - 2;
    int i;
    int numbers[length];
    for (i = 0; i < length; i++) {
        numbers[i] = atoi(argv[i + 2]);
    }
    int value = atoi(argv[1]);
    int position = -1;
    for (i = 0; i < length; i++) {
        if (numbers[i] == value) {
            position = i;
        }
    }
    if (position >= 0) {
        printf("Found %d at %d\n", value, position);
    } else {
        printf("%d not found\n", value);
    }

    return 0;
}