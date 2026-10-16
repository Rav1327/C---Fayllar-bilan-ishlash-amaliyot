#include <stdio.h>
#include <string.h>

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
    int tanlov = -1;
    int natija;
    int belgi;

    while (tanlov != 0) {
        printf("\n===== MAHSULOTLAR BOSHQARUVI =====\n\n");
        printf("1. Mahsulotlarni ko'rish\n");
        printf("2. Yangi mahsulot qo'shish\n");
        printf("3. Umumiy hisobot\n");
        printf("4. Kam qolgan mahsulotlar\n");
        printf("5. Eng qimmat mahsulot\n");
        printf("6. Eng arzon mahsulot\n");
        printf("0. Chiqish\n\n");
        printf("Tanlovingiz: ");

        natija = scanf("%d", &tanlov);

        if (natija == EOF) {
            tanlov = 0;
        } else if (natija != 1) {
            do {
                belgi = getchar();
            } while (belgi != '\n' && belgi != EOF);
            tanlov = -1;
        }

        switch (tanlov) {
            case 1:
                oqish();
                break;
            case 2:
                qoshish();
                break;
            case 3:
                hisobot();
                break;
            case 4:
                kamQolgan();
                break;
            case 5:
                engQimmat();
                break;
            case 6:
                engArzon();
                break;
            case 0:
                printf("Dastur tugadi.\n");
                break;
            default:
                printf("Noto'g'ri tanlov! Qaytadan urinib ko'ring.\n");
        }
    }

    return 0;
}
