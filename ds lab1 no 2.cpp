#include <stdio.h>

#define MAX_ELEMENTS 100

void inputSet(int set[], int *size) {
    printf("Enter the number of elements in the set: ");
    scanf("%d", size);
    printf("Enter the elements of the set (space-separated): ");
    for (int i = 0; i < *size; i++) {
        scanf("%d", &set[i]);
    }
}

void cartesianProduct(int sets[][MAX_ELEMENTS], int sizes[], int numSets) {
    int product[MAX_ELEMENTS][MAX_ELEMENTS];
    int productSize = 1;
    for (int i = 0; i < numSets; i++) {
        productSize *= sizes[i];
    }
    for (int i = 0; i < productSize; i++) {
        int temp = i;
        for (int j = 0; j < numSets; j++) {
            product[i][j] = sets[j][temp % sizes[j]];
            temp /= sizes[j];
        }
    }
    printf("Cartesian Product:\n");
    for (int i = 0; i < productSize; i++) {
        printf("{ ");
        for (int j = 0; j < numSets; j++) {
            printf("%d ", product[i][j]);
        }
        printf("}\n");
    }
}

int main() {
    int numSets;
    printf("Enter the number of sets (2 or more): ");
    scanf("%d", &numSets);
    if (numSets < 2) {
        printf("At least two sets are required.\n");
        return 1;
    }
    int sets[MAX_ELEMENTS][MAX_ELEMENTS];
    int sizes[MAX_ELEMENTS];
    for (int i = 0; i < numSets; i++) {
        inputSet(sets[i], &sizes[i]);
    }
    cartesianProduct(sets, sizes, numSets);
    return 0;
}

