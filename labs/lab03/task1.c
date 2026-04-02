#include <stdio.h>
#include <stdlib.h>

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
    
    printf("\nArray: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
}
