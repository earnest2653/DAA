#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int n; // Number of cities
int dist[MAX_CITIES][MAX_CITIES]; // Distance matrix

int dp[MAX_CITIES][1 << MAX_CITIES]; // DP table for memoization

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // Return to starting city
    }

    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int minCost = INT_MAX;
    for (int city = 0; city < n; city++) {
        if (!(mask & (1 << city))) {
            int newCost = dist[pos][city] + tsp(mask | (1 << city), city);
            if (newCost < minCost) {
                minCost = newCost;
            }
        }
    }

    return dp[pos][mask] = minCost;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }

    int minCost = tsp(1, 0); // Start from city 0

    printf("Minimum cost for the Traveling Salesman Problem: %d\n", minCost);

    return 0;
}
