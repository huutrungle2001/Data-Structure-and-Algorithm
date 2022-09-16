#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        printf("%d ", temp);
    }
}