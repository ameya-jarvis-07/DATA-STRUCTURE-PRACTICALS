#include <stdio.h>
#include <stdbool.h>
#define MAX 5

int top = -1;
int arr[MAX];

bool isFull();
bool isEmpty();
void push(int arr[], int val);
int pop(int arr[]);
int peek(int arr[]);
void display(int arr[]);

bool isFull() {
    return top == MAX - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(int arr[], int val) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    arr[++top] = val;
    printf("Pushed: %d\n", val);
}

int pop(int arr[]) {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    int temp = arr[top--];
    printf("Popped: %d\n", temp);
    return temp;
}

int peek(int arr[]) {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return arr[top];
}

void display(int arr[]) {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    printf("----- Stack Menu -----\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(arr, value);
                break;
            case 2:
                pop(arr);
                break;
            case 3:
                value = peek(arr);
                if (value != -1)
                    printf("Top element is: %d\n", value);
                break;
            case 4:
                display(arr);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}