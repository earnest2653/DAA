#include <stdio.h>
#include <stdbool.h>

#define V 4 // Number of vertices
#define COLORS 3 // Number of colors

int graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

int color[V];

bool isSafe(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int v) {
    if (v == V) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= COLORS; c++) {
        if (isSafe(v, c)) {
            color[v] = c;

            if (graphColoringUtil(v + 1)) {
                return true;
            }

            color[v] = 0; // Backtrack if no solution found
        }
    }

    return false; // No valid coloring found
}

void graphColoring() {
    if (!graphColoringUtil(0)) {
        printf("Solution does not exist.\n");
        return;
    }

    printf("Graph coloring solution:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Color %d\n", i, color[i]);
    }
}

int main() {
    graphColoring();

    return 0;
}
