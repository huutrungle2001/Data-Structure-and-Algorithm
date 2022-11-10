#include <stdio.h>

int getF(int n) {
    return n * n - 100 * n + 1;
}

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int minF = getF(50);
    if(n2 < minF){
        printf("0");
        return 0;
    }
}