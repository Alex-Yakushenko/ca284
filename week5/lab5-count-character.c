#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_character(char chr, char * pString);

int main(int argc, char*argv[])
{
    char * pMyString = argv[2];
    char chr = argv[1][0];
    int number = find_character(chr, pMyString);
    printf("%d\n", number);

    return 0;
}
int find_character(char chr, char * pString)
{
    int counter = 0;
    while (pString = strchr(pString, chr)) {
        counter++;
        pString++;
    }
    return counter;
}
