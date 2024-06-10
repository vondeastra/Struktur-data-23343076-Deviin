/*
	Nama : Muhammad Devin Rahadi
	NIM : 23343076
	Kasus : Percobaan 2 queque menggunakan linked list
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *front;
struct node *rear;
void tambah();
void hapus();
void dispaly();

int main(){
	int menu;
	while(menu != 4){
		printf("\n****************Queue Menggunakan Linked List********************\n");
		printf("\n=================================================================\n");
		printf("\n1. Tambah sebuah elemen\n2. Hapus sebuah elemen\n3. Tampilkan antrian\n4. Keluar\n");
		printf("\n Masukkan pilihanmu ?");
		scanf("%d", &menu);
		
		switch(menu){
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
				printf("\n masukkan pilihan menu yang sesuai?\n");
		}
	}
}

void tambah(){
	struct node *ptr;
	int item;
	
	ptr = (struct node *) malloc (sizeof(struct node));
	if(ptr == NULL){
		printf("\n OVERFLOW\n");
		return;
	}
	else {
		printf("\n Silahkan masukan elemen yang kamu inginkan\n");
		scanf("%d", &item);
		ptr->data = item;
		
		if(front == NULL){
			front = ptr;
			rear = ptr;
			front -> next = NULL;
			rear -> next = NULL;
		}
		else{
			rear -> next = ptr;
			rear = ptr;
			rear -> next = NULL;
		}
	}
}

void hapus(){
	struct node *ptr;
	if(front == NULL){
		printf("\n UNDERFLOW\n");
		return;
	}
	else {
		ptr = front;
		front = front -> next;
		free(ptr);
	}
	return;
}

void display(){
	struct node *ptr;
	ptr = front;
	if(front == NULL){
		printf("\n Antrian kosong\n");
	}
	else {
		printf("\n Menampilkan antrian ....\n");
		while(ptr != NULL){
			printf("\n%d\n", ptr -> data);
			ptr = ptr -> next;
		}
	}
}