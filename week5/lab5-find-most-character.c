#include <stdio.h>
#include <string.h>

int count_character(char chr, char * pString);
void unique_letters(char * pLetters, char * pString);

int main(int argc, char*argv[])
{
    char * pString = argv[1];
    char letters[strlen(pString) + 1];
    char * pLetters = letters;
    //printf("%s", pLetters);
    unique_letters(pLetters, pString);
    //printf("%s", pLetters);
    
    char letter = *pLetters;
    int counter = count_character(letter, pString);
    pLetters++;
    while (*pLetters != '\0') {
        if (counter < count_character(*pLetters, pString)) {
            letter = *pLetters;
            counter = count_character(*pLetters, pString);
        }
        pLetters++;
    }

    printf("%c\n", letter);

    return 0;
}

int count_character(char chr, char * pString)
{
    int counter = 0;
    while (pString = strchr(pString, chr)) {
        counter++;
        pString++;
    }
    return counter;
}

void unique_letters(char * pLetters, char * pString)
{
    int i = 0;
    while (*pString != '\0'){
        char letter = *pString;
        if (strchr(pLetters, letter) == NULL && letter != ' ') {
            pLetters[i] = letter;
            i++;
        }
        pString++;
    }
    pLetters[i] = '\0';
}