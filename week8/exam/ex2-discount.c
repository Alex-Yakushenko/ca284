#include <stdio.h>
#include <stdlib.h>

typedef struct Cart Cart;

struct Cart {
    char *name;
    int amount;
    float price;
    int promo;
};

Cart addItem(char **argv, int * index);
void totalPrice(Cart * item, float *total);

int main(int argc, char*argv[])
{
    int index = 1;
    int items_num = (argc - 1) / 4;
    Cart cart[100];
    float total = 0;
    for (int i = 0; i < items_num; i++) {
        cart[i] = addItem(argv, &index);
    }
    for (int i = 0; i < items_num; i++) {
        totalPrice(&cart[i], &total);
    }
    printf("%.2f\n", total);

    return 0;
}

Cart addItem(char **argv, int * index)
{
    Cart item;
    item.name = argv[*index];
    item.amount = atoi(argv[*index + 1]);
    item.price = atof(argv[*index + 2]);
    item.promo = atoi(argv[*index + 3]);
    *index += 4;

    return item;
}
void totalPrice(Cart * item, float *total)
{
    if (item->promo == 0) {
        *total += item->amount * item->price;
    } else {
        int over = item->amount % 3;
        int fullPrice = (item->amount - over) - ((item->amount - over) / 3) + over;
        *total += fullPrice * item->price;
    }
}












