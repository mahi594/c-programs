#include <stdio.h>
#include <stdlib.h>

#define maxSize 101
int a[maxSize];
int front = 0;  // Index of the front element
int rear = -1;  // Index of the rear element
int currentSize = 0;

int isEmpty() {
    return currentSize == 0;
}

int isFull() {
    return currentSize == maxSize;
}

int size() {
    return currentSize;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    rear = (rear + 1) % maxSize; // Circular increment
    a[rear] = item;
    currentSize++;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value or throw an exception
    }
    int removedItem = a[front];
    front = (front + 1) % maxSize; // Circular increment
    currentSize--;
    return removedItem;
}

int main() {
    int n = 10; // Number of elements to process

    // Enqueue the first element (1)
    enqueue(1);

    // Process numbers up to N
    for (int i = 2; i <= n; i++) {
        // Dequeue and print the front element (alternating print and enqueue)
        int toPrint = dequeue();
        // printf("%d ", toPrint);

        // Enqueue the next number
        enqueue(i);
        printf("%d ", toPrint);
    }

    // Dequeue and print remaining numbers in the queue
    while (!isEmpty()) {
        printf("%d ", dequeue());
    }

    return 0;
}
