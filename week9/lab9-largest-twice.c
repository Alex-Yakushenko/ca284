#include <stdio.h>
#include <stdlib.h>

void populate(int * numbers, int * length, char * argv[]);
void maxMin(int * numbers, int * max, int * min, int * length);

int main(int argc, char*argv[])
{
    int length = argc - 1;
    int * numbers = calloc(length, sizeof(int));
    populate(numbers, &length, argv);
    int max;
    int min;
    maxMin(numbers, &max, &min, &length);
    if (max / 2 >= min) {
        printf("%d\n", max);
    } else {
        printf("0\n");
    }
    return 0;
}

void populate(int * numbers, int * length, char * argv[])
{
    for (int i = 0; i < *length; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }
}

void maxMin(int * numbers, int * max, int * min, int * length)
{
    *max = numbers[0];
    *min = numbers[1];
    if (*min > *max) {
        int tmp = *min;
        *min = *max;
        *max = tmp;
    }
    for (int i = 2; i < *length; i++) {
        if (numbers[i] < *min) {
            *min = numbers[i];
        } else if (numbers[i] > *max) {
            *max = numbers[i];
        }
    }

}
