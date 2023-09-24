#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc < 2){
        printf("No input given!\n");
        return 1;
    }else if (argc < 3) {
        printf("Two arguments needed!\n");
        return 1;
    }
    
    int radius = atoi(argv[1]);
    int height = atoi(argv[2]);

    if (radius < 0 || height < 0) {
        printf("The radius or height cannot be negative!\n");
        return 1;
    }
    double surface_area = 2 * 3.1415 * radius * (radius + height);
    printf("%.2f\n", surface_area);

    return 0;
}