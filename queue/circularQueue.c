#include <stdio.h>
#include <stdlib.h>

struct circularqueue {
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct circularqueue *q) {
    return (q->r + 1) % q->size == q->f;
}

int isempty(struct circularqueue *q) {
    return q->r == q->f;
}

void circularenqueue(struct circularqueue *q, int value) {
    if (isfull(q)) {
        printf("Queue overflow\n");
    } else {
        printf("enqued element is %d\n",value);
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = value;
    }
}

int circulardequeue(struct circularqueue *q) {
    int a = -1;
    if (isempty(q)) {
        printf("Underflow\n");
    } else {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

// void displayQueue(struct circularqueue *q) {
//     if (isempty(q)) {
//         printf("Queue is empty.\n");
//         return;
//     }
//     printf("Queue elements: ");
//     int i = (q->f + 1) % q->size; // Start from the front
//     while (i != (q->r + 1) % q->size) {
//         printf("%d ", q->arr[i]);
//         i = (i + 1) % q->size; // Move to the next position
//     }
//     printf("\n");
// }

int main() {
    struct circularqueue q;
    q.size = 11; // Increased size by 1 for circular queue logic
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    if (isempty(&q)) {
        printf("Queue is empty\n");
    }

    // Enqueue
    circularenqueue(&q, 11);
    circularenqueue(&q, 12);
    circularenqueue(&q, 14);
    circularenqueue(&q, 13);
    circularenqueue(&q, 15);
    circularenqueue(&q, 16);
    circularenqueue(&q, 17);
    circularenqueue(&q, 18);
    circularenqueue(&q, 19);
    circularenqueue(&q, 20);

   

    printf("Dequeuing element %d\n", circulardequeue(&q));
    printf("Dequeuing element %d\n", circulardequeue(&q));
    printf("Dequeuing element %d\n", circulardequeue(&q));

    circularenqueue(&q, 21);
    

    free(q.arr); // Clean up allocated memory
    return 0;
}
