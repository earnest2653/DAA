#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    double ratioA = ((struct Item *)a)->value / (double)((struct Item *)a)->weight;
    double ratioB = ((struct Item *)b)->value / (double)((struct Item *)b)->weight;

    if (ratioA > ratioB) {
        return -1;
    } else if (ratioA < ratioB) {
        return 1;
    } else {
        return 0;
    }
}

double knapsackGreedy(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += (remainingWeight / (double)items[i].weight) * items[i].value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    double maxValue = knapsackGreedy(capacity, items, n);

    printf("Maximum value using greedy approach: %.2lf\n", maxValue);

    return 0;
}
