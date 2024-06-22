/* 	Nama : MUHAMMAD DEVIN RAHADI
	NIM : 23343076
	PRODI : INFORMATIKA
	KELAS : 202323430157, SELASA 08:50 - 10:30
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Struktur untuk queue
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Fungsi untuk membuat queue baru
Queue* buatQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Fungsi untuk mengecek apakah queue kosong
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Fungsi untuk menambah elemen ke dalam queue
void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue penuh!\n");
        return;
    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Fungsi untuk menghapus elemen dari queue
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue kosong!\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Fungsi untuk BFS
void BFS(int adjMatrix[MAX][MAX], int startVertex, int numVertices) {
    Queue* q = buatQueue();
    int visited[MAX] = {0};

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    printf("Hasil BFS: ");

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int numVertices = 6;
    int adjMatrix[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0}
    };

    BFS(adjMatrix, 0, numVertices);

    return 0;
}
