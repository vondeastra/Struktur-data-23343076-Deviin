/*
	nama : Muhammad Devin Rahadi
	NIM : 23343076
	kasus : pointer percobaan 14
*/

#include<stdio.h>
#include<conio.h>

int main(){
	int usia1 = 50;
	int usia2 = 18;
	
	int *ptr;
	
	ptr = &usia1;
	
	printf("\n Usia saya (usia1): %d\n", usia1);
	printf("\n Usia saya (*ptr): %d", *ptr);
	printf("\n (&usia1) %x (ptr) %x", &usia1, ptr);
	
	ptr = &usia2;
	
	printf("\n Usia anda (*ptr): %d", *ptr);
	printf("\n (&usia2) %x (ptr) %x", &usia2, ptr);
	printf("\n (&ptr) %x", &ptr);
	
	getch();
}