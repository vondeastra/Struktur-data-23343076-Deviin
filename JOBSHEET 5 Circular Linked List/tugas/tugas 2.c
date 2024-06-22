/* 	Nama : MUHAMMAD DEVIN RAHADI
	NIM : 23343076
	PRODI : INFORMATIKA
	KELAS : 202323430157, SELASA 08:50 - 10:30
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk simpul (node) mobil
typedef struct MobilNode {
    char noPlat[20];
    char merk[50];
    char namaPemilik[50];
    struct MobilNode* berikutnya;
    struct MobilNode* sebelumnya;
} MobilNode;

// Struktur untuk Double Linked List
typedef struct {
    MobilNode* kepala;
    MobilNode* ekor;
} MobilDoubleLinkedList;

// Fungsi untuk membuat simpul mobil baru
MobilNode* buatSimpulMobil(const char* noPlat, const char* merk, const char* namaPemilik) {
    MobilNode* simpulBaru = (MobilNode*)malloc(sizeof(MobilNode));
    strcpy(simpulBaru->noPlat, noPlat);
    strcpy(simpulBaru->merk, merk);
    strcpy(simpulBaru->namaPemilik, namaPemilik);
    simpulBaru->berikutnya = NULL;
    simpulBaru->sebelumnya = NULL;
    return simpulBaru;
}

// Fungsi untuk menambah mobil ke Double Linked List
void tambahMobil(MobilDoubleLinkedList* list, const char* noPlat, const char* merk, const char* namaPemilik) {
    MobilNode* simpulBaru = buatSimpulMobil(noPlat, merk, namaPemilik);
    if (list->kepala == NULL) {
        list->kepala = list->ekor = simpulBaru;
    } else {
        list->ekor->berikutnya = simpulBaru;
        simpulBaru->sebelumnya = list->ekor;
        list->ekor = simpulBaru;
    }
    printf("Mobil dengan no plat \"%s\" telah ditambahkan ke antrian.\n", noPlat);
}

// Fungsi untuk menghapus mobil dari Double Linked List berdasarkan no plat
void hapusMobil(MobilDoubleLinkedList* list, const char* noPlat) {
    MobilNode* current = list->kepala;
    while (current != NULL) {
        if (strcmp(current->noPlat, noPlat) == 0) {
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
            printf("Mobil dengan no plat \"%s\" telah dihapus dari antrian.\n", noPlat);
            return;
        }
        current = current->berikutnya;
    }
    printf("Mobil dengan no plat \"%s\" tidak ditemukan dalam antrian.\n", noPlat);
}

// Fungsi untuk menampilkan semua mobil dalam Double Linked List
void tampilkanMobil(MobilDoubleLinkedList* list) {
    MobilNode* current = list->kepala;
    if (current == NULL) {
        printf("Tidak ada mobil dalam antrian.\n");
        return;
    }
    while (current != NULL) {
        printf("No Plat: %s, Merk: %s, Nama Pemilik: %s\n", current->noPlat, current->merk, current->namaPemilik);
        current = current->berikutnya;
    }
}

int main() {
    MobilDoubleLinkedList perparkiran;
    perparkiran.kepala = NULL;
    perparkiran.ekor = NULL;

    tambahMobil(&perparkiran, "B1234XYZ", "Toyota", "Andi");
    tambahMobil(&perparkiran, "B5678ABC", "Honda", "Budi");
    tambahMobil(&perparkiran, "B9012DEF", "Suzuki", "Citra");

    printf("\nAntrian Mobil:\n");
    tampilkanMobil(&perparkiran);

    hapusMobil(&perparkiran, "B5678ABC");

    printf("\nAntrian Mobil Setelah Penghapusan:\n");
    tampilkanMobil(&perparkiran);

    return 0;
}
