/* 	Nama : MUHAMMAD DEVIN RAHADI
	NIM : 23343076
	PRODI : INFORMATIKA
	KELAS : 202323430157, SELASA 08:50 - 10:30
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct{
	char nim[10];
	char nama[50];
	int nilai;
}Mahasiswa;

Mahasiswa stack[MAX];
int top = -1;

void push(Mahasiswa);
void pop();
void display();
void sort();

int main(){
	int ch;
	Mahasiswa mhs;
	
	while(1){
		printf("\n** Menu Stack Mahasiswa **");
		printf("\n\n1. Tambahkan data\n2. Hapus data\n3. Tampilkan data\n4. Urutkan data\n5. Keluar");
		printf("\n\n Masukan pilihanmu (1-5): ");
		scanf("%d", &ch);
		
		switch(ch){
			case 1:
				printf("\nMasukkan NIM: ");
				scanf("%s", mhs.nim);
				printf("Masukkan nama: ");
				scanf("%s", mhs.nama);
				printf("Masukkan nilai: ");
				scanf("%d", &mhs.nilai);
				push(mhs);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				sort();
				break;
			case 5:
				exit(0);
			default:
				printf("\nPilihan tidak valid!");
		}
	}
}

void push(Mahasiswa mhs){
	if(top == MAX-1){
		printf("\nStack penuh!!");
	} else {
		top = top+1;
		stack[top] = mhs;
	}
}

void pop() 
{ 
    if(top==-1) 
    { 
        printf("\nStack kosong!!"); 
    } 
    else 
    { 
        top=top-1; 
    } 
}

void display(){
	int i;
	
	if(top==-1){
		printf("\nStack kosong!!");
	} else {
		printf("\n Item pada stack adalah.....\n");
		for(i=top; i>=0; --i){
			printf("NIM: %s, Nama: %s, Nilai: %d\n", stack[i].nim, stack[i].nama, stack[i].nilai);
		}
	}
}

void sort(){
	int i, j;
	Mahasiswa temp;
	
	if(top==-1){
		printf("\nStack kosong!!");
	} else {
		for(i=0; i<top; i++){
			for(j=0; j<top-i; j++){
				if(stack[j].nilai < stack[j+1].nilai){
					temp = stack[j];
					stack[j] = stack[j+1];
					stack[j+1] = temp;
				}
			}
		}
	}
}