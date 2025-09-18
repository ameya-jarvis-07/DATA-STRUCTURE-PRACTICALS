#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int size = 0;

void createArray() {
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size.\n");
        size = 0;
        return;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void displayArray() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to search for an element
void searchElement() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    int value, found = 0;
    printf("Enter the element to search: ");
    scanf("%d", &value);

    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("Element %d found at index %d.\n", value, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", value);
    }
}

void deleteByIndex() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    int index;
    printf("Enter the index to delete (0 to %d): ", size - 1);
    scanf("%d", &index);

    if (index < 0 || index >= size) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Element at index %d deleted.\n", index);
}


void insertAtStart() {
    if (size >= MAX_SIZE) {
        printf("Array is full. Delete some elements before inserting.\n");
        return;
    }

    int value;
    printf("Enter the element to insert at start: ");
    scanf("%d", &value);

    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    size++;
    printf("Element %d inserted at the beginning.\n", value);
}

void insertAtEnd() {
    if (size >= MAX_SIZE) {
        printf("Array is full. Delete some elements before inserting.\n");
        return;
    }

    int value;
    printf("Enter the element to insert at end: ");
    scanf("%d", &value);

    arr[size] = value;
    size++;
    printf("Element %d inserted at the end.\n", value);
}

void deleteByElement() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    int value, found = 0;
    printf("Enter the element to delete: ");
    scanf("%d", &value);

    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            found = 1;
            printf("Element %d deleted.\n", value);
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", value);
    }
}
void insertAtIndex() {
    if (size >= MAX_SIZE) {
        printf("Array is full.\n");
        return;
    }

    int index, value;
    printf("Enter index 0 to %d:\n", size);
    scanf("%d", &index);

    if (index < 0 || index > size) {
        printf("Invalid index.\n"); 
        return;
    }

    printf("Enter the Element to insert: ");
    scanf("%d", &value);

    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    size++;

    printf("Element %d is inserted at index %d\n", value, index);
}


int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Search Element\n");          
        printf("4. Delete by Index\n");
        printf("5. Insert at Start\n");
        printf("6. Insert at End\n");
        printf("7. Delete by Element\n");  
        printf("8. Insert At Index\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createArray();
                break;
            case 2:
                displayArray();
                break;
            case 3:
                searchElement();  
                break;
            case 4:
                deleteByIndex();
                break;
            case 5:
                insertAtStart();
                break;
            case 6:
                insertAtEnd();
                break;
            case 7:
                deleteByElement();  
                break;
            case 8:
                insertAtIndex();
                break;
            case 9:
                printf("Exiting program.\n");
                return 0;
            
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}