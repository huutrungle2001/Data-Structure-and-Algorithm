#include <stdio.h>

int main() {
    freopen("bai1.inp", "r", stdin);
    freopen("bai1.out", "w", stdout);

    int n;
    scanf("%d", &n);
    int temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        printf("%d ", temp);
    }
}