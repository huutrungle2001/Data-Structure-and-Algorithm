#include <stdio.h>

void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    mergeSort(nums, 0, n - 1);

    int countDistinct = 1;
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] != nums[i + 1]) {
            countDistinct++;
        }
    }

    printf("%d\n", countDistinct);

    int occurences = 1;

    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            occurences++;
        } else {
            printf("%d %d\n", nums[i], occurences);
            occurences = 1;
        }
    }

    printf("%d %d", nums[n - 1], occurences);
}