#include <stdio.h>
#define oo 1000000007

int main() {
    int n;
    scanf("%d", &n);
    int maxValue = -oo;
    
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        maxValue = temp > maxValue ? temp : maxValue;
    }

    printf("%d", maxValue);
}