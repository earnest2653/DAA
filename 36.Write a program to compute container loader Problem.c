#include <stdio.h>
#include <stdbool.h>

#define NUM_CONTAINERS 5
#define CONTAINER_CAPACITY 10

void firstFitDecreasing(int items[], int numItems) {
    int containers[NUM_CONTAINERS][NUM_CONTAINERS] = {0};
    int containerCount = 0;

    for (int i = 0; i < numItems; i++) {
        int itemSize = items[i];
        bool itemPlaced = false;

        for (int j = 0; j < containerCount; j++) {
            int remainingCapacity = CONTAINER_CAPACITY;

            for (int k = 0; k < j; k++) {
                remainingCapacity -= containers[j][k];
            }

            if (remainingCapacity >= itemSize) {
                containers[j][j] = itemSize;
                itemPlaced = true;
                break;
            }
        }

        if (!itemPlaced) {
            containers[containerCount][containerCount] = itemSize;
            containerCount++;
        }
    }

    printf("Container Loading Solution:\n");
    for (int i = 0; i < containerCount; i++) {
        printf("Container %d: ", i + 1);
        for (int j = 0; j < containerCount; j++) {
            if (containers[i][j] > 0) {
                printf("%d ", containers[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int numItems;
    
    printf("Enter the number of items: ");
    scanf("%d", &numItems);
    
    int items[numItems];
    
    printf("Enter the sizes of the items:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &items[i]);
    }
    
    firstFitDecreasing(items, numItems);
    
    return 0;
}
