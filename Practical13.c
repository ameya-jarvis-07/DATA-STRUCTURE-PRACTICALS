#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning.\n", data);
}
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", data);
}
void deleteByValue(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", value);
        return;
    }
    if (prev == NULL) {
        head = temp->next; // Deleting the head node
    } else {
        prev->next = temp->next; // Bypass the node to be deleted
    }
    free(temp);
    printf("Element %d deleted from the list.\n", value);
}
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void deleteByIndex() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int index;
    printf("Enter the index to delete: ");
    scanf("%d", &index);
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (index == 0) {
        head = temp->next; // Deleting the head node
        free(temp);
        printf("Element at index %d deleted.\n", index);
        return;
    }
    for (int i = 0; temp != NULL && i < index; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Index %d out of bounds.\n", index);
        return;
    }
    prev->next = temp->next; // Bypass the node to be deleted
    free(temp);
    printf("Element at index %d deleted.\n", index);
}
int main() {
    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete by Value\n");
        printf("4. Delete by Index\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;
            case 4:
                deleteByIndex();
                break;
            case 5:
                displayList();
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}