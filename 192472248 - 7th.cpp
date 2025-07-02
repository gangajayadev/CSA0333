#include <stdio.h>
void display(int arr[], int n) {
    int i;
    printf("Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void insertElement(int arr[], int *n, int pos, int val) {
    int i;
    for (i = *n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    (*n)++;
    printf("Element inserted.\n");
    display(arr, *n);
}
void deleteElement(int arr[], int *n, int pos) {
    int i;
    for (i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
    printf("Element deleted.\n");
    display(arr, *n);
}
int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;
    int choice, pos, val;
    while (1) {
        printf("\n1. Insert  2. Delete  3. Display  4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter position (0 to %d): ", n);
            scanf("%d", &pos);
            if (pos < 0 || pos > n) {
                printf("Invalid position.\n");
                continue;
            }
            printf("Enter value: ");
            scanf("%d", &val);
            insertElement(arr, &n, pos, val);
        }
        else if (choice == 2) {
            printf("Enter position (0 to %d): ", n - 1);
            scanf("%d", &pos);
            if (pos < 0 || pos >= n) {
                printf("Invalid position.\n");
                continue;
            }
            deleteElement(arr, &n, pos);
        }
        else if (choice == 3) {
            display(arr, n);
        }
        else if (choice == 4) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
