#include <stdio.h>
#define oo 1000000007

int main() {
    int n;
    scanf("%d", &n);
    int minValue = oo;
    
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        minValue = temp < minValue ? temp : minValue;
    }

    printf("%d", minValue);
}