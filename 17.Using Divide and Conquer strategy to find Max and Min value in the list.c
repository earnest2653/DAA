#include <stdio.h>

struct MinMax {
    int min;
    int max;
};

struct MinMax findMinMax(int arr[], int left, int right) {
    struct MinMax result, leftResult, rightResult;

    // If only one element
    if (left == right) {
        result.min = arr[left];
        result.max = arr[right];
        return result;
    }

    // If two elements
    if (right - left == 1) {
        if (arr[left] < arr[right]) {
            result.min = arr[left];
            result.max = arr[right];
        } else {
            result.min = arr[right];
            result.max = arr[left];
        }
        return result;
    }

    // Divide the array and recursively find min and max
    int middle = (left + right) / 2;
    leftResult = findMinMax(arr, left, middle);
    rightResult = findMinMax(arr, middle + 1, right);

    // Combine the results
    if (leftResult.min < rightResult.min) {
        result.min = leftResult.min;
    } else {
        result.min = rightResult.min;
    }

    if (leftResult.max > rightResult.max) {
        result.max = leftResult.max;
    } else {
        result.max = rightResult.max;
    }

    return result;
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct MinMax result = findMinMax(arr, 0, n - 1);

    printf("Minimum value: %d\n", result.min);
    printf("Maximum value: %d\n", result.max);

    return 0;
}
