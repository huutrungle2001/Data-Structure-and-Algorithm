#include <stdio.h>
#include <stdlib.h>

inline static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int k, l;
    scanf("%d %d", &k, &l);
    k--, l--;

    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    inputMatrix(matrix, m, n);

    for (int i = 0; i < m; i++) {
        swap(&matrix[i][k], &matrix[i][l]);
    }

    displayMatrix(matrix, m, n);
}