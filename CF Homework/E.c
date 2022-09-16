#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a < b) {
        printf("nho hon\n");
    } else if (a > b) {
        printf("lon hon\n");
    } else {
        printf("bang nhau\n");
    }
}