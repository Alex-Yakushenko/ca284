#include <stdio.h>
#include <stdlib.h>

float finder(float * arr, int *length);
void populate(float * arr, int * length, char * argv[]);

int main(int argc, char * argv[])
{
    int length = argc - 1;
    float * numbers = calloc(length, sizeof(float));
    populate(numbers, &length, argv);
    float secondLargest = finder(numbers, &length);
    printf("%.1f\n", secondLargest);
    free(numbers);
    numbers = NULL;
    return  0;
}

void populate(float * arr, int * length, char * argv[])
{
    for (int i = 0; i < *length; i++) {
        arr[i] = atof(argv[i + 1]);
    }
}
float finder(float * arr, int *length)
{
    float secondL = arr[0];
    float largest = arr[1];

    if (secondL >= largest) {
        float tmp;
        tmp = largest;
        largest = secondL;
        secondL = tmp;
    }

    for (int i = 2; i < *length; i++) {
        if (arr[i] > largest) {
            secondL = largest;
            largest = arr[i];
        } else if (arr[i] > secondL && arr[i] < largest) {
            secondL = arr[i];
        } else {
        }
    }
    return secondL;

}