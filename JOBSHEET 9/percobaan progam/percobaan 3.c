/* 	Nama : Muhammad Devin Rahadi
	NNIM : 23343076
	Percobaan : percobaan 3 merge sort - entry element
*/

#include<stdio.h>

//function to sort the subsection a[i .. j] of the array a[]

void merge_sort(int i, int j, int a[], int aux[]) {
	if(j <= i) {
		return;
	}
	int mid = (i + j) / 2;
	
	merge_sort(i, mid, a, aux);
	merge_sort(mid+1, j, a, aux);
	int pointer_left = i;
	int pointer_right = mid + 1;
	int k;
	
	for (k = i; k ,= j; k++) {
		if(pointer_left == mid + 1) {
			aux[k] = a[pointer_right];
			pointer_right++
		} else if(pointer_right == j + 1){
			aux[k] = a[pointer_left];
			pointer_left++;
		} else if(a[pointer_left] < a[pointer_right]) {
			aux[k] = a[pointer_left];
			pointer_left++;
		} else {
			aux[k] = a[pointer_right];
			pointer_right++;
		}
	}
	for (k = 1; k <= j; k++) {
		a[k] = aux[k];
	}
}

int main(){
	int a[100], aux[100], n, i, d, swap;
	
	printf("Masukan jumlah elemen didalam array: \n");
	scanf("%d", &n);
	
	printf("Masukan %d bilanagan integer\n", n);
	
	for (i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	merge_sort(0, n - 1, a, aux);
	printf("Menampilkan array yang telah diurutkan:\n");
	
	for (i = 0; i < n; i++){
		printf("%d\n", a[i]);
	}
	return 0;
}