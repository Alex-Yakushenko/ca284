#include <stdio.h>
#include <string.h>

int subCheck(char * str, char * substr, int * start, int * end);

int main(int argc, char*argv[])
{
    char *input_string = argv[1];
    char *search_string = argv[2];
    int start;
    int end;
    if (subCheck(input_string, search_string, &start, &end)) {
        printf("%d %d\n", start, end);
    }


    return 0;
}
int subCheck(char * str, char * substr, int * start, int * end)
{
     int str_len = strlen(str);
     int sub_len = strlen(substr);
     
     for (int i = 0; i <= str_len - sub_len; i++) {
        int j;
        for (j = 0; j < sub_len; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        if (j == sub_len) {
            *start = i;
            *end = i + j - 1;
            return 1;
        }
     }
     return 0;
}