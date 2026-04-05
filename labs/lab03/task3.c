#include <stdio.h>
#include <stdlib.h>

int find_max(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int find_min(int *arr, int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

int find_sum(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

void main() {
    int n;
    int *arr;
    
    printf("Enter array size: ");
    scanf("%d", &n);
    
    arr = (int*)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("\nMax: %d\n", find_max(arr, n));
    printf("Min: %d\n", find_min(arr, n));
    printf("Sum: %d\n", find_sum(arr, n));
    
    free(arr);
}
