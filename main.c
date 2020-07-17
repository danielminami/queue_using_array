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

int front = 0;
int rear = 0;

node_t queue[MAX_LEN] = {0};

bool isEmpty() {
    return (front == rear);
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
        printf("Error: No memory available\n");
    } else {
        if (isFull()) {
            printf("Error: Queue is full.\n");
            return;
        } else {
            queue[rear] = *newNode;
        }
        rear = rear == 0 ? 1 : (rear + 1) % MAX_LEN;        
    }   
}

int dequeue() {
    int value = -1;
    if (isEmpty()) {
        printf("Error: Queue is empty\n");
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
    
    printf("Adding eighth element:\n");
    enqueue(80);
    printQueue();
    printf("\n");
    
    printf("Adding nineth element:\n");
    enqueue(90);
    printQueue();
    printf("\n");
    
    printf("Dequeuing an element:\n");
    dequeue();
    printQueue();
    printf("\n");
    
}

void resetQueue() {
    int i = 0;
    front = 0;
    rear = 0;
    for (i = 0; i < MAX_LEN; i++) {
        queue[i].data = 0;
    }
}

int main() {

    testCase1();
    resetQueue();
    testCase2();
    
    exit(0);
}

