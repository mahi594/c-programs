#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
struct Node* insertAtEnd(struct Node* currentHead, int newData) {
    struct Node* newNode = createNode(newData);

    // If the list is empty, the new node becomes the head
    if (currentHead == NULL) {
        return newNode;
    }

    // Traverse to the last node
    struct Node* temp = currentHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Set the next of the last node to the new node
    temp->next = newNode;

    return currentHead;  // Return the unchanged head
}

// Function to delete a node from the end of the linked list
struct Node* deleteFromEnd(struct Node* currentHead) {
    // Underflow check: If the list is empty
    if (currentHead == NULL) {
        printf("Error: Underflow! The list is empty.\n");
        return NULL;
    }

    // If there is only one node in the list
    if (currentHead->next == NULL) {
        free(currentHead);
        return NULL;  // List becomes empty
    }

    // Traverse to the second-to-last node
    struct Node* temp = currentHead;
    struct Node* prev = NULL;  // Track the previous node

    while (temp->next != NULL) {
        prev = temp;   // Store the current node before moving forward
        temp = temp->next;
    }

    // Free the last node
    free(temp);

    // Set the next of the second-to-last node to NULL
    prev->next = NULL;

    return currentHead;  // Return the unchanged head
}

// Function to print the linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;  // Initialize an empty list

    // Insert elements at the end
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    // Print the updated linked list
    printf("Linked list after insertion: \n");
    printList(head);

    // Delete elements from the end
    head = deleteFromEnd(head);  // Deletes 30
    head = deleteFromEnd(head);  // Deletes 20
    head = deleteFromEnd(head);  // Deletes 10
    head = deleteFromEnd(head);  // Underflow case

    // Print the final linked list after deletion
    printf("Linked list after deletion: \n");
    printList(head);

    return 0;
}
