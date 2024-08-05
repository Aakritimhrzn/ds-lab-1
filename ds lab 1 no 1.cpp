#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100

void inputSet(int set[], int *size) {
    printf("Enter the number of elements in the set: ");
    scanf("%d", size);

    printf("Enter the elements of the set (space-separated): ");
    for (int i = 0; i < *size; i++) {
        scanf("%d", &set[i]);
    }
}

void printSet(int set[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("}\n");
}

int isElementInSet(int element, int set[], int size) {
    for (int i = 0; i < size; i++) {
        if (set[i] == element) {
            return 1; 
        }
    }
    return 0; 
}

void unionSets(int sets[][MAX_ELEMENTS], int sizes[], int numSets) {
    int result[MAX_ELEMENTS];
    int resultSize = 0;

    for (int i = 0; i < numSets; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            if (!isElementInSet(sets[i][j], result, resultSize)) {
                result[resultSize++] = sets[i][j];
            }
        }
    }

    printf("Union: ");
    printSet(result, resultSize);
}

void intersectionSets(int sets[][MAX_ELEMENTS], int sizes[], int numSets) {
    int result[MAX_ELEMENTS];
    int resultSize = 0;

    for (int i = 0; i < sizes[0]; i++) {
        int element = sets[0][i];
        int foundInAll = 1;

        for (int j = 1; j < numSets; j++) {
            if (!isElementInSet(element, sets[j], sizes[j])) {
                foundInAll = 0;
                break;
            }
        }

        if (foundInAll) {
            result[resultSize++] = element;
        }
    }

    printf("Intersection: ");
    printSet(result, resultSize);
}

void differenceSets(int sets[][MAX_ELEMENTS], int sizes[]) {
    int result[MAX_ELEMENTS];
    int resultSize = 0;

    for (int i = 0; i < sizes[0]; i++) {
        int element = sets[0][i];
        if (!isElementInSet(element, sets[1], sizes[1])) {
            result[resultSize++] = element;
        }
    }

    printf("Difference (set1 - set2): ");
    printSet(result, resultSize);
}

void symmetricDifferenceSets(int sets[][MAX_ELEMENTS], int sizes[], int numSets) {
    int result[MAX_ELEMENTS];
    int resultSize = 0;

    
    for (int i = 0; i < sizes[0]; i++) {
        if (!isElementInSet(sets[0][i], sets[1], sizes[1])) {
            result[resultSize++] = sets[0][i];
        }
    }

    for (int i = 0; i < sizes[1]; i++) {
        if (!isElementInSet(sets[1][i], sets[0], sizes[0])) {
            result[resultSize++] = sets[1][i];
        }
    }

    printf("Symmetric Difference: ");
    printSet(result, resultSize);
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

    int choice;
    printf("\nChoose a set operation:\n");
    printf("1. Union\n");
    printf("2. Intersection\n");
    printf("3. Difference (set1 - set2)\n");
    printf("4. Symmetric Difference\n");
    printf("Enter the number of the operation you want to perform: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            unionSets(sets, sizes, numSets);
            break;
        case 2:
            intersectionSets(sets, sizes, numSets);
            break;
        case 3:
            differenceSets(sets, sizes);
            break;
        case 4:
            symmetricDifferenceSets(sets, sizes, numSets);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

