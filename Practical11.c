#include <stdio.h> 
#include <stdbool.h>
#define MAX 5
int size = 0;
struct Element {
    int data;
    int priority;
};
struct Element arr[MAX];
bool isFull() {
    return size == MAX;
}
bool isEmpty() {
    return size == 0;
}
void insert(int data, int priority) {
    if (isFull()) {
        printf("Priority Queue Overflow\n");
        return;
    }
    struct Element newElement = {data, priority};
    int i;
    for (i = size - 1; (i >= 0 && arr[i].priority > newElement.priority); i--) {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = newElement;
    size++;
    printf("Inserted: %d with priority %d\n", data, priority);
}
struct Element delete() {
    if (isEmpty()) {
        printf("Priority Queue Underflow\n");
        struct Element empty = {-1, -1};
        return empty;
    }
    return arr[--size];
}
struct Element peek() {
    if (isEmpty()) {
        printf("Priority Queue is empty\n");
        struct Element empty = {-1, -1};
        return empty;
    }
    return arr[size - 1];
}
void display() {
    if (isEmpty()) {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Priority Queue elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Data: %d, Priority: %d\n", arr[i].data, arr[i].priority);
    }
}
int main() {
    insert(10, 2);
    insert(20, 1);
    insert(30, 3);
    display();
    struct Element top = peek();
    if (top.data != -1) {
        printf("Top element: Data: %d, Priority: %d\n", top.data, top.priority);
    }
    struct Element removed = delete();
    if (removed.data != -1) {
        printf("Deleted element: Data: %d, Priority: %d\n", removed.data, removed.priority);
    }
    display();
    return 0;
}

