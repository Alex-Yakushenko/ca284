#include <stdio.h>
#include <string.h>


void reverseString(char str[]) {
    int length = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

}

int main(int argc, char*argv[]) {
    char myString[50];
    strcpy(myString, argv[1]);
    reverseString(myString);
    printf("%s\n", myString);

    return 0;
}
