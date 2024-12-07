#include "stdio.h"
#include "string.h"
const int MAX = 100;

typedef struct {
    char hang[11];
    char chip[4];
    int ram;
    float gia;
    char chuanhoa[50];
} Maytinh;

int checkchip(char chip[]) {
    return strcmp(chip, "i3") == 0 || strcmp(chip, "i5") == 0 || strcmp(chip, "i7") == 0;
}

void nhap(Maytinh mt[], int *n) {
    char choice;
    do {
        printf("Nhap thong tin cua may tinh thu %d:\n", *n + 1);
        do {
            printf("Nhap ten hang: ");
            scanf("%s", mt[*n].hang);
            if (strlen(mt[*n].hang) > 10) {
                printf("Nhap sai! Vui long nhap lai!\n");
            }
        } while (strlen(mt[*n].hang) > 10);
        do {
            printf("Nhap chip cua may (i3, i5, i7): ");
            scanf("%s", mt[*n].chip);
            if (!checkchip(mt[*n].chip)) {
                printf("Nhap sai! Vui long nhap lai!\n");
            }
        } while (!checkchip(mt[*n].chip));
        do {
            printf("Nhap RAM cua may (chia het cho 4): ");
            scanf("%d", &mt[*n].ram);
            if (mt[*n].ram <= 0 || mt[*n].ram % 4 != 0) {
                printf("Nhap sai! Vui long nhap lai!\n");
            }
        } while (mt[*n].ram <= 0 || mt[*n].ram % 4 != 0);
        do {
            printf("Nhap gia cua may (trieu VND): ");
            scanf("%f", &mt[*n].gia);
            if (mt[*n].gia <= 0) {
                printf("Nhap sai! Vui long nhap lai!\n");
            }
        } while (mt[*n].gia <= 0);
        (*n)++;
        printf("Ban co muon nhap tiep? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');
}
void chuanhoa(Maytinh mt[], int n) {
    for (int i = 0; i < n; i++) {
        sprintf(mt[i].chuanhoa, "%s.%s.%d", mt[i].hang, mt[i].chip, mt[i].ram);
    }
}
void sort(Maytinh mt[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mt[i].gia > mt[j].gia) {
                Maytinh tmp = mt[i];
                mt[i] = mt[j];
                mt[j] = tmp;
            }
        }
    }
}
void solve(Maytinh mt[], int n) {
    printf("\nDanh sach cac may tinh thoa man :\n");
    printf("Stt - Ma            - Chip - RAM - Gia\n");

    int j = 1;
    for (int i = 0; i < n; i++) {
        if (strcmp(mt[i].hang, "Asus") == 0 &&
            (strcmp(mt[i].chip, "i5") == 0 || strcmp(mt[i].chip, "i7") == 0) &&
            mt[i].ram >= 8 && mt[i].gia < 25) {
            printf("%d - %-15s - %-3s  - %-3d - %.2f\n", j++, mt[i].chuanhoa, mt[i].chip, mt[i].ram, mt[i].gia);
        }
    }
}

int main() {
    Maytinh mt[MAX];
    int n = 0;
    nhap(mt, &n);
    chuanhoa(mt, n);
    sort(mt, n);
    solve(mt, n);
    return 0;
}
