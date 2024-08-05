#include <stdio.h>
#include <math.h>

int main() {
    double number;
    printf("Enter a real number: ");
    scanf("%lf", &number);

    int floorValue = (int)floor(number);
    int ceilingValue = (int)ceil(number);

    printf("Floor: %d\n", floorValue);
    printf("Ceiling: %d\n", ceilingValue);

    return 0;
}

