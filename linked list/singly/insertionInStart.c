#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int newData) {
    // Step 1: Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Overflow check: If memory allocation fails
    if (newNode == NULL) {
        printf("Error: Overflow! Unable to allocate memory for a new node.\n");
        return NULL;
    }
    
    // Step 2: Assign the data to the node
    newNode->data = newData;
    
    // Step 3: Set the next pointer to NULL
    newNode->next = NULL;
    
    return newNode;  // Return the pointer to the new node
}

// Function to insert a new node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* currentHead, int newData) {
    // Create a new node with the given data
    struct Node* newNode = createNode(newData);
    
    // Overflow case: If node creation failed
    if (newNode == NULL) {
        return currentHead;  // No changes made to the list
    }
    
    // Set the new node's next pointer to the current head
    newNode->next = currentHead;
    
    // Return the new node as the new head of the list
    return newNode;
}

// Function to delete a node from the beginning of the linked list (for underflow check)
struct Node* deleteFromBeginning(struct Node* currentHead) {
    // Underflow check: If the list is empty
    if (currentHead == NULL) {
        printf("Error: Underflow! The list is empty.\n");
        return NULL;
    }
    
    // Store the node to be deleted
    struct Node* temp = currentHead;
    
    // Move the head to the next node
    currentHead = currentHead->next;
    
    // Free the old head node
    free(temp);
    
    return currentHead;  // Return the new head of the list
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

    // Insert elements at the beginning
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);

    // Print the updated linked list
    printf("Linked list after insertion: \n");
    printList(head);

    // Delete elements from the beginning
    head = deleteFromBeginning(head);  // Deletes 30
    head = deleteFromBeginning(head);  // Deletes 20
    head = deleteFromBeginning(head);  // Deletes 10
    head = deleteFromBeginning(head);  // Underflow case

    // Print the final linked list after deletion
    printf("Linked list after deletion: \n");
    printList(head);

    return 0;
}
