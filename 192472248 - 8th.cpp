#include <stdio.h>
int main() {
    int arr[100], n, i, key, found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter number to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Number found at position %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Number not found in the array.\n");
    return 0;
}
