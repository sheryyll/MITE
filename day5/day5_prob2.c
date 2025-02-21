/*`2. Railway Ticket Reservation System`  
`Scenario:`  
A `railway booking system` maintains a `queue of passengers` for reservations. The system should:  
- Add `new reservations`  
- Process bookings `in order`  
- Display `waiting list if full`  

`Operations Example:`  
```
Booking Confirmed: Passenger 1 (Alice)  
Booking Confirmed: Passenger 2 (Bob)  
Waiting List: Passenger 3 (Charlie)  */

#include <stdio.h>
#include <string.h>
#define MAX_SEATS 2  
#define MAX_QUEUE 5  

typedef struct {
    int id;
    char name[50];
} Passenger;

typedef struct {
    Passenger elements[MAX_QUEUE];
    int front, back;
} Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, int id, char* name);
int QueueEmpty(Queue* q);
Passenger QueueFront(Queue* q);
void QueuePop(Queue* q);
void DisplayQueue(Queue* q);

int main() {
    Queue bookingQueue;
    QueueInit(&bookingQueue);

    QueuePush(&bookingQueue, 1, "Alice");
    QueuePush(&bookingQueue, 2, "Bob");
    QueuePush(&bookingQueue, 3, "Charlie");
    QueuePush(&bookingQueue, 4, "David");

    while (!QueueEmpty(&bookingQueue)) {
        Passenger p = QueueFront(&bookingQueue);
        printf("Processing Booking: Passenger %d (%s)\n", p.id, p.name);
        QueuePop(&bookingQueue);
        DisplayQueue(&bookingQueue);
    }

    return 0;
}

void QueueInit(Queue* q) {
    q->front = -1;
    q->back = -1;
}

void QueuePush(Queue* q, int id, char* name) {
    if (q->back == MAX_QUEUE - 1) {
        printf("Sorry, no available seats or waiting list slots.\n");
        return;
    }

    q->back++;
    q->elements[q->back].id = id;
    strcpy(q->elements[q->back].name, name);

    if (q->front == -1) {
        q->front = 0;
    }

    if (q->back < MAX_SEATS) {
        printf("Booking Confirmed: Passenger %d (%s)\n", id, name);
    } else {
        printf("Waiting List: Passenger %d (%s)\n", id, name);
    }
}

int QueueEmpty(Queue* q) {
    return (q->front == -1);
}

Passenger QueueFront(Queue* q) {
    return q->elements[q->front];
}

void QueuePop(Queue* q) {
    if (QueueEmpty(q)) {
        printf("No reservations to process.\n");
        return;
    }

    if (q->front == q->back) {
        q->front = -1;
        q->back = -1;
    } else {
        q->front++;
    }
}

void DisplayQueue(Queue* q) {
    if (QueueEmpty(q)) {
        printf("No remaining reservations.\n");
        return;
    }

    printf("Remaining Reservations: ");
    for (int i = q->front; i <= q->back; i++) {
        printf("Passenger %d (%s)  ", q->elements[i].id, q->elements[i].name);
    }
    printf("\n");
}
