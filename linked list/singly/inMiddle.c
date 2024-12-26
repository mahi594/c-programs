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

// Function to insert a node in the middle of the linked list
struct Node* insertInMiddle(struct Node* head, int position, int newData) {
    struct Node* newNode = createNode(newData);

    // If the list is empty or inserting at the first position
    if (head == NULL || position == 1) {
        newNode->next = head;
        return newNode;  // The new node becomes the head
    }

    // Traverse the list to find the node just before the position
    struct Node* temp = head;
    int count = 1;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    // If position is greater than the number of nodes
    if (temp == NULL) {
        printf("Position is out of bounds.\n");
        return head;
    }

    // Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;

    return head;  // Return the unchanged head
}

// Function to delete a node from the middle of the linked list
struct Node* deleteFromMiddle(struct Node* head, int position) {
    // Underflow check: If the list is empty
    if (head == NULL) {
        printf("Error: Underflow! The list is empty.\n");
        return NULL;
    }

    // If deleting the first node
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;  // Move the head to the next node
        free(temp);  // Free the old head
        return head;
    }

    // Traverse the list to find the node just before the position
    struct Node* temp = head;
    int count = 1;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    // If the position is invalid (greater than the number of nodes)
    if (temp == NULL || temp->next == NULL) {
        printf("Position is out of bounds.\n");
        return head;
    }

    // Delete the node at the position
    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);

    return head;
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

    // Insert nodes at various positions
    head = insertInMiddle(head, 1, 10);  // Insert 10 at position 1
    head = insertInMiddle(head, 2, 20);  // Insert 20 at position 2
    head = insertInMiddle(head, 3, 30);  // Insert 30 at position 3
    head = insertInMiddle(head, 2, 15);  // Insert 15 at position 2

    // Print the linked list
    printf("Linked list after insertion: \n");
    printList(head);

    // Delete a node from the middle (position 2)
    head = deleteFromMiddle(head, 2);  // Deletes 15

    // Print the updated linked list
    printf("Linked list after deletion: \n");
    printList(head);

    return 0;
}
