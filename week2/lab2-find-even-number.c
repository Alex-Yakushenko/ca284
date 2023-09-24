#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int numbers[10];
    int length = argc - 1;
    int i;
    for (i = 1; i <= length; i++)
    {
        numbers[i - 1] = atoi(argv[i]);
    }

    int even_count = 0;
    for (i = 0; i < length; i++)
    {
        if (numbers[i] % 2 == 0) {
            printf("%d - %d\n", i, numbers[i]);
            even_count += 1;
        }
    }
    if (even_count == 0)
    {
        printf("Not found!\n");
    }
    return 0;
}