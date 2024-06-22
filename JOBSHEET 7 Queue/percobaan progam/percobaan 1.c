/*
	Nama : Muhammad Devin Rahadi
	NIM : 23343076
	Kasus : Percobaan 1 queque menggunakan array
*/

#include <stdio.h>
#include <stdlib.h>
#define ukuran 5

void tambah();
void hapus();
void display();
int front = -1, rear = -1;
int queue[ukuran];

int main(){
	int pilihan;
	while(pilihan !=4){
		printf("\n*************************Main Menu*****************************\n");
		printf("\n=================================================================\n");
		printf("\n1.Tambah sebuah elemen\n2.hapus sebuha elemen\n3.Tampilkan atrian\n4.Keluar\n");
		printf("\n Masukkan pilihanmu ?");
		scanf("%d", &pilihan);
		
		switch(pilihan){
			case 1 :
				tambah();
				break;
			case 2 :
				hapus();
				break;
			case 3 :
				display();
				break;
			case 4 :
				exit(0);
				break;
			default :
				printf("\n Masukkan pilihan yang sesuai?\n");
		}
	}
}

void tambah(){
	int item;
	
	printf("\n Sihlakan masukan elemen yang kamu inginkan\n");
	scanf("\n %d", &item);
	
	if(rear == ukuran - 1){
		printf("\n OVERFLOW \n");
		return;
	}
	if(front == -1 && rear == -1){
		front = 0;
		rear = 0;
	}
	else {
		rear = rear + 1;
	}
	queue[rear] = item;
	printf("\n Nilai berhasil ditambahkan");
}

void hapus(){
	int item;
	if(front == -1 || front > rear){
		printf("\n UNDERFLOW\n");
		return;
	}
	else {
		item = queue[front];
		if(front == rear){
			front = -1;
			rear = -1;
		}
		else{
			front = front + 1;
		}
		printf("\n Nilai berhasil dihapus");
	}
}

void display() {
	int i;
	
	if(rear == -1){
		printf("\n Antrian kosonhg\n");
	}
	else{
		printf("\n Menampilkan nilai .....\n");
		for(i = front; i <= rear; i++){
			printf("\n %d\n", queue[i]);
		}
	}
}
