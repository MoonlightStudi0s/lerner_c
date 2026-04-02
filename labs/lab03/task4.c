#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, m;
    int *arr;
    
    printf("Enter initial size: ");
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
    
    printf("\nIncrease size to: ");
    scanf("%d", &m);
    
    arr = (int*)realloc(arr, m * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory reallocation failed!\n");
        return;
    }
    
    printf("Enter %d new elements:\n", m - n);
    for (int i = n; i < m; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("\nArray after increase: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n\nDecrease size to: ");
    scanf("%d", &n);
    
    arr = (int*)realloc(arr, n * sizeof(int));
    
    printf("Array after decrease: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
}
