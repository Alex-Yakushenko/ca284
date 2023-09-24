#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    int width = atoi(argv[1]);

    for (int i = 1; i <= width; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            if (i == 1 || i == width || j == 1 || j == width) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}