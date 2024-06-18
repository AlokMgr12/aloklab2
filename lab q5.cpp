#include <stdio.h>

int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1) {
        printf("Modular inverse doesn't exist for %d under modulo %d\n", a, m);
        return -1;
    }
    return (x % m + m) % m;
}

int chineseRemainderTheorem(int *a, int *n, int k) {
    int N = 1;
    for (int i = 0; i < k; i++) {
        N *= n[i];
    }

    int x = 0;

    for (int i = 0; i < k; i++) {
        int Ni = N / n[i];
        int Mi = modInverse(Ni, n[i]);
        x += a[i] * Ni * Mi;
    }

    return x % N;
}

int main() {
    int a[] = {2, 3, 2};
    int n[] = {3, 5, 7};
    int k = sizeof(a) / sizeof(a[0]);

    int result = chineseRemainderTheorem(a, n, k);
    printf("The solution is %d\n", result);

    return 0;
}

