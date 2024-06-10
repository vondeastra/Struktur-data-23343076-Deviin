/* 	Nama : Muhammad Devin Rahadi
	NNIM : 23343076
	Percobaan : percobaan 3 shell sort
*/

#include<stdio.h>

void shellSort(int a[], int n){
	int i, j, increment, tmp;
	for(increment = n/2; increment > 0; increment /= 2){
		for(i = increment; i < n; i++){
			tmp=a[i];
			for(j = i; j >= increment; j -= increment){
				if(tmp < a[j-increment]){
					a[j] = a[j-increment];
				} else {
					break;
				}
			}
			a[j] = tmp;
		}
	}
}

int main(){
	int i, n, a[10];
	printf("Masukan jumlah elemen : ");
	scanf("%d", &n);
	printf("Masukan %d bilangan : \n",n);
	
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	shellSort(a,n);
	
	printf("eleemen yang telah diurutkana adalah : \n");
	for(i = 0; i < n; i++){
		printf("%d\n", a[i]);
	}
	printf("\n");
	return 0;
}