#include <stdio.h>

long long binomialCoeff(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

void printPascalTriangle(int numRows) {
    for (int i = 0; i < numRows; i++) {
        // Print leading spaces
        for (int j = 0; j < numRows - i; j++) {
            printf(" ");
        }

        // Print values in the current row
        for (int j = 0; j <= i; j++) {
            printf("%lld ", binomialCoeff(i, j));
        }

        printf("\n");
    }
}

int main() {
    int numRows;

    printf("Enter the number of rows for Pascal's triangle: ");
    scanf("%d", &numRows);

    printPascalTriangle(numRows);

    return 0;
}
