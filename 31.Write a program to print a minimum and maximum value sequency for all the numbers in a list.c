#include <stdio.h>
#include <limits.h>

void printMinMaxSequence(int arr[], int n) {
    int minSoFar = INT_MAX;
    int maxSoFar = INT_MIN;

    printf("Minimum-Maximum Sequence:\n");

    for (int i = 0; i < n; i++) {
        minSoFar = (arr[i] < minSoFar) ? arr[i] : minSoFar;
        maxSoFar = (arr[i] > maxSoFar) ? arr[i] : maxSoFar;

        printf("%d %d ", minSoFar, maxSoFar);
    }

    printf("\n");
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

    printMinMaxSequence(arr, n);

    return 0;
}
