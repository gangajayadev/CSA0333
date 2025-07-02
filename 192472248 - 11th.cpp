#include <stdio.h>
#define SIZE 100
int stack[SIZE];
int top = -1;
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (bottom to top): [");
    for (int i = 0; i <= top; i++) {
        printf("%d", stack[i]);
        if (i != top) printf(", ");
    }
    printf("]\n");
}
void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow.\n");
    } else {
        top++;
        stack[top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow.\n");
    } else {
        printf("Popped %d from the stack.\n", stack[top]);
        top--;
    }
}
void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}
int main() {
    int n, value, choice;
    printf("Enter number of elements to initialize the stack: ");
    scanf("%d", &n);
    if (n > SIZE) {
        printf("Exceeded maximum stack size (%d).\n", SIZE);
        return 1;
    }
    printf("Enter %d elements (bottom to top):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &stack[i]);
    }
    top = n - 1;
    display();
    while (1) {
        printf("\n1. Push  2. Pop  3. Peek  4. Display  5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                display();
                break;
            case 2:
                pop();
                display();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
