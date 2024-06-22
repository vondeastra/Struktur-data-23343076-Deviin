/* 	Nama : Muhammad Devin Rahadi
	NNIM : 23343076
	Percobaan : percobaan 2 merge sort - before and after
*/

#include <stdio.h>
#define MAX 10

int a[11] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0};
int b[10];

void merging(int low, int mid, int high) {
	int 11, 12, i;
	for(11 = low, 12 = mid +1, i = low; 11 <= mid && 12 <= high; i++) {
		if(a[11] <= a[12]){
			b[i] = a [11++];
		} else {
			b[i] = a[12++];
		}
	}
	while(11 <= mid) {
		b[i++] = a[11++];
	}
	while(12 <= high){
		b[i++] = a[12++];
	}
	for(i = low; i <= high; i++){
		a[i] = b[i];
	}
}

void sort(int low, int high) {
	int mid;
	
	if(low < high){
		mid = (low + high) / 2;
		sort(low, mid);
		sort(mid+1, high);
		merging(low, mid, high);
	} else {
		return;
	}
}

int main(){
	int i;
	printf("Data sebelum diurut\n");
	for(i = 0; i <= max; i++){
		printf("%d", a[i]);
	} 
	sort(0, max);
	printf("\nData setelah diurut\n");
	for(i = o; i <= max; i++){
		printf("%d", a[i]);
	}
}