#include <stdio.h>
#include <stdlib.h>


struct Country {
    char *name;
    char *capital;
    float population;
    int size;
};

void print_country(struct Country c);

int main(int argc, char*argv[])
{
    struct Country country1 = {argv[1], argv[2], atof(argv[3]), atoi(argv[4])};
    print_country(country1);

    return 0;
}

void print_country(struct Country c)
{
    printf("%s\n", c.name);
    printf("%s\n", c.capital);
    printf("%.2f million people\n", c.population);
    printf("%d km2\n", c.size);
}