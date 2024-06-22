/* 	Nama : Muhammad Devin Rahadi
	NNIM : 23343076
	Percobaan : percobaan 1 shell sort
*/

#include<stdio.h>

void shellSort(int array[], int n){
	for(int gap = n/2; gap > 0; gap /= 2){
		for(int i = gap; i < n; i += 1){
			int temp = array[i];
			int j;
			for(j = 1; j >= gap && array[j-gap] > temp; j -= gap){
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
	}
}

void printArray(int array[], int size){
	for(int i=0; i<size; ++i){
		printf("%d", array[i]);
	}
	printf("\n");
}

int main(){
	int data[]={9, 8, 3, 7, 5, 6, 4, 1};
	int size = sizeof(data) / sizeof(data[0]);
	shellSort(data, size);
	printf("Sorted array: \n");
	printArray(data, size);
}