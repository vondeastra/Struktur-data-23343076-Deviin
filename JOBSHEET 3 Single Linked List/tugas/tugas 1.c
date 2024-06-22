/*
	Nama : Muhammad Devin Rahadi
	NIM : 23343076
	Prodi : Informatika
*/
#include <stdio.h>
#include <stdlib.h>

// Struktur untuk simpul dalam linked list
struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk menambahkan simpul baru ke linked list
void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Fungsi untuk menghasilkan bilangan Fibonacci hingga ke-n
struct Node* generate_fibonacci(int n) {
    struct Node* head = NULL;

    // Inisialisasi dua bilangan Fibonacci pertama
    int a = 0, b = 1;

    // Menghitung bilangan Fibonacci hingga ke-n
    for (int i = 0; i < n; i++) {
        insert(&head, a);
        int temp = a;
        a = b;
        b = temp + b;
    }

    return head;
}

// Fungsi untuk mencetak linked list
void print_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
// Fungsi untuk membebaskan memori linked list
void free_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
	
    int n;
    
    printf("Nama : Muhammad Devin Rahadi\n");
    printf("NIM  : 23343076\n\n");
    

    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Masukkan bilangan non-negatif.\n");
        return 1;
    }

    // Memanggil fungsi untuk menghasilkan bilangan Fibonacci
    struct Node* fibonacci_list = generate_fibonacci(n);

    printf("Bilangan Fibonacci pertama hingga ke-%d adalah:\n", n);
    print_list(fibonacci_list);

    // Membebaskan memori yang dialokasikan
    free_list(fibonacci_list);

    return 0;
}

