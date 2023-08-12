#include <stdio.h>

void insertNumber(int list[], int *size, int number, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position to insert.\n");
        return;
    }

    // Shift elements to the right to make space for the new number
    for (int i = *size; i > position; i--) {
        list[i] = list[i - 1];
    }

    // Insert the new number at the specified position
    list[position] = number;

    (*size)++;
}

int main() {
    int list[100]; // Assuming a list of size 100
    int size = 0;
    int number, position;

    printf("Enter the number to insert: ");
    scanf("%d", &number);

    printf("Enter the position to insert at: ");
    scanf("%d", &position);

    printf("Enter the initial size of the list: ");
    scanf("%d", &size);

    printf("Enter %d elements of the list:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    insertNumber(list, &size, number, position);

    printf("List after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}
