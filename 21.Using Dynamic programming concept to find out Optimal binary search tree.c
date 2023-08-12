#include <stdio.h>
#include <limits.h>

#define MAX_KEYS 10

int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

int optimalBSTCost(int keys[], int freq[], int n) {
    int dp[MAX_KEYS][MAX_KEYS];

    for (int i = 0; i < n; i++) {
        dp[i][i] = freq[i];
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                int cost = ((r > i) ? dp[i][r - 1] : 0) + ((r < j) ? dp[r + 1][j] : 0) + sum(freq, i, j);
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[MAX_KEYS], freq[MAX_KEYS];
    printf("Enter the keys and their frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &keys[i], &freq[i]);
    }

    int cost = optimalBSTCost(keys, freq, n);
    printf("Optimal BST cost: %d\n", cost);

    return 0;
}
