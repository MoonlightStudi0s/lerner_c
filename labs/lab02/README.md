# Лабораторная работа №2: Структуры в языке C

## Описание работы
В данной лабораторной работе изучаются структуры в языке C: объявление, вложенные структуры, указатели на структуры, массивы структур, передача структур в функции, перечисления (enum) и объединения (union). Работа состоит из 7 заданий, каждое из которых демонстрирует определенный аспект работы со структурами.

---

## Используемые технологии и библиотеки

| Компонент | Описание |
|-----------|---------|
| **Язык** | C (стандарт C99/C11) |
| **Компилятор** | GCC (GNU Compiler Collection) |
| **Библиотеки** | `<stdio.h>` — ввод/вывод данных<br>`<string.h>` — работа со строками |

---

## Инструкция по запуску

### 1. Сохраните код
Каждое задание представляет собой отдельную программу. Сохраните код каждого задания в отдельный файл:
- `task1.c`
- `task2.c`
- `task3.c`
- `task4.c`
- `task5.c`
- `task6.c`
- `task7.c`

### 2. Компиляция
Используйте GCC для компиляции:
```bash
gcc task1.c -o task1
gcc task2.c -o task2
# и так далее для каждого задания
3. Запуск
bash
./task1   # Linux/Mac
task1.exe # Windows
4. Требования к системе
Операционная система: Windows, Linux, macOS

Установленный компилятор GCC

Терминал/командная строка

Задания и код
Задание 1. Базовая структура
Описание: Создание структуры Student с полями: имя, возраст, средний балл. Демонстрация объявления переменной, заполнения, вывода и ввода данных с клавиатуры.

Код:

c
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float average;
};

void main() {
    struct Student s1;
    struct Student s2;

    strcpy(s1.name, "Vasya");
    s1.age = 20;
    s1.average = 4.5;

    printf("Student 1: %s, %d, %.2f\n", s1.name, s1.age, s1.average);

    printf("Enter name: ");
    scanf("%s", s2.name);
    printf("Enter age: ");
    scanf("%d", &s2.age);
    printf("Enter average: ");
    scanf("%f", &s2.average);

    printf("Student 2: %s, %d, %.2f\n", s2.name, s2.age, s2.average);
}
Задание 2. Массив структур
Описание: Создание массива из 5 структур Student, заполнение данными, вывод всех студентов и поиск студента с максимальным средним баллом.

Код:

c
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float average;
};

void main() {
    struct Student group[5];
    int i, max_index = 0;

    strcpy(group[0].name, "Anna");
    group[0].age = 19;
    group[0].average = 4.8;

    strcpy(group[1].name, "Bob");
    group[1].age = 21;
    group[1].average = 3.9;

    strcpy(group[2].name, "Cid");
    group[2].age = 20;
    group[2].average = 4.2;

    strcpy(group[3].name, "Dan");
    group[3].age = 22;
    group[3].average = 5.0;

    strcpy(group[4].name, "Eva");
    group[4].age = 18;
    group[4].average = 4.0;

    for (i = 0; i < 5; i++) {
        printf("%s | %d | %.2f\n", group[i].name, group[i].age, group[i].average);
        if (group[i].average > group[max_index].average) max_index = i;
    }

    printf("Top student: %s with %.2f\n", group[max_index].name, group[max_index].average);
}
Задание 3. Вложенные структуры
Описание: Создание структуры Date (день, месяц, год) и структуры Person (имя, дата рождения). Вывод данных и фильтрация родившихся после 2000 года.

Код:

c
#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Person {
    char name[50];
    struct Date birth;
};

void main() {
    struct Person p1;
    struct Person p2;

    strcpy(p1.name, "John");
    p1.birth.day = 15;
    p1.birth.month = 5;
    p1.birth.year = 1995;

    strcpy(p2.name, "Jane");
    p2.birth.day = 22;
    p2.birth.month = 8;
    p2.birth.year = 2003;

    if (p1.birth.year > 2000) printf("%s born after 2000\n", p1.name);
    if (p2.birth.year > 2000) printf("%s born after 2000\n", p2.name);
}
Задание 4. Структуры и функции
Описание: Создание структуры Rectangle (ширина, высота). Написание функций для вычисления площади (передача по значению) и периметра (передача по указателю).

Код:

c
#include <stdio.h>

struct Rectangle {
    float width;
    float height;
};

float area_by_val(struct Rectangle r) {
    return r.width * r.height;
}

float perim_by_ptr(struct Rectangle *r) {
    return 2 * (r->width + r->height);
}

void main() {
    struct Rectangle rect;
    rect.width = 10.5;
    rect.height = 4.2;

    printf("Area: %.2f\n", area_by_val(rect));
    printf("Perimeter: %.2f\n", perim_by_ptr(&rect));
}
Задание 5. Перечисления (enum)
Описание: Создание перечисления Day с днями недели. Демонстрация использования switch и встраивания enum в структуру.

Код:

c
#include <stdio.h>

enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };

struct Event {
    char name[30];
    enum Day weekday;
};

void main() {
    enum Day today = WED;
    struct Event e = {"Meeting", FRI};

    switch (today) {
        case MON: printf("It's Monday\n"); break;
        case TUE: printf("It's Tuesday\n"); break;
        case WED: printf("It's Wednesday\n"); break;
        case THU: printf("It's Thursday\n"); break;
        case FRI: printf("It's Friday\n"); break;
        case SAT: printf("It's Saturday\n"); break;
        case SUN: printf("It's Sunday\n"); break;
    }

    printf("Event: %s on day %d\n", e.name, e.weekday);
}
Задание 6. Объединения (union)
Описание: Создание объединения Data с полями int, float, char. Демонстрация того, что хранится только одно значение. Создание структуры, содержащей union и поле-индикатор типа.

Код:

c
#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

struct Mixed {
    union Data value;
    int type; // 0=int, 1=float, 2=char
};

void main() {
    union Data u;
    u.i = 42;
    printf("As int: %d\n", u.i);
    printf("As float (garbage): %f\n", u.f);

    u.f = 3.14;
    printf("As float: %f\n", u.f);
    printf("As int (garbage): %d\n", u.i);

    struct Mixed m;
    m.value.i = 100;
    m.type = 0;
    if (m.type == 0) printf("Stored int: %d\n", m.value.i);
}
Задание 7. Комплексное задание
Описание: Создание структуры Student с полями: имя, возраст, курс (enum), средний балл. Реализация массива студентов и функций: добавление, вывод списка, поиск по имени, сортировка по среднему баллу. Использование указателей.

Код:

c
#include <stdio.h>
#include <string.h>

enum Course { FIRST = 1, SECOND, THIRD, FOURTH };

struct Student {
    char name[50];
    int age;
    enum Course course;
    float average;
};

struct Student group[100];
int count = 0;

void add(char *name, int age, enum Course course, float avg) {
    strcpy(group[count].name, name);
    group[count].age = age;
    group[count].course = course;
    group[count].average = avg;
    count++;
}

void print_all() {
    for (int i = 0; i < count; i++) {
        printf("%s | age %d | course %d | avg %.2f\n",
               group[i].name, group[i].age, group[i].course, group[i].average);
    }
}

void search_by_name(char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(group[i].name, name) == 0) {
            printf("Found: %s, age %d\n", group[i].name, group[i].age);
            return;
        }
    }
    printf("Not found\n");
}

void sort_by_avg() {
    struct Student temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (group[i].average < group[j].average) {
                temp = group[i];
                group[i] = group[j];
                group[j] = temp;
            }
        }
    }
}

void main() {
    add("Alice", 20, SECOND, 4.7);
    add("Bob", 21, THIRD, 3.8);
    add("Charlie", 19, FIRST, 4.9);

    printf("Before sort:\n");
    print_all();

    sort_by_avg();

    printf("\nAfter sort (by avg):\n");
    print_all();

    printf("\nSearch for Bob:\n");
    search_by_name("Bob");
}
Ответы на вопросы
1. Как объявить структуру в языке C?
Структура объявляется с помощью ключевого слова struct, за которым следует имя структуры и список полей в фигурных скобках:

c
struct Student {
    char name[50];
    int age;
    float average;
};
После объявления можно создавать переменные:

c
struct Student s1;                    // локальная переменная
struct Student *ptr = &s1;            // указатель на структуру
struct Student group[10];             // массив структур
2. Что такое вложенные структуры и зачем они нужны?
Вложенные структуры — это структуры, которые содержат поля, являющиеся другими структурами. Они нужны для:

Группировки логически связанных данных (например, дата рождения как отдельная сущность)

Повышения читаемости кода

Возможности переиспользования (одну структуру Date можно использовать в Person, Event, Document)

Пример:

c
struct Date { int day, month, year; };
struct Person {
    char name[50];
    struct Date birth_date;  // вложенная структура
};
3. Как передать структуру в функцию?
Существует два способа передачи структуры в функцию:

а) По значению — создается копия структуры:

c
void printStudent(struct Student s) {
    printf("%s\n", s.name);
}
б) По указателю — передается адрес структуры (экономия памяти, возможность изменения оригинала):

c
void changeAge(struct Student *s, int newAge) {
    s->age = newAge;  // доступ через ->
}
4. Можно ли создавать массивы структур?
Да, массивы структур создаются так же, как массивы любых других типов:

c
struct Student group[30];  // массив из 30 студентов
Доступ к элементам осуществляется по индексу:

c
group[0].age = 20;
strcpy(group[1].name, "John");
5. Как обратиться к элементу массива структур?
Через комбинацию индекса массива и оператора доступа к полю (.):

c
group[2].average = 4.8;           // присвоение значения полю
printf("%s", group[0].name);       // чтение поля
Если используется указатель на элемент массива:

c
struct Student *ptr = &group[0];
ptr->age = 21;                     // доступ через ->
6. Можно ли использовать enum внутри структуры?
Да, перечисления можно использовать как поля структуры. Это удобно для ограничения набора допустимых значений:

c
enum Course { FIRST, SECOND, THIRD, FOURTH };

struct Student {
    char name[50];
    enum Course course;  // поле типа enum
    float average;
};
Присваивание значения:

c
struct Student s;
s.course = SECOND;
7. Можно ли сравнивать структуры оператором ==?
Нет, нельзя. В языке C оператор == не определен для структур. Сравнение структур необходимо выполнять вручную, сравнивая каждое поле:

c
int compareStudents(struct Student a, struct Student b) {
    return (strcmp(a.name, b.name) == 0 &&
            a.age == b.age &&
            a.average == b.average);
}
Причина: компилятор не может автоматически определить, что значит "равенство" для структуры (особенно если есть поля-массивы или указатели).

Примечания
Во всех программах используется void main(), что допустимо во многих компиляторах, но по стандарту ANSI C рекомендуется int main(void).

Ввод строк через scanf("%s", ...) не безопасен (возможно переполнение буфера), но для учебных целей допустим.

В задании 6 демонстрируется, что при записи в одно поле объединения, остальные поля содержат "мусор" (неопределенное значение).