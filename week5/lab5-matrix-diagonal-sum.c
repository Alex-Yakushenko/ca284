#include <stdio.h>
#include <stdlib.h>

void populate(char **arguments, int length, int matrix[length][length]);
int total(int length, int matrix[length][length]);

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int matrix[n][n];
    populate(argv, n, matrix);
    int diagonal_total = total(n, matrix);
    printf("%d\n", diagonal_total);

    return 0;
}

void populate(char **arguments, int length, int matrix[length][length])
{
    int argI = 2;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            matrix[i][j] = atoi(arguments[argI]);
            argI++;
        }
    }
}

int total(int length, int matrix[length][length])
{
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += *(*(matrix + i) + i); // summing up the diagonal
    }
    return sum;
}
