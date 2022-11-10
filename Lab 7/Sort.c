#include <stdio.h>
#include <stdlib.h>

void input(int *numbers, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
}

void display(int *numbers, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int *numbers, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (numbers[j] < numbers[min]) {
                min = j;
            }
        }
        swap(&numbers[i], &numbers[min]);
    }
}

void InsertionSort(int *numbers, int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int temp = numbers[i];
        while (j >= 0 && numbers[j] > temp) {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = temp;
    }
}

void BubbleSort(int *numbers, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                swap(&numbers[j], &numbers[j + 1]);
            }
        }
    }
}

void QuickSort(int *numbers, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = numbers[left];
    int i = left;
    int j = right;
    while (i < j) {
        while (i < j && numbers[j] >= pivot) {
            j--;
        }
        while (i < j && numbers[i] <= pivot) {
            i++;
        }
        if (i < j) {
            swap(&numbers[i], &numbers[j]);
        }
    }
    swap(&numbers[left], &numbers[i]);
    QuickSort(numbers, left, i - 1);
    QuickSort(numbers, i + 1, right);
}

int main() {
    int n;
    scanf("%d", &n);
    int *numbers = (int *)malloc(n * sizeof(int));

    input(numbers, n);
    // SelectionSort(numbers, n);
    // InsertionSort(numbers, n);
    // BubbleSort(numbers, n);
    QuickSort(numbers, 0, n - 1);
    display(numbers, n);
    return 0;
}