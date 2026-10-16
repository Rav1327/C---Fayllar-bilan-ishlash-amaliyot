#include <stdio.h>

void qoshish() {
    FILE *fayl;
    char nom[50];
    int narx;
    int miqdor;

    printf("Mahsulot nomi: ");
    if (scanf("%49s", nom) != 1) {
        printf("Noto'g'ri ma'lumot kiritildi!\n");
        return;
    }
    printf("Mahsulot narxi: ");
    if (scanf("%d", &narx) != 1) {
        printf("Noto'g'ri ma'lumot kiritildi!\n");
        return;
    }
    printf("Mahsulot miqdori: ");
    if (scanf("%d", &miqdor) != 1) {
        printf("Noto'g'ri ma'lumot kiritildi!\n");
        return;
    }

    fayl = fopen("products.txt", "a");
    if (fayl == NULL) {
        printf("Faylni ochib bo'lmadi!\n");
        return;
    }

    fprintf(fayl, "%s %d %d\n", nom, narx, miqdor);
    fclose(fayl);

    printf("Mahsulot muvaffaqiyatli qo'shildi!\n");
}

int main() {
    qoshish();
    return 0;
}
