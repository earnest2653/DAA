#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 4 // Number of workers/tasks

int cost[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

bool rowVisited[N] = {false};
bool colVisited[N] = {false};

int assignment[N];

int minCost = INT_MAX;

void updateMinCost() {
    int totalCost = 0;
    for (int i = 0; i < N; i++) {
        totalCost += cost[i][assignment[i]];
    }
    if (totalCost < minCost) {
        minCost = totalCost;
    }
}

void solveAssignment(int row, int currentCost) {
    if (row == N) {
        updateMinCost();
        return;
    }

    for (int col = 0; col < N; col++) {
        if (!rowVisited[row] && !colVisited[col]) {
            rowVisited[row] = true;
            colVisited[col] = true;
            assignment[row] = col;
            solveAssignment(row + 1, currentCost + cost[row][col]);
            rowVisited[row] = false;
            colVisited[col] = false;
        }
    }
}

int main() {
    solveAssignment(0, 0);

    printf("Minimum cost for the Assignment Problem: %d\n", minCost);

    return 0;
}
