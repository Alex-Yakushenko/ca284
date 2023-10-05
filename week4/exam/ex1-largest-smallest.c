/*
Author: Alexander Yakushenko
Date: 05/10/2023
Description: This code gets the operation type and floating point numbers
from the command line arguments and stores them. It then uses fucntios
to determine the type of the operation and the output of it.
Once it gets tht type of the operation it stores the first number in the array
and checks all of the following numbers. If one of the following numbers
is smaller/larger than the current one, it swaps the current one with
smaller/larger number.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float maxMin(float arr[], int length, char operation[]);
void initArray(float arr[], int length, char**arguments);

int main(int argc, char*argv[])
{
    char operation[20];
    strcpy(operation, argv[1]);
    int length = argc - 2;
    float numbers[length];
    // Store the operation type and declare the array

    initArray(numbers, length, argv);
    // puts the numbers from the command line into the array
    float output = maxMin(numbers, length, operation);
    printf("%.2f\n", output);
    // calls the function and produces output
    return 0;
}
// the following function modifies an empty array and adds the
// floating point numbers from the command line
void initArray(float arr[], int length, char**arguments)
{
    for (int i = 0; i < length; i++) {
        arr[i] = atof(arguments[i + 2]);
    }
}

// this function checks the operation type and finds smallest/largest number
float maxMin(float arr[], int length, char operation[]) {
    float first = arr[0];
    // stores the first number to compare to the rest
    if (strcmp(operation, "smallest") == 0) {
        // for loop to compare first number to the rest of the numbers
        // replacing first with any smaller numbers it finds
        for (int i = 1; i < length; i++) {
            if (first > arr[i]) {
                first = arr[i];
            }
        }
    } else if (strcmp(operation, "largest") == 0) {
        // for loop to compare first number to the rest of the numbers
        // replacing first with any larger numbers ir finds
        for (int i = 1; i < length; i++) {
            if (first < arr[i]) {
                first = arr[i];
            }
        }
    }
    return first;
}
