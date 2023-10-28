#include <stdio.h>
#include <stdlib.h>

typedef struct Country Country;

struct Country {
    char *name;
    char *capital;
    float population;
    int size;
};

Country addCountry(char **argv, int * index);
void printCountry(Country * c);

int main(int argc, char *argv[])
{
    int index = 1;
    int country_num = (argc - 1) / 4;
    Country countries[country_num];
    for (int i = 0; i < country_num; i++) {
        countries[i] = addCountry(argv, &index);
    }
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    for (int i = 0; i < country_num; i++) {
        if (countries[i].size <= 100000) {
            printCountry(&countries[i]);
        }
    }
    return 0;
}

Country addCountry(char **argv, int * index)
{
    Country c;
    c.name = argv[*index];
    c.capital = argv[*index + 1];
    c.population = atof(argv[*index + 2]);
    c.size = atoi(argv[*index + 3]);
    *index += 4;
    
    return c;
}
void printCountry(Country * c)
{
    printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", c->name, c->capital, c->size, c->population);
}