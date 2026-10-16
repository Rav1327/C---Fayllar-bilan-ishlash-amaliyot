#include <stdio.h>
#include <string.h>

void engQimmat() {
    FILE *fayl = fopen("products.txt", "r");
    char nom[50];
    char engQimmatNom[50];
    int narx;
    int miqdor;
    int engQimmatNarx = 0;
    int engQimmatMiqdor = 0;
    int soni = 0;

    if (fayl == NULL) {
        printf("products.txt fayli mavjud emas!\n");
        return;
    }

    while (fscanf(fayl, "%49s %d %d", nom, &narx, &miqdor) == 3) {
        if (soni == 0 || narx > engQimmatNarx) {
            strcpy(engQimmatNom, nom);
            engQimmatNarx = narx;
            engQimmatMiqdor = miqdor;
        }
        soni++;
    }

    fclose(fayl);

    if (soni == 0) {
        printf("Fayl bo'sh!\n");
        return;
    }

    printf("\n===== ENG QIMMAT MAHSULOT =====\n\n");
    printf("Nomi: %s\n", engQimmatNom);
    printf("Narxi: %d so'm\n", engQimmatNarx);
    printf("Miqdori: %d ta\n", engQimmatMiqdor);
}

int main() {
    engQimmat();
    return 0;
}
