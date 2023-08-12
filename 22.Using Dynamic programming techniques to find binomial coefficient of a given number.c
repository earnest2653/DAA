#include <stdio.h>

int binomialCoeff(int n, int r) {
    int dp[n + 1][r + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= (i < r ? i : r); j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][r];
}

int main() {
    int n, r;

    printf("Enter the values of n and r (n choose r): ");
    scanf("%d %d", &n, &r);

    int result = binomialCoeff(n, r);
    printf("The binomial coefficient C(%d, %d) is: %d\n", n, r, result);

    return 0;
}
