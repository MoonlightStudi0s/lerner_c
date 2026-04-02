#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
};

void main() {
    struct Person p;
    FILE *f;
    int choice;

    while (1) {
        printf("\n1 - Добавить человека\n");
        printf("2 - Показать всех\n");
        printf("3 - Выйти\n");
        printf("Выбери: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("Имя: ");
            fgets(p.name, 50, stdin);
            p.name[strcspn(p.name, "\n")] = 0;
            printf("Возраст: ");
            scanf("%d", &p.age);
            getchar();

            f = fopen("database.bin", "ab");
            if (f == NULL) {
                printf("Ошибка открытия файла!\n");
                continue;
            }
            fwrite(&p, sizeof(struct Person), 1, f);
            fclose(f);
            printf("Сохранено!\n");
        }
        else if (choice == 2) {
            f = fopen("database.bin", "rb");
            if (f == NULL) {
                printf("Файл пустой или не существует\n");
                continue;
            }
            printf("\n--- Список людей ---\n");
            while (fread(&p, sizeof(struct Person), 1, f) == 1) {
                printf("Имя: %s, Возраст: %d\n", p.name, p.age);
            }
            fclose(f);
        }
        else if (choice == 3) {
            printf("Пока-пока!\n");
            break;
        }
        else {
            printf("Не понял, выбери 1-3\n");
        }
    }
}
