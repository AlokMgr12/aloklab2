#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void join(int A[ROWS][COLS], int B[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = A[i][j] | B[i][j];
        }
    }
}

void meet(int A[ROWS][COLS], int B[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = A[i][j] & B[i][j];
        }
    }
}

void booleanProduct(int A[ROWS][COLS], int B[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] |= A[i][k] & B[k][j];
            }
        }
    }
}

int main() {
    int A[ROWS][COLS] = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 1, 0}
    };
    int B[ROWS][COLS] = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 0, 1}
    };
    
    int result[ROWS][COLS];

    printf("Matrix A:\n");
    printMatrix(A);

    printf("\nMatrix B:\n");
    printMatrix(B);

    join(A, B, result);
    printf("\nJoin (A | B):\n");
    printMatrix(result);

    meet(A, B, result);
    printf("\nMeet (A & B):\n");
    printMatrix(result);

    booleanProduct(A, B, result);
    printf("\nBoolean Product (A * B):\n");
    printMatrix(result);

    return 0;
}

