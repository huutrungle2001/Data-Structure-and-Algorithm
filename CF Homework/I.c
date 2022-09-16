#include <stdio.h>

int main() {
    double n;
    scanf("%lf", &n);

    double sum = 0;

    for (int i = 0; i < n; i++) {
        double num;
        scanf("%lf", &num);
        sum += num;
    }

    printf("%.3lf", sum / n);
}