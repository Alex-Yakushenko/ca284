#include <stdio.h>
#include <stdlib.h>

void populate(int * vector, char * argv[], int * index, int * length);
void dot_prod(int * a, int * b, int * length, int * total);
int main(int argc, char * argv[])
{
    int length = atoi(argv[1]);
    int * vec1 = calloc(length, sizeof(int));
    int * vec2 = calloc(length, sizeof(int));
    int index = 2;
    populate(vec1, argv, &index, &length);
    populate(vec2, argv, &index, &length);
    int total = 0;
    dot_prod(vec1, vec2, &length, &total);
    printf("%d\n", total);
    free(vec1);
    free(vec2);
    vec1 = NULL;
    vec2 = NULL;

    return 0;
}

void populate(int * vector, char * argv[], int * index, int * length)
{
    for (int i = 0; i < *length; i++) {
        vector[i] = atoi(argv[*index + i]);
    }
    *index += *length;
}

void dot_prod(int * a, int * b, int * length, int * total)
{
    for (int i = 0; i < *length; i++) {
        *total += *(a + i) * *(b + i);
    }
}