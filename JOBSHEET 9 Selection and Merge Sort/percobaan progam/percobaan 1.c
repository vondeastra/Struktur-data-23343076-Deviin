/* 	Nama : Muhammad Devin Rahadi
	NNIM : 23343076
	Percobaan : percobaan 1 merge sort
*/

#include <stdio.h> 
#include <stdlib.h> 
#define max 10000 
 
void input(); 
void tukar(int *, int *); 
void tampil(); 
void partisi(int data[],int low,int high); 
void mergesort(int data[],int low,int mid,int high); 
int data[max],hasil[max]; 
int n; 
 
int main() 
{ 
 input(); 
 int awal=0, akhir=n-1; 
        partisi(data,awal,akhir); 
 tampil(); 
} 
//fungsi input 
void input() 
{ 
 int i; 
 printf("Masukkan jumlah total elemen: "); 
    scanf("%d",&n); 
 
    puts(" "); 
    for(i=0;i<n;i++) 
 { 
  data[i]=rand(); 
  printf("%d\t",data[i]); 
  //printf("Elemen ke-%d: ",i+1); 
        //scanf("%d",&data[i]); 
    } 
} 

void partisi(int data[], int low, int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		partisi(data,low,mid);
		partisi(data,mid+1, high);
		margesort(data,low,mid,high);
	}
}

void mergesort(int data[], int low, int mid, int high){
	int i,m,k,l,temp[max];
	l=low;
	i=low;
	m=mid+1;
	while((l<=mid) && (m<=high)){
		if(data[l]<=data[m]){
			temp[i]=data[l];
			l++
		} else {
			temp[i]=data[m];
			m++
		}
		i++
	}
	if(l>mid){
		for(k=m;k<=high;k++){
			temp[i]=data[k];
			i++;
		}
	} else {
		for(k=l; k<=mid; k++){
			temp[i]=data[k];
			i++;
		}
	}
	for(k=low; k<=high; k++){
		f
	}
}