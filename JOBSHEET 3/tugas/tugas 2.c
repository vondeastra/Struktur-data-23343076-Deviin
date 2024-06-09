/* Nama : Muhammad Devin Rahadi
   NIM  : 23343076
   prodi :informatika
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int *prima, n, m, i, j, count = 0;

    printf("Masukkan bilangan prima yang ingin ditampilkan : ");
    scanf("%d", &n);

    // Alokasi memori untuk prima dengan malloc
    prima = (int*)malloc(n * sizeof(int));

    // Inisialisasi bilangan prima pertama
    prima[count] = 2;
    count++;

    // Cari bilangan prima sampai ke-n
    for (i = 3; count < n; i += 2) {
        for (j = 3; j <= (int)sqrt(i); j += 2) {
            if (i % j == 0) {
                break;
            }
        }
        if (j > (int)sqrt(i)) {
            prima[count] = i;
            count++;
        }
    }

    // Ubah ukuran memori dengan realloc
    printf("Masukkan ukuran memori yang baru : ");
    scanf("%d", &m);
    prima = (int*)realloc(prima, m * sizeof(int));

    // Tampilkan bilangan prima
    printf("Bilangan prima pertama sampai ke %d : \n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", prima[i]);
    }
    printf("\n");

    // Tampilkan alamat memori
    printf("Alamat memori prima : %p\n", prima);

    // Bebaskan memori
    free(prima);

    return 0;
}