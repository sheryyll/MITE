/*`1. Task Scheduler for Customer Support Calls`  
`Scenario:`  
A `customer support` team handles `incoming calls` on a `first-come, first-served` basis using a `queue`. The system should:  
- Add `new calls to the queue`  
- Process `calls in order`  
- Display `remaining calls in the queue`  

`Operations Example:`  
```
New Call Added:  Call 101 from Alice  
New Call Added:  Call 102 from Bob  
Processing Call: 101 from Alice  
Remaining Calls: 102 from Bob  
```*/
#include<stdio.h>
#define QUEUE_SIZE 1000

typedef struct {
    int callID;
    char callerName[50];
}Call;

typedef struct{
   Call elements[QUEUE_SIZE];
   int front;
   int back;

}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, int callID, char* callerName);
int QueueEmpty(Queue* q);
Call QueueFront(Queue* q);
void QueuePop(Queue* q);
void DisplayQueue(Queue* q);

int main() {

    Queue callQueue;
    QueueInit(&callQueue;

    QueuePush(&callQueue, 101, "Alice");
    QueuePush(&callQueue, 102, "Bob");
    QueuePush(&callQueue, 103, "Charlie");

    while (!QueueEmpty(&callQueue)) {
        Call currentCall = QueueFront(&callQueue);
        printf("Processing Call: %d from %s\n", currentCall.callID, currentCall.callerName);
        QueuePop(&callQueue);
        DisplayQueue(&callQueue);
    }

    return 0;
}
void QueueInit(Queue* q) {
    q->front = -1;
    q->back = -1;
}

void QueuePush(Queue* q, int callID, char* callerName) {
    if (q->back == QUEUE_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    q->back++;
    q->elements[q->back].callID = callID;
    strcpy(q->elements[q->back].callerName, callerName);

    if (q->front == -1) {
        q->front = 0;
    }

    printf("New Call Added: Call %d from %s\n", callID, callerName);
}

int QueueEmpty(Queue* q){
    return (q->front == -1);

}

Call QueueFront(Queue* q){
    return q->elements[q->front];
}


void QueuePop(Queue* q){
    if(QueueEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    
    if(q->front == q->back){
        q->front = -1;;
        q->back = -1;
    }
    else{
        q->front++;
    }

}
void DisplayQueue(Queue* q) {
    if (QueueEmpty(q)) {
        printf("No remaining calls.\n");
        return;
    }
    
    printf("Remaining Calls: ");
    for (int i = q->front; i <= q->back; i++) {
        printf("%d from %s  ", q->elements[i].callID, q->elements[i].callerName);
    }
    printf("\n");
}