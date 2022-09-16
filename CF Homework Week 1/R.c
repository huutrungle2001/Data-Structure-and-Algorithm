#include <stdio.h>
#include <stdlib.h>

inline static void inputMatrix(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

inline static void displayMatrix(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

inline static void multiplyMatrix(int **matrixA, int **matrixB, int **result, int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int m, n, p;
    scanf("%d %d %d", &m, &n, &p);

    int **matrixA = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrixA[i] = (int *)malloc(n * sizeof(int));
    }

    int **matrixB = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrixB[i] = (int *)malloc(p * sizeof(int));
    }

    int **result = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        result[i] = (int *)malloc(p * sizeof(int));
    }

    inputMatrix(matrixA, m, n);
    inputMatrix(matrixB, n, p);

    multiplyMatrix(matrixA, matrixB, result, m, n, p);

    displayMatrix(result, m, p);
}