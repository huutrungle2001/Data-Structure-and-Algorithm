#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    int countPositive = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        if (nums[i] > 0) {
            countPositive++;
        }
    }

    if (countPositive == 0) {
        printf("Day so khong co phan tu duong");
    } else {
        printf("%d\n", countPositive);
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            printf("%d ", nums[i]);
        }
    }
}