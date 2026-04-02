#include <stdio.h>

void main() {
    FILE *f = fopen("test.txt", "w");
    if (f == NULL) {
        printf("НЕ УДАЛОСЬ ОТКРЫТЬ БЛЯ\n");
    } else {
        printf("Файл открыт, всё пучком\n");
        fclose(f);
    }
}
