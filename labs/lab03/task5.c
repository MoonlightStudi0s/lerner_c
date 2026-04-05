#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, index;
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
    
    printf("\nEnter index to delete (0-%d): ", n-1);
    scanf("%d", &index);
    
    if (index < 0 || index >= n) {
        printf("Invalid index!\n");
        free(arr);
        return;
    }
    
    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    n--;
    arr = (int*)realloc(arr, n * sizeof(int));
    
    printf("Array after deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
}
