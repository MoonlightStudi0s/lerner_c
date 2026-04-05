#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INITIAL_CAPACITY 2

typedef struct {
    char name[100];
    int age;
    float height;
    int birthYear;
} Person;

Person *people = NULL;
int personCount = 0;
int personCapacity = 0;

int isValidName(const char *name) {
    int i;
    for (i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && name[i] != ' ' && name[i] != '\'') {
            return 0;
        }
    }
    return 1;
}

int calculateRealAge(int birthYear) {
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    int currentYear = now->tm_year + 1900;
    return currentYear - birthYear;
}

void addPerson() {
    if (personCount >= personCapacity) {
        personCapacity = (personCapacity == 0) ? INITIAL_CAPACITY : personCapacity * 2;
        people = (Person *)realloc(people, personCapacity * sizeof(Person));
        if (people == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }
    
    Person newP;
    char buffer[100];
    int valid;
    
    do {
        valid = 1;
        printf("Enter name: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        if (!isValidName(buffer)) {
            printf("Invalid name! Use only letters.\n");
            valid = 0;
        } else {
            strcpy(newP.name, buffer);
        }
    } while (!valid);
    
    do {
        printf("Enter age: ");
        fgets(buffer, sizeof(buffer), stdin);
        newP.age = atoi(buffer);
        if (newP.age <= 0) {
            printf("Age must be positive!\n");
        }
    } while (newP.age <= 0);
    
    do {
        printf("Enter height: ");
        fgets(buffer, sizeof(buffer), stdin);
        newP.height = (float)atof(buffer);
        if (newP.height <= 0) {
            printf("Height must be positive!\n");
        }
    } while (newP.height <= 0);
    
    do {
        printf("Enter birth year: ");
        fgets(buffer, sizeof(buffer), stdin);
        newP.birthYear = atoi(buffer);
        if (newP.birthYear < 1900 || newP.birthYear > 2025) {
            printf("Invalid birth year!\n");
        }
    } while (newP.birthYear < 1900 || newP.birthYear > 2025);
    
    people[personCount] = newP;
    personCount++;
    printf("Person added!\n");
}

void printAll() {
    int i;
    int realAge;
    if (personCount == 0) {
        printf("No records!\n");
        return;
    }
    for (i = 0; i < personCount; i++) {
        printf("%s | Age: %d | Height: %.2f | Birth year: %d", 
               people[i].name, people[i].age, people[i].height, people[i].birthYear);
        realAge = calculateRealAge(people[i].birthYear);
        if (abs(realAge - people[i].age) > 1) {
            printf(" (real age would be %d)", realAge);
        }
        printf("\n");
    }
}

int compareByName(const void *a, const void *b) {
    return strcmp(((Person *)a)->name, ((Person *)b)->name);
}

int compareByAge(const void *a, const void *b) {
    return ((Person *)a)->age - ((Person *)b)->age;
}

void sortByName() {
    if (personCount == 0) {
        printf("No records to sort!\n");
        return;
    }
    qsort(people, personCount, sizeof(Person), compareByName);
    printf("Sorted by name!\n");
}

void sortByAge() {
    if (personCount == 0) {
        printf("No records to sort!\n");
        return;
    }
    qsort(people, personCount, sizeof(Person), compareByAge);
    printf("Sorted by age!\n");
}

void statistics() {
    int i;
    float totalAge = 0;
    float maxHeight = 0;
    if (personCount == 0) {
        printf("No records!\n");
        return;
    }
    for (i = 0; i < personCount; i++) {
        totalAge += people[i].age;
        if (people[i].height > maxHeight) {
            maxHeight = people[i].height;
        }
    }
    printf("Average age: %.2f\n", totalAge / personCount);
    printf("Max height: %.2f\n", maxHeight);
}

void searchByName() {
    int i;
    int found = 0;
    char searchName[100];
    if (personCount == 0) {
        printf("No records!\n");
        return;
    }
    printf("Enter name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0;
    
    for (i = 0; i < personCount; i++) {
        if (strstr(people[i].name, searchName) != NULL) {
            printf("Found: %s | Age: %d | Height: %.2f | Birth year: %d\n",
                   people[i].name, people[i].age, people[i].height, people[i].birthYear);
            found = 1;
        }
    }
    if (!found) {
        printf("Not found!\n");
    }
}

void searchByAgeRange() {
    int i;
    int found = 0;
    int minAge, maxAge;
    char buffer[100];
    if (personCount == 0) {
        printf("No records!\n");
        return;
    }
    printf("Enter min age: ");
    fgets(buffer, sizeof(buffer), stdin);
    minAge = atoi(buffer);
    printf("Enter max age: ");
    fgets(buffer, sizeof(buffer), stdin);
    maxAge = atoi(buffer);
    
    for (i = 0; i < personCount; i++) {
        if (people[i].age >= minAge && people[i].age <= maxAge) {
            printf("%s | Age: %d | Height: %.2f | Birth year: %d\n",
                   people[i].name, people[i].age, people[i].height, people[i].birthYear);
            found = 1;
        }
    }
    if (!found) {
        printf("No records in that age range!\n");
    }
}

void saveToBinary() {
    FILE *f = fopen("people.bin", "wb");
    if (f == NULL) {
        printf("Cannot open file for writing!\n");
        return;
    }
    fwrite(&personCount, sizeof(int), 1, f);
    fwrite(people, sizeof(Person), personCount, f);
    fclose(f);
    printf("Saved %d records to people.bin\n", personCount);
}

void loadFromBinary() {
    FILE *f = fopen("people.bin", "rb");
    int newCount;
    Person *newPeople;
    if (f == NULL) {
        printf("File not found!\n");
        return;
    }
    fread(&newCount, sizeof(int), 1, f);
    
    newPeople = (Person *)malloc(newCount * sizeof(Person));
    if (newPeople == NULL) {
        printf("Memory allocation failed!\n");
        fclose(f);
        return;
    }
    fread(newPeople, sizeof(Person), newCount, f);
    fclose(f);
    
    if (people != NULL) {
        free(people);
    }
    people = newPeople;
    personCount = newCount;
    personCapacity = newCount;
    
    printf("Loaded %d records from people.bin\n", personCount);
}

void saveToText() {
    FILE *f = fopen("people.txt", "w");
    int i;
    if (f == NULL) {
        printf("Cannot open file for writing!\n");
        return;
    }
    fprintf(f, "%d\n", personCount);
    for (i = 0; i < personCount; i++) {
        fprintf(f, "%s\n%d\n%.2f\n%d\n", 
                people[i].name, people[i].age, people[i].height, people[i].birthYear);
    }
    fclose(f);
    printf("Saved %d records to people.txt\n", personCount);
}

void loadFromText() {
    FILE *f = fopen("people.txt", "r");
    int newCount;
    int i;
    Person *newPeople;
    if (f == NULL) {
        printf("File not found!\n");
        return;
    }
    fscanf(f, "%d\n", &newCount);
    
    newPeople = (Person *)malloc(newCount * sizeof(Person));
    if (newPeople == NULL) {
        printf("Memory allocation failed!\n");
        fclose(f);
        return;
    }
    for (i = 0; i < newCount; i++) {
        fscanf(f, "%99[^\n]\n", newPeople[i].name);
        fscanf(f, "%d\n", &newPeople[i].age);
        fscanf(f, "%f\n", &newPeople[i].height);
        fscanf(f, "%d\n", &newPeople[i].birthYear);
    }
    fclose(f);
    
    if (people != NULL) {
        free(people);
    }
    people = newPeople;
    personCount = newCount;
    personCapacity = newCount;
    
    printf("Loaded %d records from people.txt\n", personCount);
}

void saveMenu() {
    char choice[10];
    printf("Save to (1) binary or (2) text? ");
    fgets(choice, sizeof(choice), stdin);
    if (choice[0] == '1') {
        saveToBinary();
    } else if (choice[0] == '2') {
        saveToText();
    } else {
        printf("Invalid choice!\n");
    }
}

void loadMenu() {
    char choice[10];
    printf("Load from (1) binary or (2) text? ");
    fgets(choice, sizeof(choice), stdin);
    if (choice[0] == '1') {
        loadFromBinary();
    } else if (choice[0] == '2') {
        loadFromText();
    } else {
        printf("Invalid choice!\n");
    }
}

void exitProgram() {
    printf("Goodbye!\n");
    if (people != NULL) {
        free(people);
    }
}

void (*menuFunctions[])(void) = {
    addPerson,
    printAll,
    sortByName,
    sortByAge,
    statistics,
    searchByName,
    searchByAgeRange,
    saveMenu,
    loadMenu,
    exitProgram
};

const char *menuItems[] = {
    "Add person",
    "Print all",
    "Sort by name",
    "Sort by age",
    "Statistics",
    "Search by name",
    "Search by age range",
    "Save",
    "Load",
    "Exit"
};

#define MENU_SIZE 10

void main() {
    int choice;
    char buffer[10];
    
    people = (Person *)malloc(INITIAL_CAPACITY * sizeof(Person));
    if (people == NULL) {
        printf("Initial memory allocation failed!\n");
        return;
    }
    personCapacity = INITIAL_CAPACITY;
    personCount = 0;
    
    while (1) {
        printf("\n=== MENU ===\n");
        for (choice = 0; choice < MENU_SIZE; choice++) {
            printf("%d. %s\n", choice + 1, menuItems[choice]);
        }
        printf("Choice: ");
        fgets(buffer, sizeof(buffer), stdin);
        choice = atoi(buffer);
        
        if (choice >= 1 && choice <= MENU_SIZE) {
            if (choice == MENU_SIZE) {
                menuFunctions[choice - 1]();
                break;
            }
            menuFunctions[choice - 1]();
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
}