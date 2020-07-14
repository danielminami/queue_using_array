/*
Daniel Minami <minamid@sheridancollege.ca>
----------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LEN 6

typedef struct node {
    int data;
} node_t;

int front = -1;
int rear = -1;

node_t queue[MAX_LEN] = {0};

bool isEmpty() {
    return (front == -1);
}

bool isFull() {
    int calculatedRear = rear == 0 ? 1 : (rear +1) % MAX_LEN; 
    return front == calculatedRear;
}

node_t* createNode(int newValue) {
    node_t* newNode = (node_t*) malloc( sizeof(node_t) );
    newNode->data = newValue;
    return newNode;
}

void enqueue(int value) {
    node_t *newNode = createNode(value);
    if (newNode == NULL) {
        printf("No memory available");
    } else {
        if (isEmpty()) {
            queue[0] = *newNode;
            printf("***inside if %d***", queue[0].data);
            front = 0;
            rear = 0;
        } else if (isFull()) {
            printf("Sorry, Queue is full.");
        } else {
            printf("*** BEFORE: %d ***\n", rear);
            rear = rear == 0 ? 1 : (rear + 1) % MAX_LEN;
            printf("*** AFTER: %d ***\n", rear);
            queue[rear] = *newNode;
        }        
    }
    
    printf("*** %d ***\n", rear);
    
}

int dequeue() {
    int value = -1;
    if (isEmpty()) {
        printf("Queue is empty");
    } else {
        value = queue[front].data;
        queue[front].data = -1;
        front = (front+1) % MAX_LEN;
    }
    return value;
}

void printQueue() {
    printf("Printing all elements: \n");
    int i = 0;
    for (i = 0; i < MAX_LEN; i++) {
        printf("%d ", queue[i].data);
    }
    printf("  FRONT:%d  REAR:%d", front, rear);
    printf("\n");
}

void testCase1() {
    
    //This test case should fail and not allow all elements 70 and 80 to be
    //added to the queue.
    
    printf("*******************\n");
    printf("****TEST CASE 1****\n");
    printf("*******************\n\n");
    
    printf("Adding first element:\n");
    enqueue(10);
    printQueue();
    printf("\n");
    
    printf("Adding second element:\n");
    enqueue(20);
    printQueue();
    printf("\n");
    
    printf("Adding third element:\n");
    enqueue(30);
    printQueue();
    printf("\n");
    
    printf("Adding fourth element:\n");
    enqueue(40);
    printQueue();
    printf("\n");
    
    printf("Adding fifth element:\n");
    enqueue(50);
    printQueue();
    printf("\n");
    
    printf("Adding sixth element:\n");
    enqueue(60);
    printQueue();
    printf("\n");
    
    printf("Adding seventh element:\n");
    enqueue(70);
    printQueue();
    printf("\n");
    
    printf("Adding eighth element:\n");
    enqueue(80);
    printQueue();
    printf("\n");
}

void testCase2() {
    
    //This test case should and not allow all the elements to be 
    //added to and popped the queue.
    
    printf("*******************\n");
    printf("****TEST CASE 2****\n");
    printf("*******************\n\n");
    
    printf("Adding first element:\n");
    enqueue(10);
    printQueue();
    printf("\n");
    
    printf("Adding second element:\n");
    enqueue(20);
    printQueue();
    printf("\n");
    
    printf("Adding third element:\n");
    enqueue(30);
    printQueue();
    printf("\n");
    
    printf("Adding fourth element:\n");
    enqueue(40);
    printQueue();
    printf("\n");
    
    printf("Dequeuing an element:\n");
    dequeue();
    printQueue();
    printf("\n");
    
    printf("Dequeuing an element:\n");
    dequeue();
    printQueue();
    printf("\n");
    
    printf("Adding fifth element:\n");
    enqueue(50);
    printQueue();
    printf("\n");
    
    printf("Adding sixth element:\n");
    enqueue(60);
    printQueue();
    printf("\n");
    
    printf("Dequeuing an element:\n");
    dequeue();
    printQueue();
    printf("\n");
    
    printf("Dequeuing an element:\n");
    dequeue();
    printQueue();
    printf("\n");
    
    printf("Adding seventh element:\n");
    enqueue(70);
    printQueue();
    printf("\n");
    
    printf("Adding eighth element:\n");
    enqueue(80);
    printQueue();
    printf("\n");
    
    printf("Dequeuing an element:\n");
    dequeue();
    printQueue();
    printf("\n");
    
    printf("Dequeuing an element:\n");
    dequeue();
    printQueue();
    printf("\n");
    
    printf("Dequeuing an element:\n");
    dequeue();
    printQueue();
    printf("\n");
    
    printf("Dequeuing an element:\n");
    dequeue();
    printQueue();
    printf("\n");
    
    printf("Dequeuing an element:\n");
    dequeue();
    printQueue();
    printf("\n");
    
    printf("Dequeuing an element:\n");
    dequeue();
    printQueue();
    printf("\n");
    
}

void resetQueue() {
    int i = 0;
    front = -1;
    rear = -1;
    for (i = 0; i < MAX_LEN; i++) {
        queue[i].data = 0;
    }
}

int main() {

    testCase1();
    resetQueue();
    testCase2();

//    
//    dequeue();
//    printQueue();
//    enqueue(40);
//    enqueue(50);
//    enqueue(60);
//    enqueue(70);
//    enqueue(80);
//    enqueue(90);
//    printQueue();
    
    exit(0);
}

