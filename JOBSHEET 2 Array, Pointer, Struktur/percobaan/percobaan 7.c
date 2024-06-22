/*
	nama : Muhammad Devin Rahadi
	NIM : 23343076
	kasus : array percobaan 7
*/

#include <stdio.h>

typedef struct Mahasiswa {
	char nama[50];
	char jurusan[50];
	int nilai;
}data;

int main(void){
	data mhs01;
	
	strcpy(mhs01.nama, "Devin");
	strcpy(mhs01.jurusan, "Informatika");
	mhs01.nilai = 100;
	
	printf("%s adalah mahasiswa jurusan %s\n", mhs01.nama, mhs01.jurusan);
	printf("memperoleh nilai UAS %i \n", mhs01.nilai);
	
	return 0;
}