/*
	nama : Muhammad Devin Rahadi
	NIM : 23343076
	Latihan : untuk no  1 sampai 3
	 1. membuat struct data mahasiswa
	 2. membuat fungsi input
	 3. membuat fungsi outputnya
*/

#include <stdio.h>

// Definisikan struct mahasiswa
struct Mahasiswa {
  int nim;
  char nama[100];
  char tanggal_lahir[11];
  float ipk;
};

// Fungsi untuk input data mahasiswa
void inputDataMahasiswa(struct Mahasiswa *mahasiswa) {
  printf("Masukkan NIM: ");
  scanf("%d", &(mahasiswa->nim));
  printf("Masukkan nama: ");
  scanf("%s", mahasiswa->nama);
  printf("Masukkan tanggal lahir (dd-mm-yyyy): ");
  scanf("%s", mahasiswa->tanggal_lahir);
  printf("Masukkan IPK: ");
  scanf("%f", &(mahasiswa->ipk));
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanDataMahasiswa(struct Mahasiswa mahasiswa) {
  printf("NIM: %d\n", mahasiswa.nim);
  printf("Nama: %s\n", mahasiswa.nama);
  printf("Tanggal lahir: %s\n", mahasiswa.tanggal_lahir);
  printf("IPK: %.2f\n", mahasiswa.ipk);
}

int main() {
  // Buat instance dari struct Mahasiswa
  struct Mahasiswa mahasiswa;

  // Panggil fungsi input data mahasiswa
  inputDataMahasiswa(&mahasiswa);

  // Panggil fungsi tampilkan data mahasiswa
  tampilkanDataMahasiswa(mahasiswa);

  return 0;
}

