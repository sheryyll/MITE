/*3. Railway Ticket Booking – Seat Availability Search
`Scenario:`  
A `railway reservation system` allows passengers 
to check seat availability. The system should:  
- Sort `seat numbers` (ascending order)  
- Search `for a specific seat number` using `binary search`  
- Display `the next available seat`  

`Operations Example:`  
Available Seats: [45, 12, 78, 23, 56]
Sorted: [12, 23, 45, 56, 78]
Search Seat 23: Found (Available)
Next Available Seat: 45
*/

#include <stdio.h>


void sortSeats(int seats[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (seats[j] > seats[j + 1]) {
                int temp = seats[j];
                seats[j] = seats[j + 1];
                seats[j + 1] = temp;
            }
        }
    }
}


int binarySearch(int seats[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (seats[mid] == key)
            return mid;  
        else if (seats[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  
}


int nextAvailableSeat(int seats[], int n, int seatNumber) {
    for (int i = 0; i < n; i++) {
        if (seats[i] > seatNumber) {
            return seats[i];
        }
    }
    return -1;  
}

int main() {
    int seats[] = {45, 12, 78, 23, 56};
    int n = sizeof(seats) / sizeof(seats[0]);
    
    
    sortSeats(seats, n);
    
    
    printf("Sorted Seats: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", seats[i]);
    }
    printf("\n");
    
  
    int searchSeat = 23;
    int index = binarySearch(seats, n, searchSeat);
    if (index != -1) {
        printf("Search Seat %d: Found (Available)\n", searchSeat);
    } else {
        printf("Search Seat %d: Not Available\n", searchSeat);
    }
    
    int nextSeat = nextAvailableSeat(seats, n, searchSeat);
    if (nextSeat != -1) {
        printf("Next Available Seat: %d\n", nextSeat);
    } else {
        printf("No next available seat.\n");
    }
    
    return 0;
}