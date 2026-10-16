#include <stdio.h>
#include <string.h>

void engArzon() {
    FILE *fayl = fopen("products.txt", "r");
    char nom[50];
    char engArzonNom[50];
    int narx;
    int miqdor;
    int engArzonNarx = 0;
    int engArzonMiqdor = 0;
    int soni = 0;

    if (fayl == NULL) {
        printf("products.txt fayli mavjud emas!\n");
        return;
    }

    while (fscanf(fayl, "%49s %d %d", nom, &narx, &miqdor) == 3) {
        if (soni == 0 || narx < engArzonNarx) {
            strcpy(engArzonNom, nom);
            engArzonNarx = narx;
            engArzonMiqdor = miqdor;
        }
        soni++;
    }

    fclose(fayl);

    if (soni == 0) {
        printf("Fayl bo'sh!\n");
        return;
    }

    printf("\n===== ENG ARZON MAHSULOT =====\n\n");
    printf("Nomi: %s\n", engArzonNom);
    printf("Narxi: %d so'm\n", engArzonNarx);
    printf("Miqdori: %d ta\n", engArzonMiqdor);
}

int main() {
    engArzon();
    return 0;
}
