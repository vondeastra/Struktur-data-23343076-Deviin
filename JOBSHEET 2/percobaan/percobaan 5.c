/*
  nama : muhammad devin rahadi
  NIM : 23343076
  kasus : array percobaan 5
*/
 
#include<stdio.h>

struct Mahasiswa {
	char nama[50];
	char jurusan[50];
	int nilai;
};

int main(void){
	struct 	Mahasiswa mhs01;
	
	strcpy(mhs01.nama, "devin");
	strcpy(mhs01.jurusan, "Informatika");
	mhs01.nilai = 100;
	
	printf("%s adalah Mahasiswa jurusan %s\n", mhs01.nama, mhs01.jurusan);
	printf("memperoleh hasil UAS %i \n", mhs01.nilai);
	
	return 0;
}
	