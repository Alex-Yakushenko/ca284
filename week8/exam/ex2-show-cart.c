#include <stdio.h>
#include <stdlib.h>

typedef struct Cart Cart;

struct Cart {
    char *name;
    int amount;
    float price;
    char *promo;
};

Cart addItem(char **argv, int * index);
void printItem(Cart * item);

int main(int argc, char*argv[])
{
    int index = 1;
    int items_num = (argc - 1) / 4;
    Cart cart[100];
    for (int i = 0; i < items_num; i++) {
        cart[i] = addItem(argv, &index);
    }
    for (int i = 0; i < items_num; i++) {
        printItem(&cart[i]);
    }

    return 0;
}

Cart addItem(char **argv, int * index)
{
    Cart item;
    item.name = argv[*index];
    item.amount = atoi(argv[*index + 1]);
    item.price = atof(argv[*index + 2]);
    if (atoi(argv[*index + 3]) == 0) {
        item.promo = "No Sale";
    } else {
        item.promo = "On Sale";
    }
    *index += 4;

    return item;
}
void printItem(Cart * item)
{
    printf("%s,%d,%.2f,%s\n",item->name, item->amount, item->price, item->promo);
}











