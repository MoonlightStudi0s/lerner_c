#include <stdio.h>
#include <stdlib.h>

void main() {
    int n;
    int *arr;
    
    printf("Enter array size: ");
    scanf("%d", &n);
    
    arr = (int*)calloc(n, sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Array after calloc (all zeros):\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    free(arr);
}
