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
    return (rear + 1) % MAX == front;
}
bool isEmpty() {
    return front == -1;
}
void enqueue(int arr[], int val) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty()) front = 0; // Initialize front on first enqueue
    rear = (rear + 1) % MAX;
    arr[rear] = val;
    printf("Enqueued: %d\n", val);
}
int dequeue(int arr[]) {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int temp = arr[front];
    if (front == rear) {
        front = rear = -1; // Queue is now empty
    } else {
        front = (front + 1) % MAX;
    }
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
    int i = front;
    while (true) {
        printf("%d ", arr[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(arr, value);
                break;
            case 2:
                dequeue(arr);
                break;
            case 3:
                value = peek(arr);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 4:
                display(arr);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}