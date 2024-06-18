#include <stdio.h>

int euclidean_algorithm(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int extended_euclidean_algorithm(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extended_euclidean_algorithm(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int main() {
    int a = 56;
    int b = 98;
    int x, y;

    int gcd_euclidean = euclidean_algorithm(a, b);
    printf("GCD of %d and %d using Euclidean algorithm is: %d\n", a, b, gcd_euclidean);

    int gcd_extended = extended_euclidean_algorithm(a, b, &x, &y);
    printf("GCD of %d and %d using Extended Euclidean algorithm is: %d\n", a, b, gcd_extended);
    printf("Coefficients x and y are: %d, %d\n", x, y);

    return 0;
}

