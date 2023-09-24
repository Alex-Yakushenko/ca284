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
    int odd_count = 0;
    for (i = 0; i < length; i++)
    {
        if (numbers[i] % 2 == 1) {
            odd_count += 1;
        }
    }
    printf("%d\n", odd_count);
    return 0;
}