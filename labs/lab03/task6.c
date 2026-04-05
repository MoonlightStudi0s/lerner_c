#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, index, value;
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
    
    printf("\nEnter index to insert (0-%d): ", n);
    scanf("%d", &index);
    printf("Enter value to insert: ");
    scanf("%d", &value);
    
    if (index < 0 || index > n) {
        printf("Invalid index!\n");
        free(arr);
        return;
    }
    
    n++;
    arr = (int*)realloc(arr, n * sizeof(int));
    
    for (int i = n - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[index] = value;
    
    printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
}
