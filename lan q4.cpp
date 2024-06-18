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

void linearCongruence(int a, int b, int n) {
    int x, y;
    int gcd = gcdExtended(a, n, &x, &y);

    if (b % gcd != 0) {
        printf("No solution exists\n");
        return;
    }

    int x0 = (x * (b / gcd)) % n;
    if (x0 < 0) {
        x0 += n;
    }

    for (int i = 0; i < gcd; i++) {
        int solution = (x0 + i * (n / gcd)) % n;
        printf("Solution %d: x = %d\n", i + 1, solution);
    }
}

int main() {
    int a, b, n;

    printf("Enter values for a, b, and n (for equation ax = b (mod n)):\n");
    scanf("%d %d %d", &a, &b, &n);

    linearCongruence(a, b, n);

    return 0;
}

