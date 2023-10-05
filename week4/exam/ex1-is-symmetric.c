/*
Author: Alexander Yakushenko
Date: 05/10/2023
Description: This script will check if a word is symmetric by
splitting the word into two halves, and checking if the characters
on both ends match, while moving towards the middle of the string.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char string[]);

int main(int argc, char*argv[])
{
    char myString[50];
    strcpy(myString, argv[1]);
    // storing the string from the command line in a variable
    int palindrome = isPalindrome(myString);
    // calling the function to check if the word is symmetric or not
    if (palindrome == 0) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    // producing the output depending on the output of a function
    return 0;
}

// the following function checks if the word is symmetric
int isPalindrome(char string[])
{
    for (int i = 0; i < strlen(string) / 2; i ++) {
        if (string[i] != string[strlen(string) - i - 1]) {
            return 1;
        }
    }
    // the for loop splits the word checking if both halves are mirrored
    return 0;
}
