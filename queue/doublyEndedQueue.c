#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the Deque
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Global pointers for the front and rear of the Deque
struct Node *front = NULL;
struct Node *rear = NULL;

// Function to display the Deque
void displayDeque() {
    if (front == NULL) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    struct Node *temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert an element at the front
void insertFront(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;

    if (front == NULL) { // If the Deque is empty
        front = rear = newNode;
    } else {
        front->prev = newNode;
        front = newNode;
    }
    printf("%d inserted at the front.\n", value);
}

// Function to insert an element at the rear
void insertRear(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear == NULL) { // If the Deque is empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted at the rear.\n", value);
}

// Function to delete an element from the front
void deleteFront() {
    if (front == NULL) {
        printf("Deque is empty. Nothing to delete from the front.\n");
        return;
    }

    struct Node *temp = front;
    printf("%d deleted from the front.\n", front->data);

    if (front == rear) { // If there's only one element
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }
    free(temp);
}

// Function to delete an element from the rear
void deleteRear() {
    if (rear == NULL) {
        printf("Deque is empty. Nothing to delete from the rear.\n");
        return;
    }

    struct Node *temp = rear;
    printf("%d deleted from the rear.\n", rear->data);

    if (front == rear) { // If there's only one element
        front = rear = NULL;
    } else {
        rear = rear->prev;
        rear->next = NULL;
    }
    free(temp);
}

// Main function to demonstrate the operations
int main() {
    insertFront(10);
    insertRear(20);
    insertFront(5);
    insertRear(25);
    displayDeque();

    deleteFront();
    displayDeque();

    deleteRear();
    displayDeque();

    deleteRear();
    deleteFront();
    displayDeque(); // Should show "Deque is empty."

    return 0;
}
