/* 	Nama : MUHAMMAD DEVIN RAHADI
	NIM : 23343076
	PRODI : INFORMATIKA
	KELAS : 202323430157, SELASA 08:50 - 10:30
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk simpul (node) buku
typedef struct BukuNode {
    char judul[100];
    char pengarang[100];
    int tahun;
    struct BukuNode* berikutnya;
    struct BukuNode* sebelumnya;
} BukuNode;

// Struktur untuk Double Linked List
typedef struct {
    BukuNode* kepala;
    BukuNode* ekor;
} BukuDoubleLinkedList;

// Fungsi untuk membuat simpul buku baru
BukuNode* buatSimpulBuku(const char* judul, const char* pengarang, int tahun) {
    BukuNode* simpulBaru = (BukuNode*)malloc(sizeof(BukuNode));
    strcpy(simpulBaru->judul, judul);
    strcpy(simpulBaru->pengarang, pengarang);
    simpulBaru->tahun = tahun;
    simpulBaru->berikutnya = NULL;
    simpulBaru->sebelumnya = NULL;
    return simpulBaru;
}

// Fungsi untuk menambah buku ke Double Linked List
void tambahBuku(BukuDoubleLinkedList* list, const char* judul, const char* pengarang, int tahun) {
    BukuNode* simpulBaru = buatSimpulBuku(judul, pengarang, tahun);
    if (list->kepala == NULL) {
        list->kepala = list->ekor = simpulBaru;
    } else {
        list->ekor->berikutnya = simpulBaru;
        simpulBaru->sebelumnya = list->ekor;
        list->ekor = simpulBaru;
    }
    printf("Buku \"%s\" telah ditambahkan ke daftar.\n", judul);
}

// Fungsi untuk menghapus buku dari Double Linked List berdasarkan judul
void hapusBuku(BukuDoubleLinkedList* list, const char* judul) {
    BukuNode* current = list->kepala;
    while (current != NULL) {
        if (strcmp(current->judul, judul) == 0) {
            if (current->sebelumnya != NULL) {
                current->sebelumnya->berikutnya = current->berikutnya;
            } else {
                list->kepala = current->berikutnya;
            }
            if (current->berikutnya != NULL) {
                current->berikutnya->sebelumnya = current->sebelumnya;
            } else {
                list->ekor = current->sebelumnya;
            }
            free(current);
            printf("Buku \"%s\" telah dihapus dari daftar.\n", judul);
            return;
        }
        current = current->berikutnya;
    }
    printf("Buku \"%s\" tidak ditemukan dalam daftar.\n", judul);
}

// Fungsi untuk menampilkan semua buku dalam Double Linked List
void tampilkanBuku(BukuDoubleLinkedList* list) {
    BukuNode* current = list->kepala;
    if (current == NULL) {
        printf("Tidak ada buku dalam daftar.\n");
        return;
    }
    while (current != NULL) {
        printf("Judul: %s, Pengarang: %s, Tahun: %d\n", current->judul, current->pengarang, current->tahun);
        current = current->berikutnya;
    }
}

int main() {
    BukuDoubleLinkedList perpustakaan;
    perpustakaan.kepala = NULL;
    perpustakaan.ekor = NULL;

    tambahBuku(&perpustakaan, "Harry Potter", "J.K. Rowling", 1997);
    tambahBuku(&perpustakaan, "Laskar Pelangi", "Andrea Hirata", 2005);
    tambahBuku(&perpustakaan, "1984", "George Orwell", 1949);

    printf("\nDaftar Buku:\n");
    tampilkanBuku(&perpustakaan);

    hapusBuku(&perpustakaan, "Laskar Pelangi");

    printf("\nDaftar Buku Setelah Penghapusan:\n");
    tampilkanBuku(&perpustakaan);

    return 0;
}
