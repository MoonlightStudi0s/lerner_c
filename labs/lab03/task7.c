#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
};

void main() {
    int n;
    struct Student *students;
    int oldest_index = 0;
    
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    students = (struct Student*)malloc(n * sizeof(struct Student));
    
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        
        if (students[i].age > students[oldest_index].age) {
            oldest_index = i;
        }
    }
    
    printf("\n--- All students ---\n");
    for (int i = 0; i < n; i++) {
        printf("%s, %d years old\n", students[i].name, students[i].age);
    }
    
    printf("\nOldest student: %s (%d years old)\n", 
           students[oldest_index].name, students[oldest_index].age);
    
    free(students);
}
