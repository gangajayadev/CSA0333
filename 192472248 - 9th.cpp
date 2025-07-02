#include <stdio.h>
int main() {
    int arr[100], n, key, low, high, mid, i, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter number to search: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            printf("Number %d found at position %d\n", key, mid);
            found = 1;
            break;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (!found)
        printf("Number %d not found in the array.\n", key);
    return 0;
}
