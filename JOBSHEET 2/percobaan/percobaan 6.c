/*
	nama : Muhammad Devin Rahadi
	NIM : 23343076
	kasus : array percobaan 6
*/
#include <stdio.h>

struct Mahasiswa {
	char nama[50];
	char jurusan[50];
	int nilai;
};typedef struct Mahasiswa data;

int main(void){
	data mhs01;
	
	strcpy(mhs01.nama,"Devin");
	strcpy(mhs01.jurusan, "Informatika");
	mhs01.nilai = 100;
	
	printf("%s adalah mahasiswa jurusan %s\n", mhs01.nama, mhs01.jurusan);
	printf("Memperoleh nilai UAS %i \n", mhs01.nilai);
	
	return 0;
}