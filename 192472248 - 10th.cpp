#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
} *head = NULL;
void insert(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else {
        struct Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d successfully.\n", val);
}
void deleteNode(int val) {
    struct Node *temp = head, *prev = NULL;

    while (temp && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("Value %d not found in the list.\n", val);
        return;
    }
    if (!prev)
        head = head->next;
    else
        prev->next = temp->next;
    free(temp);
    printf("Deleted %d successfully.\n", val);
}
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Array: []\n");
        return;
    }
    printf("Array: [");
    while (temp) {
        printf("%d", temp->data);
        if (temp->next) printf(", ");
        temp = temp->next;
    }
    printf("]\n");
}
int main() {
    int arr[] = {10, 20, 30}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int ch, val;
    for (int i = 0; i < n; i++)
        insert(arr[i]);
    printf("\nInitial Linked List:\n");
    display();
    while (1) {
        printf("\n1. Insert  2. Delete  3. Display  4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                display();
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(val);
                display();
                break;
            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
