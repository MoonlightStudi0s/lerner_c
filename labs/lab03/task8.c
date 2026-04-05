#include <stdio.h>
#include <stdlib.h>

void print_menu() {
    printf("\n=== MENU ===\n");
    printf("1. Add element\n");
    printf("2. Delete element\n");
    printf("3. Print list\n");
    printf("4. Change size\n");
    printf("5. Exit\n");
    printf("Choice: ");
}

void add_element(int **arr, int *size) {
    int value, pos;
    printf("Enter value: ");
    scanf("%d", &value);
    printf("Enter position (0-%d): ", *size);
    scanf("%d", &pos);
    
    if (pos < 0 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }
    
    (*size)++;
    *arr = (int*)realloc(*arr, *size * sizeof(int));
    
    for (int i = *size - 1; i > pos; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    
    (*arr)[pos] = value;
    printf("Element added!\n");
}

void delete_element(int **arr, int *size) {
    int pos;
    printf("Enter position to delete (0-%d): ", *size - 1);
    scanf("%d", &pos);
    
    if (pos < 0 || pos >= *size) {
        printf("Invalid position!\n");
        return;
    }
    
    for (int i = pos; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    
    (*size)--;
    *arr = (int*)realloc(*arr, *size * sizeof(int));
    printf("Element deleted!\n");
}

void print_list(int *arr, int size) {
    if (size == 0) {
        printf("List is empty!\n");
        return;
    }
    
    printf("List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void change_size(int **arr, int *size) {
    int new_size;
    printf("Enter new size: ");
    scanf("%d", &new_size);
    
    if (new_size < 0) {
        printf("Invalid size!\n");
        return;
    }
    
    if (new_size == 0) {
        free(*arr);
        *arr = NULL;
    } else {
        *arr = (int*)realloc(*arr, new_size * sizeof(int));
        
        if (new_size > *size) {
            printf("Enter %d new elements:\n", new_size - *size);
            for (int i = *size; i < new_size; i++) {
                printf("arr[%d] = ", i);
                scanf("%d", &(*arr)[i]);
            }
        }
    }
    
    *size = new_size;
    printf("Size changed to %d\n", *size);
}

void main() {
    int *arr = NULL;
    int size = 0;
    int choice;
    
    // Массив указателей на функции (для демонстрации продвинутого подхода)
    void (*actions[5])(int**, int*) = {add_element, delete_element, NULL, change_size, NULL};
    
    while (1) {
        print_menu();
        scanf("%d", &choice);
        
        if (choice == 5) {
            printf("Goodbye!\n");
            break;
        }
        
        switch (choice) {
            case 1: add_element(&arr, &size); break;
            case 2: delete_element(&arr, &size); break;
            case 3: print_list(arr, size); break;
            case 4: change_size(&arr, &size); break;
            default: printf("Invalid choice!\n");
        }
    }
    
    free(arr);
}
