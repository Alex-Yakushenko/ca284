#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sum(int a, int b);
float diff(int a, int b);
float prod(int a, int b);
float dev(int a, int b);
float power(int a, int b);
float nat_log(int a, int b);

int main(int argc, char*argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    float (*functions[])(int, int) = {sum, diff, prod, dev, power, nat_log};
    for (int i = 0; i < sizeof(functions) / sizeof(functions[0]); i++) {
        printf("%.2f\n", functions[i](a, b));
    }
    return 0;
}

float sum(int a, int b){
    return a + b;
}
float diff(int a, int b) {
    return a - b;
}
float prod(int a, int b) {
    return a * b;
}
float dev(int a, int b) {
    return a / b;
}
float power(int a, int b) {
    return pow(a, b);
}
float nat_log(int a, int b) {
    return log(a) + log(b);
}
