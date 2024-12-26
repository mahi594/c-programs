#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
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

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int newData) {
    struct Node* newNode = createNode(newData);
    if (head == NULL) {
        return newNode;  // If the list is empty, return the new node as the head
    }

    // Traverse to the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newNode;

    return head;  // Return the unchanged head
}

// Function to search for a value in the linked list
int search(struct Node* head, int value) {
    int position = 1;  // Position starts from 1
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == value) {
            return position;  // Return the position if found
        }
        current = current->next;  // Move to the next node
        position++;
    }

    return -1;  // Return -1 if the value is not found
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
    struct Node* head = NULL;

    // Insert nodes at the end
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    // Print the linked list
    printf("Linked list: \n");
    printList(head);

    // Search for a value
    int valueToSearch = 30;
    int position = search(head, valueToSearch);
    
    if (position != -1) {
        printf("Value %d found at position %d.\n", valueToSearch, position);
    } else {
        printf("Value %d not found in the list.\n", valueToSearch);
    }

    return 0;
}
