/*
  nama : muhammad devin rahadi
  NIM : 23343076
  kasus : array percobaan 1
*/
#include<stdio.h>

int main(){
	int nil[3];
	int rr;
	
	nil[0] = 80;
	nil[1] = 90;
	nil[2] = 80;
	
	rr = (nil[0] + nil[1] + nil[2]) / 3;
	printf("The average of the 3 grades is: %d", rr);
	
	return 0;
}