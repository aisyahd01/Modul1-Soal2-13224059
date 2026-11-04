
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int indeks;
    char kata[100];
} Paket;

/* Membalikkan susunan karakter kata. */
void balikKata(char *kata) {
    int kiri = 0;
    int kanan = (int)strlen(kata) - 1;

    while (kiri < kanan) {
        char temp = kata[kiri];
        kata[kiri] = kata[kanan];
        kata[kanan] = temp;

        kiri++;
        kanan--;
    }
}

/* Membandingkan indeks paket untuk sorting. */
int bandingkanPaket(const void *a, const void *b) {
    const Paket *paketA = (const Paket *)a;
    const Paket *paketB = (const Paket *)b;

    if (paketA->indeks < paketB->indeks) {
        return -1;
    }

    if (paketA->indeks > paketB->indeks) {
        return 1;
    }

    return 0;
}

int main(void) {
    int jumlah;
    char kodeValid[100];

    if (scanf("%d %99s", &jumlah, kodeValid) != 2 || jumlah < 0) {
        return 0;
    }

    /* Membuat dynamic array. */
    Paket *paket = NULL;

    if (jumlah > 0) {
        paket = malloc((size_t)jumlah * sizeof(Paket));

        if (paket == NULL) {
            return 1;
        }
    }

    int jumlahValid = 0;

    /* Membaca dan memeriksa seluruh paket. */
    for (int i = 0; i < jumlah; i++) {
        int indeks;
        char kode[100];
        char kata[100];

        if (scanf("%d %99s %99s", &indeks, kode, kata) != 3) {
            break;
        }

        if (strcmp(kode, kodeValid) == 0) {
            balikKata(kata);

            paket[jumlahValid].indeks = indeks;
            strcpy(paket[jumlahValid].kata, kata);

            jumlahValid++;
        }
    }

   

    /* Mengurutkan paket berdasarkan indeks. */
    qsort(paket, (size_t)jumlahValid, sizeof(Paket),
          bandingkanPaket);

    int totalKarakter = 0;

    /* Menggabungkan kata dan menghitung jumlah karakter. */
    for (int i = 0; i < jumlahValid; i++) {
        if (i > 0) {
            printf(" ");
        }

        printf("%s", paket[i].kata);
        totalKarakter += (int)strlen(paket[i].kata);
    }

    printf("\nLENGTH %d\n", totalKarakter);

    free(paket);

    return 0;
}

/*algoritma qsort https://www.geeksforgeeks.org/c/qsort-function-in-c/ */
