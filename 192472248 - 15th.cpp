#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}
int hash(int key) {
    return key % SIZE;
}
void insert(int key) {
    int index = hash(key);
    int start = index;
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == start) {
            printf("Hash table is full\n");
            return;
        }
    }
    hashTable[index] = key;
}
int search(int key) {
    int index = hash(key);
    int start = index;
    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return index;
        index = (index + 1) % SIZE;
        if (index == start)
            break;
    }
    return -1;
}
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d --> %d\n", i, hashTable[i]);
}
int main() {
    init();
    int choice, key;
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            }
            case 2: {
                printf("Enter key to search: ");
                scanf("%d", &key);
                int index = search(key);
                if (index != -1)
                    printf("Key found at index %d\n", index);
                else
                    printf("Key not found\n");
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                return 0;
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }
}
