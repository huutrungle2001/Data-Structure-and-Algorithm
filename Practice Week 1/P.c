#include <stdio.h>

int main() {
    double M;
    scanf("%lf", &M);
    if (M < 1) {
        printf("NULL");
        return 0;
    }

    double S = 1;
    double i = 1;
    while ((S + 1.0 / (i + 1.0)) < M) {
        i += 1;
        S += 1.0 / i;
    }
    printf("%d", (int)i);
}