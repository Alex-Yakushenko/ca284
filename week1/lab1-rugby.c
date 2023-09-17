#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int tries = atoi(argv[1]);
    int conversions = atoi(argv[2]);
    int penalties = atoi(argv[3]);
    int drop_goals = atoi(argv[4]);

    int total =(tries * 5) + (conversions * 2) + (penalties * 3) + (drop_goals * 3);
    printf("%d\n", total);

    return 0;
}