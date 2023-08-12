#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices

int graph[V][V] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int path[V];

bool isSafe(int v, int pos, int path[], int pathIndex) {
    if (!graph[path[pos - 1]][v]) {
        return false;
    }

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

bool hamiltonianCircuitUtil(int path[], int pathIndex) {
    if (pathIndex == V) {
        if (graph[path[pathIndex - 1]][path[0]]) {
            return true;
        } else {
            return false;
        }
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, pathIndex, path, pathIndex)) {
            path[pathIndex] = v;

            if (hamiltonianCircuitUtil(path, pathIndex + 1)) {
                return true;
            }

            path[pathIndex] = -1;
        }
    }

    return false;
}

void hamiltonianCircuit() {
    path[0] = 0;

    if (!hamiltonianCircuitUtil(path, 1)) {
        printf("No Hamiltonian Circuit exists.\n");
        return;
    }

    printf("Hamiltonian Circuit exists:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);
}

int main() {
    hamiltonianCircuit();

    return 0;
}
