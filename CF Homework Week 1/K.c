#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    double sum = 0;
    double countNonNegative = 0;

    for (int i = 0; i < n; i++) {
        double num;
        scanf("%lf", &num);
        if (num >= 0) {
            sum += num;
            countNonNegative++;
        }
    }

    printf("%.3lf\n", sum / countNonNegative);
}