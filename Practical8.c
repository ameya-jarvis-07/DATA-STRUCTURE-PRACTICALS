#include <stdio.h>
#include <stdbool.h>
#define MAX 5
int front = -1, rear = -1;
int arr[MAX];
bool isFull();
bool isEmpty();
void enqueue(int arr[], int val);
int dequeue(int arr[]);
int peek(int arr[]);
void display(int arr[]);
bool isFull() {
    return rear == MAX - 1;
}
bool isEmpty() {
    return front == -1 || front > rear;
}
void enqueue(int arr[], int val) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0; // Initialize front on first enqueue
    arr[++rear] = val;
    printf("Enqueued: %d\n", val);
}
int dequeue(int arr[]) {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int temp = arr[front++];
    printf("Dequeued: %d\n", temp);
    return temp;
}
int peek(int arr[]) {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    return arr[front];
}
void display(int arr[]) {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    enqueue(arr, 10);
    enqueue(arr, 20);
    enqueue(arr, 30);
    display(arr);
    printf("Front element: %d\n", peek(arr));
    dequeue(arr);
    display(arr);
    return 0;
}
