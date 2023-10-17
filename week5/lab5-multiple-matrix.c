#include <stdio.h>
#include <stdlib.h>

void populate(int n, int m, int matrix[n][m], char *argv[], int index);
void multiply_matrices(int n1, int m1, int A[n1][m1], int n2, int m2, int B[n2][m2], int C[n1][m2]);
void print_matrix(int n, int m, int matrix[n][m]);

int main(int argc, char * argv[])
{
    int n1 = atoi(argv[1]);
    int m1 = atoi(argv[2]);
    int n2 = atoi(argv[3 + m1 * n1]);
    int m2 = atoi(argv[4 + m1 * n1]);

    int A[n1][m1];
    int B[n2][m2];
    int C[n1][m2];

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            C[i][j] = 0;
        }
    }
    int argI = 3;
    populate(n1, m1, A, argv, argI);
    argI = 3 + m1 * n1 + 2;
    populate(n2, m2, B, argv, argI);
    /*
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            printf("%d ", A[i][j]);
        }
    }
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            printf("%d ", B[i][j]);
        }
    }
    */
    multiply_matrices(n1, m1, A, n2, m2, B, C);
    print_matrix(n1, m2, C);

    return 0;
}

void populate(int n, int m, int matrix[n][m], char *argv[], int index)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = atoi(argv[index]);
            index++;
        }
    }
}

void multiply_matrices(int n1, int m1, int A[n1][m1], int n2, int m2, int B[n2][m2], int C[n1][m2]) {
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            for (int k = 0; k < m1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void print_matrix(int n, int m, int matrix[n][m]) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            printf("%d", matrix[i][j]);
            if (j != m - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}