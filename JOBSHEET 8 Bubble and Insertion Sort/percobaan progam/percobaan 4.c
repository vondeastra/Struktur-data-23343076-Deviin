/* NAMA : MUHAMMAD DEVIN RAHADI
   NIM : 23343076
   TUGAS : PERCOBAAN 4 BUBLE SORT WITH ITERATION
*/

#include <stdio.h> 
#include <stdbool.h> 
#define MAX 10 
 
int list[MAX] = {1,8,4,6,0,3,5,2,7,9}; 
 
void display() { 
   int i; 
   printf("["); 
  
   // navigate through all items  
   for(i = 0; i < MAX; i++) { 
      printf("%d ",list[i]); 
   } 
  
   printf("]\n"); 
} 

void bubleSort() {
	int temp;
	int i, j;
	bool swapped = false;
	
	for(i = 0; i < MAX-1; i++){
		swapped = false;
		
		for(j = 0; j < MAX-1; j++){
			printf(" Items compared: [%d, %d]", list[j],list[j+1]);
			
			if(list[j] > list[j+1]){
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
				
				swapped = true;
				printf(" => swapped[%d,%d]\n", list[j], list[j+1]);
			} else {
				printf(" => not swapped\n");
			}
		}
		if(!swapped){
			break;
		}
		printf("Iteration %d#: ", (i+1));
		display();
	}
}

int main(){
	printf("Input Array: ");
	display();
	printf("\n");
	
	bubleSort();
	printf("\nOutput Array: ");
	display();
}