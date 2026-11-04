/*Nama= Aisyah Dahayu Shabirah
NIM: 13224059
Modul 1: Data Manipulation, External FIles, Sturctures an Dynamic Array
Deskripsi: Program untuk menyaring paket yang valid, membalikkan kata sandi
dan mengurutkan paket */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int indeks;
    char kata[50];
}Paket;

void balikKata(char *kata){
    int kiri = 0;
    int kanan= (int)strlen(kata) -1;
    while(kiri < kanan){
        char temp= kata[kiri];
        kata[kiri]= kata[kanan];
        kata[kanan] = temp;

        kiri++;
        kanan--;
    }
}

int bandingkanPaket(const void *a, const void *b){
    const Paket *paketA = (const Paket *)a;
    const Paket *paketB = (const Paket *)b;

    if (paketA->indeks < paketB->indeks){
        return -1;
    }if (paketA->indeks < paketB->indeks){
        return 1;
    }
    return 0;
}

int main(){
    int jumlah;
    char kodeValid[50];

    if (scanf("%d %49s", &jumlah, kodeValid) != 2 || jumlah < 0){
        return 0;
    }
    Paket *paket = NULL;
    if (jumlah > 0){
        paket = malloc((size_t)jumlah *sizeof(Paket));
        
        if (paket == NULL){
            return 1;
        }
    }
    /* Memeriksa paket valid */
    int jumlahValid = 0;
    for (int i = 0; i < jumlah; i++){
        int indeks;
        char kode[50];
        char kata[50];

        if (scanf("%d %49s %49s", &indeks, kode, kata) !=3){
            break;
        }
        if (strcmp(kode, kodeValid)==0){
            balikKata(kata);
            paket[jumlahValid].indeks= indeks;
            strcpy(paket[jumlahValid].kata, kata);
            
            jumlahValid++;
        }
    }

    if (jumlahValid == 0){
        printf("00");
        free(paket);
        return 0;
    }

    /* Mengurutkan paket berdasarkan indeks. */
    qsort(paket, (size_t)jumlahValid, sizeof(Paket),
          bandingkanPaket);

    int totalKarakter= 0;
    /* Menggabungkan kata dan menghitung jumlah karakter. */
    for (int i = 0; i < jumlahValid; i++){
        if (i > 0){
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
/*algoritma qsort https://www.geeksforgeeks.org/c/qsort-function-in-c/ */
