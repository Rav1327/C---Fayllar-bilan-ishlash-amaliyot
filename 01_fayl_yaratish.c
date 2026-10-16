#include <stdio.h>

int main() {
    FILE *fayl = fopen("products.txt", "w");

    if (fayl == NULL) {
        printf("Faylni yaratib bo'lmadi!\n");
        return 1;
    }

    fprintf(fayl, "Non 5000 20\n");
    fprintf(fayl, "Sut 12000 8\n");
    fprintf(fayl, "Shakar 15000 3\n");
    fprintf(fayl, "Yog 25000 2\n");
    fprintf(fayl, "Guruch 18000 15\n");
    fprintf(fayl, "Tuxum 2000 4\n");
    fprintf(fayl, "Un 10000 12\n");

    fclose(fayl);

    printf("products.txt fayli yaratildi.\n");

    return 0;
}
