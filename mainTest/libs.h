#ifndef __QUEUE_STACK__H
#define __QUEUE_STACK__H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define DEBUG_MODE

typedef struct _node
{
    struct _node* next;
    struct _node* previous;
    int value;

} Node;

typedef struct _stack
{
    int depth;
    Node* top;
} Stack;

typedef struct _queue
{
    int depth;
    Node* in;
    Node* out;
} Queue;

void print_queue(Queue* Q);
void print_stack(Stack* S);
void init_stack(Stack * S);
void init_queue(Queue * Q);
void push(Stack * S, int V);
int pop(Stack* S);
void enqueue(Queue * Q, int V);
int dequeue(Queue* Q);


#endif /* __QUEUE_STACK__H */
