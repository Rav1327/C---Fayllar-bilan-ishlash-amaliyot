#include <stdio.h>

void oqish() {
    FILE *fayl = fopen("products.txt", "r");
    char nom[50];
    int narx;
    int miqdor;
    int soni = 0;

    if (fayl == NULL) {
        printf("products.txt fayli mavjud emas!\n");
        return;
    }

    printf("\n===== MAHSULOTLAR =====\n\n");

    while (fscanf(fayl, "%49s %d %d", nom, &narx, &miqdor) == 3) {
        printf("Nomi: %s\n", nom);
        printf("Narxi: %d so'm\n", narx);
        printf("Miqdori: %d ta\n", miqdor);
        printf("-----------------------\n");
        soni++;
    }

    if (soni == 0) {
        printf("Fayl bo'sh!\n");
    }

    fclose(fayl);
}

int main() {
    oqish();
    return 0;
}
