/*. Flight Ticket Booking System
Scenario:
A travel agency wants to "store the details of N passengers" (Name, Age, Destination).
The system should allow:
Adding a "new passenger"
"Sorting" passengers by "destination name (A-Z)"
Searching for passengers traveling to a specific destination
Use "arrays" and implement "sorting and searching techniques".

"Input Example:"
Enter number of passengers: 3
Passenger 1: Alice, 30, Delhi
Passenger 2: Bob, 25, Mumbai
Passenger 3: Charlie, 40, Chennai

Sorted List (by destination):
Charlie
Chennai
Alice
Delhi
Bob
Mumbai
Enter destination to search: Mumbai
Passengers traveling to Mumbai: Bob*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSENGERS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESTINATION_LENGTH 50

int input(char passenger_name[][MAX_NAME_LENGTH], int age[], char destination[][MAX_DESTINATION_LENGTH]) {
    int n;
    printf("Enter number of passengers (max %d): ", MAX_PASSENGERS);
    scanf("%d", &n);
    
    if (n > MAX_PASSENGERS) {
        printf("Number of passengers exceeds maximum limit. Setting to %d.\n", MAX_PASSENGERS);
        n = MAX_PASSENGERS;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter passenger %d Name, Age, Destination: ", i + 1);
        scanf("%s %d %s", passenger_name[i], &age[i], destination[i]);
    }
    return n;
}

void swapchar(char a[], char b[]) {
    char temp[MAX_DESTINATION_LENGTH];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void swapint(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortbydestination(int n, char passenger_name[][MAX_NAME_LENGTH], int age[], char destination[][MAX_DESTINATION_LENGTH]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(destination[j], destination[j + 1]) > 0) {
                swapchar(destination[j], destination[j + 1]);
                swapchar(passenger_name[j], passenger_name[j + 1]);
                swapint(&age[j], &age[j + 1]);
            }
        }
    }
}

void search(int n, char searchdest[], char passenger_name[][MAX_NAME_LENGTH], int age[], char destination[][MAX_DESTINATION_LENGTH]) {
    int flag = 0;
    printf("\nEnter destination to search: ");
    scanf("%s", searchdest);
    for (int i = 0; i < n; i++) {
        if (strcmp(destination[i], searchdest) == 0) {
            printf("\nPassenger Name: %s, Age: %d, Destination: %s\n", passenger_name[i], age[i], destination[i]);
            flag = 1;
        }
    }
    if (!flag) {
        printf("\nNo passengers are traveling to %s\n", searchdest);
    }
}

int main() {
    int n;
    int age[MAX_PASSENGERS];
    char searchdest[MAX_DESTINATION_LENGTH];
    char passenger_name[MAX_PASSENGERS][MAX_NAME_LENGTH];
    char destination[MAX_PASSENGERS][MAX_DESTINATION_LENGTH];
    
    n = input(passenger_name, age, destination);
    sortbydestination(n, passenger_name, age, destination);

    printf("\nSorted List (by destination):\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Age: %d, Destination: %s\n", passenger_name[i], age[i], destination[i]);
    }
    
    search(n, searchdest, passenger_name, age, destination);

    return 0;
}