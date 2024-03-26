/*
  nama : muhammad devin rahadi
  NIM : 23343076
  kasus : array percobaan 3
*/

#include<stdio.h>

int main(){
	int angka[10];
	int n, i;
	
	printf("Masukkan banyaknya bilangan : ");
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		printf("Masukkan angka ke %d : ", i + 1);
		scanf("%d", &angka[i]);
	}
	
	for(int i = 0; i < n; i++){
		printf("Angka ke %d : %d\n", i + 1, angka[i] );
	}
	
	getchar();
	return 0;
}