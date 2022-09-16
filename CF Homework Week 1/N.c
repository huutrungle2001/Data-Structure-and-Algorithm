#include <stdio.h>

int main() {
    int n, x;
    scanf("%d%d", &n, &x);

    int countLarger = 0;

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        if (temp > x) {
            countLarger++;
        }
    }

    printf("%d", countLarger);
}