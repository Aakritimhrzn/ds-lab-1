#include <stdio.h>
#include <string.h>

#define MAX_PERSONS 5
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
    double membershipA;
    double membershipB;
} Person;

double calculateMembershipA(int age) {
    if (age <= 20) {
        return 1.0;
    } else if (age > 20 && age <= 30) {
        return (30.0 - age) / 10.0;
    } else {
        return 0.0;
    }
}

double calculateMembershipB(int age) {
    if (age <= 15) {
        return 1.0;
    } else if (age > 15 && age <= 35) {
        return (35.0 - age) / 20.0;
    } else {
        return 0.0;
    }
}

void printMembershipSets(Person persons[]) {
    printf("\nMembership Degrees for Set A:\n");
    for (int i = 0; i < MAX_PERSONS; i++) {
        printf("Name: %s, Age: %d, Membership A: %.2f\n", persons[i].name, persons[i].age, persons[i].membershipA);
    }

    printf("\nMembership Degrees for Set B:\n");
    for (int i = 0; i < MAX_PERSONS; i++) {
        printf("Name: %s, Age: %d, Membership B: %.2f\n", persons[i].name, persons[i].age, persons[i].membershipB);
    }
}

void performSetOperations(Person persons[]) {
    printf("\nSet Operations Results:\n");

    printf("Union (max of Membership A and B):\n");
    for (int i = 0; i < MAX_PERSONS; i++) {
        double unionMembership = (persons[i].membershipA > persons[i].membershipB) ? persons[i].membershipA : persons[i].membershipB;
        printf("Name: %s, Union Membership: %.2f\n", persons[i].name, unionMembership);
    }

    printf("Intersection (min of Membership A and B):\n");
    for (int i = 0; i < MAX_PERSONS; i++) {
        double intersectionMembership = (persons[i].membershipA < persons[i].membershipB) ? persons[i].membershipA : persons[i].membershipB;
        printf("Name: %s, Intersection Membership: %.2f\n", persons[i].name, intersectionMembership);
    }

    printf("Difference (Membership A - Membership B):\n");
    for (int i = 0; i < MAX_PERSONS; i++) {
        double differenceMembership = persons[i].membershipA - persons[i].membershipB;
        printf("Name: %s, Difference Membership: %.2f\n", persons[i].name, differenceMembership);
    }
}

int main() {
    Person persons[MAX_PERSONS];

    for (int i = 0; i < MAX_PERSONS; i++) {
        printf("Enter name of person %d: ", i + 1);
        scanf("%s", persons[i].name);
        printf("Enter age of person %d: ", i + 1);
        scanf("%d", &persons[i].age);

        persons[i].membershipA = calculateMembershipA(persons[i].age);
        persons[i].membershipB = calculateMembershipB(persons[i].age);
    }

    printMembershipSets(persons);
    performSetOperations(persons);

    return 0;
}

