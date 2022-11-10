#include <stdio.h>

long long fib[1000000] = {0};

long long getFib(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    if (fib[n] != 0) {
        return fib[n];
    }

    return fib[n] = getFib(n - 1) + getFib(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", getFib(n));
}