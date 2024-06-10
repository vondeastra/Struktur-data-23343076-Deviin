/* 	Nama : MUHAMMAD DEVIN RAHADI
	NIM : 23343076
	PRODI : INFORMATIKA
	KELAS : 202323430157, SELASA 08:50 - 10:30
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if(top == MAX-1) {
        printf("Stack penuh!!");
    } else {
        top = top + 1;
        stack[top] = c;
    }
}

char pop() {
    if(top == -1) {
        printf("Stack kosong!!");
        return '\0';
    } else {
        return stack[top--];
    }
}

void display() {
    int i;
    for(i=top; i>=0; --i) {
        printf("%c", stack[i]);
    }
    printf("\n");
}

int main() {
    char word[MAX];
    int ch;

    while(1) {
        printf("\n** Menu Stack **");
        printf("\n\n1. Input Kata\n2. Balik Kata\n3. Exit");
        printf("\n\n Masukan pilihanmu (1-3): ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Masukkan kata: ");
                scanf("%s", word);
                for(int i=0; i<strlen(word); i++) {
                    push(word[i]);
                }
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("\nPilihan tidak valid!");
        }
    }

    return 0;
}