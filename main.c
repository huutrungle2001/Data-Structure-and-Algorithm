#include <stdio.h>

int main() {
    int dryLeftDay[5] = {[0 ... 2] = -1};
    for (int i = 0; i < 5; i++) {
        printf("%d ", dryLeftDay[i]);
    }
}