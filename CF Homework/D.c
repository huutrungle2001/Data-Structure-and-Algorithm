#include <math.h>
#include <stdio.h>

int isSquare(int n) {
    return (int)sqrt(n) == sqrt(n);
}

int main() {
    int n;
    scanf("%d", &n);
    if (isSquare(n)) {
        printf("co\n");
    } else {
        printf("khong\n");
    }
}