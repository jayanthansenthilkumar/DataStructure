#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Queue structure
typedef struct {
    char data[MAX][100];
    int front;
    int rear;
    int size;
} Queue;

// Initialize the queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Check if the queue is empty
int isEmptyQueue(Queue *q) {
    return q->size == 0;
}

// Check if the queue is full
int isFullQueue(Queue *q) {
    return q->size == MAX;
}

// Enqueue operation
void enqueue(Queue *q, char *message) {
    if (isFullQueue(q)) {
        printf("Queue is full. Cannot enqueue more messages.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    strcpy(q->data[q->rear], message);
    q->size++;
    printf("Message Enqueued: %s\n", message);
}

// Dequeue operation
char *dequeue(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty. Nothing to dequeue.\n");
        return NULL;
    }
    char *message = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    printf("Message Dequeued: %s\n", message);
    return message;
}

// Peek operation
char *peekQueue(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty. Nothing to peek.\n");
        return NULL;
    }
    return q->data[q->front];
}

int main() {
    Queue messageQueue;
    initQueue(&messageQueue);

    int choice;
    char message[100];

    while (1) {
        printf("\n1. Enqueue Message\n2. Dequeue Message\n3. Peek Front Message\n4. Exit\nChoose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character

        switch (choice) {
            case 1:
                printf("Enter message: ");
                fgets(message, 100, stdin);
                message[strcspn(message, "\n")] = 0;  // Remove newline
                enqueue(&messageQueue, message);
                break;

            case 2:
                dequeue(&messageQueue);
                break;

            case 3:
                if (peekQueue(&messageQueue)) {
                    printf("Front Message: %s\n", peekQueue(&messageQueue));
                }
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}