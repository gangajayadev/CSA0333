#include <stdio.h>
#define SIZE 100
int queue[SIZE];
int front = -1, rear = -1;
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: [");
    for (int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if (i < rear) printf(", ");
    }
    printf("]\n");
}
void enqueue(int val) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = val;
    printf("Enqueued %d\n", val);
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued %d\n", queue[front++]);
    if (front > rear) front = rear = -1;
}
int main() {
    int n, val, choice;
    printf("Enter number of elements to initialize the queue: ");
    scanf("%d", &n);
    if (n > SIZE) {
        printf("Too many elements. Max allowed is %d.\n", SIZE);
        return 1;
    }
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }
    front = 0;
    rear = n - 1;
    printf("Initial queue:\n");
    display();
    while (1) {
        printf("\n1. Enqueue  2. Dequeue  3. Display  4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
