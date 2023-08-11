#include <stdio.h>
#include <string.h>

void copyString(char dest[], char source[]) {
    int i = 0;
    while (source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
}

int main() {
    char source[100];
    char destination[100];

    printf("Enter a string: ");
    scanf("%s", source);

    copyString(destination, source);

    printf("Copied string: %s\n", destination);

    return 0;
}
