#include <stdio.h>

void kamQolgan() {
    FILE *fayl = fopen("products.txt", "r");
    char nom[50];
    int narx;
    int miqdor;
    int topilgan = 0;

    if (fayl == NULL) {
        printf("products.txt fayli mavjud emas!\n");
        return;
    }

    printf("\n===== KAM QOLGAN MAHSULOTLAR =====\n\n");

    while (fscanf(fayl, "%49s %d %d", nom, &narx, &miqdor) == 3) {
        if (miqdor <= 5) {
            printf("%s — %d ta (narxi: %d so'm)\n", nom, miqdor, narx);
            topilgan++;
        }
    }

    if (topilgan == 0) {
        printf("Kam qolgan mahsulot topilmadi.\n");
    }

    fclose(fayl);
}

int main() {
    kamQolgan();
    return 0;
}
