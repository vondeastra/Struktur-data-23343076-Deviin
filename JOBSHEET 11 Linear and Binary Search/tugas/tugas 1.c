/* 	Nama : MUHAMMAD DEVIN RAHADI
	NIM : 23343076
	PRODI : INFORMATIKA
	KELAS : 202323430157, SELASA 08:50 - 10:30
*/

#include <stdio.h>
#include <string.h>

// Struktur data mahasiswa
typedef struct {
    int NIM;
    char nama[50];
    char TTL[50];
    float IPK;
} Mahasiswa;

// Fungsi untuk menampilkan data mahasiswa
void tampilkanMahasiswa(Mahasiswa m) {
    printf("NIM: %d\n", m.NIM);
    printf("Nama: %s\n", m.nama);
    printf("TTL: %s\n", m.TTL);
    printf("IPK: %.2f\n", m.IPK);
}

// Fungsi Sequential Search
int sequentialSearch(Mahasiswa data[], int n, int nim) {
    for (int i = 0; i < n; i++) {
        if (data[i].NIM == nim) {
            return i;
        }
    }
    return -1;
}

// Fungsi Binary Search
int binarySearch(Mahasiswa data[], int n, int nim) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (data[mid].NIM == nim) {
            return mid;
        } else if (data[mid].NIM < nim) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Fungsi untuk membandingkan NIM (digunakan untuk sorting)
int compareNIM(const void *a, const void *b) {
    Mahasiswa *ma = (Mahasiswa *)a;
    Mahasiswa *mb = (Mahasiswa *)b;
    return (ma->NIM - mb->NIM);
}

int main() {
    Mahasiswa data[5] = {
        {101, "Alice", "01-01-2000", 3.5},
        {102, "Bob", "02-02-2001", 3.7},
        {103, "Charlie", "03-03-2002", 3.6},
        {104, "David", "04-04-2003", 3.8},
        {105, "Eve", "05-05-2004", 3.9}
    };

    int n = sizeof(data) / sizeof(data[0]);
    int nimDicari;

    // Sorting data untuk binary search
    qsort(data, n, sizeof(Mahasiswa), compareNIM);

    printf("Masukkan NIM yang ingin dicari: ");
    scanf("%d", &nimDicari);

    // Sequential Search
    int indeksSeq = sequentialSearch(data, n, nimDicari);
    if (indeksSeq != -1) {
        printf("Data ditemukan dengan Sequential Search:\n");
        tampilkanMahasiswa(data[indeksSeq]);
    } else {
        printf("Data tidak ditemukan dengan Sequential Search.\n");
    }

    // Binary Search
    int indeksBin = binarySearch(data, n, nimDicari);
    if (indeksBin != -1) {
        printf("Data ditemukan dengan Binary Search:\n");
        tampilkanMahasiswa(data[indeksBin]);
    } else {
        printf("Data tidak ditemukan dengan Binary Search.\n");
    }

    return 0;
}
