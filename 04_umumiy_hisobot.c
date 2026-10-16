#include <stdio.h>

void hisobot() {
    FILE *fayl = fopen("products.txt", "r");
    char nom[50];
    int narx;
    int miqdor;
    int turlarSoni = 0;
    int jamiMiqdor = 0;
    long jamiQiymat = 0;

    if (fayl == NULL) {
        printf("products.txt fayli mavjud emas!\n");
        return;
    }

    while (fscanf(fayl, "%49s %d %d", nom, &narx, &miqdor) == 3) {
        turlarSoni++;
        jamiMiqdor = jamiMiqdor + miqdor;
        jamiQiymat = jamiQiymat + (long)narx * miqdor;
    }

    fclose(fayl);

    if (turlarSoni == 0) {
        printf("Fayl bo'sh!\n");
        return;
    }

    printf("\n===== UMUMIY HISOBOT =====\n\n");
    printf("Mahsulot turlari: %d ta\n", turlarSoni);
    printf("Jami mahsulot miqdori: %d ta\n", jamiMiqdor);
    printf("Ombordagi jami qiymat: %ld so'm\n", jamiQiymat);
}

int main() {
    hisobot();
    return 0;
}
