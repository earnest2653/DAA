#include <stdio.h>
#include <stdbool.h>

void printSubset(int subset[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

void subsetSumBacktracking(int set[], int subset[], int n, int subsetSize, int sum, int targetSum, int currentIndex) {
    if (sum == targetSum) {
        printSubset(subset, subsetSize);
        return;
    }

    if (currentIndex == n || sum + set[currentIndex] > targetSum) {
        return;
    }

    subset[subsetSize] = set[currentIndex];

    subsetSumBacktracking(set, subset, n, subsetSize + 1, sum + set[currentIndex], targetSum, currentIndex + 1);

    subsetSumBacktracking(set, subset, n, subsetSize, sum, targetSum, currentIndex + 1);
}

void findSubsetsWithSum(int set[], int n, int targetSum) {
    int subset[n];
    subsetSumBacktracking(set, subset, n, 0, 0, targetSum, 0);
}

int main() {
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int set[n];
    
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    
    int targetSum;
    
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);
    
    findSubsetsWithSum(set, n, targetSum);
    
    return 0;
}
