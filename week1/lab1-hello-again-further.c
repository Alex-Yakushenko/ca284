#include <stdio.h>
#include <stdlib.h> /* a header file with a function we might need */

int main()
{
   char user_name[100];
   printf("Enter your name: ");
   scanf("%s", user_name);
   printf("Hello\n%s\n", user_name);
   return(0);
}