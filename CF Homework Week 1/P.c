#include <stdio.h>

inline static void inputVector(int *vector, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
    }
}

inline static int getScalar(int *vector1, int *vector2, int n) {
    int scalar = 0;
    for (int i = 0; i < n; i++) {
        scalar += vector1[i] * vector2[i];
    }
    return scalar;
}

int main() {
    int n;
    scanf("%d", &n);
    int vector1[n];
    inputVector(vector1, n);
    int vector2[n];
    inputVector(vector2, n);

    printf("%d", getScalar(vector1, vector2, n));
}