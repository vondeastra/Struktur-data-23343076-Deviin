/*
	Nama : Muhammad Devin Rahadi
	NIM : 23343076
	Kasus : Percobaan 5 Priority queue
*/

#include <stdio.h>

int ukuran = 0;

void swap(int *a, int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

void heapify(int array[], int ukuran, int i) {
	if (ukuran == 1){
		printf("Elemen tunggal pada heep");
	} else{
		int largest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if (l< ukuran && array[1] > array[largest]){
			largest = 1;
		}
		if (r < ukuran && array[r] > array[largest]){
			largest = r;
		}
		if (largest != i) {
			swap(&array[i], &array[largest]);
			heapify(array, ukuran, largest);
		}
	}
}

void insert(int array[], int newNum){
	if(ukuran == 0){
		array[0] = newNum;
		ukuran += 1;
	} else {
		array[ukuran] = newNum;
		ukuran += 1;
		for (int i = ukuran / 2 - 1; i>=0; i-- ){
			heapify(array, ukuran, i);
		}
	}
}

void deleteRoot(int array[], int num){
	int i; 
	for (i = 0; i < ukuran; i++){
		if (num == array[i]){
			break;
		}
	}
	swap(&array[i], &array[ukuran - 1]);
	ukuran -=1;
	for (int i = ukuran / 2 - 1; i>=0; i--){
		heapify(array, ukuran, i);
	}
}

void printArray(int array[], int ukuran){
	for(int i = 0; i < ukuran; ++i){
		printf("%d", array[i]);
	}
	printf("\n");
}

int main() { 
  int array[10]; 
  insert(array, 3); 
  insert(array, 4); 
  insert(array, 9); 
  insert(array, 5); 
  insert(array, 2); 
 
  printf("Max-Heap array adalah : "); 
  printArray(array, ukuran); 
  deleteRoot(array, 4); 
  printf("Setelah proses penghapusan elemen: "); 
  printArray(array, ukuran); 
}