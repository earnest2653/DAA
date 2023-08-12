#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index where the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    int arr[] = {12, 45, 67, 89, 34, 78, 23, 56};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int target;

    printf("Enter the number to search for: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("%d found at index %d\n", target, result);
    } else {
        printf("%d not found in the array\n", target);
    }

    return 0;
}
