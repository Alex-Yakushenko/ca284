#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *operation = argv[1];
    float first = atof(argv[2]);
    float second = atof(argv[3]);
    
    if (strcmp(operation, "divide") == 0 && second == 0) {
        printf("invalid\n");
        return 1;
    }
    
    if (strcmp(operation, "multiply") == 0) {
        double result = first * second;
        printf("%f\n", result);
    } else {
        double result = first / second;
        printf("%f\n", result);
    }
    

    return 0;
}