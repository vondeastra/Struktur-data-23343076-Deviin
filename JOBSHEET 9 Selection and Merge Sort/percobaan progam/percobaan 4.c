/* 	Nama : Muhammad Devin Rahadi
	NNIM : 23343076
	Percobaan : percobaan 4 selection sort - proses iterasi pengurutan data
*/

#include<stdio.h>
#include<stdbool.h>
#define MAX 7

int intArray[MAX] = {4, 6, 3, 2, 1, 9, 7};

void printline(int count) {
	int i;
	
	for(i = 0; i < count-1; i++){
		printf("=");
	}
	printf("=\n");
}

void display(){
	int i;
	printf("[");
	
	for(i = 0; i< MAX; i++){
		printf("%d", intArray[i]);
	}
	printf("]\n");
}

void selectionSort(){
	int indexMin, i, j;
	
	for (i = 0; i< MAX-1; i++){
		indexMin = i;
		
		for(j = i+1; j < MAX; j++) {
			if(intArray[j] < intArray[indexMin]) {
				indexMin = j;
			}
		}
		if(indexMin != i) {
			printf("Items swapped: [ %d, %d ]\n", intArray[i], intArray[indexMin]);
			
			int temp = intArray[indexMin];
			intArray[indexMin] = intArray[i];
			intArray[i] = temp;
		}
		printf("Iteration %d#:", (i+1));
		display();
	}
}

int main(){
	printf("Input Array: ");
	display();
	printline(50);
	selectionSort();
	printf("Output Array: ");
	display();
	printline(50);
}