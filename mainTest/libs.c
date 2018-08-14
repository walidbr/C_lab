#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "libs.h"

#define DEBUG_MODE


#ifdef DEBUG_MODE

void print_queue(Queue* Q)
{
    printf("Queue : ");
    if(Q->depth)
    {
        Node * N = Q->in;
        while(N != NULL)
        {
            printf("%d\t", N->value);
            N = N->next;
        }
    }
    else
        printf("-\n");
    printf("\n");
}

void print_stack(Stack* S)
{
    printf("Stack : ");
    if(S->depth)
    {
        Node * N = S->top;
        while(N != NULL)
        {
            printf("%d\t", N->value);
            N = N->next;
        }
    }
    else
        printf("-\n");
    printf("\n");
}

#else
void print_queue(Queue* Q){}
void print_stack(Stack* S){}
#endif


void init_stack(Stack * S)
{
    S->depth = 0;
    S->top = NULL;
}

void init_queue(Queue * Q)
{
    Q->depth = 0;
    Q->in = NULL;
    Q->out = NULL;
}

void push(Stack * S, int V)
{
    Node * N = (Node*)malloc(sizeof(Node));
    N->next = S->top;
    N->value = V;
    S->top = N;
    S->depth++;
    printf("Stack Info : push %d depth %d\n", V, S->depth);
    print_stack(S);
}

int pop(Stack* S)
{
    int retval;
    if(S->depth)
    {
        int V;
        Node * N = S->top;
        S->top = N->next;
        S->depth --;
        V = N->value;
        free(N);
        printf("Stack Info : pop %d depth %d\n", V, S->depth);
        retval = V;
    }
    else
    {
        printf("Stack Info : empty\n");
        retval = -1;
    }
    print_stack(S);
    return retval;
}

void enqueue(Queue * Q, int V)
{
    Node * N = (Node*)malloc(sizeof(Node));
    N->next = Q->in;
    N->previous = NULL;
    N->value = V;
    if(Q->depth)
        Q->in->previous = N;
    else
        Q->out = N;
    Q->in = N;

    Q->depth++;
    printf("Queue Info : enqueue %d depth %d\n", V, Q->depth);
    print_queue(Q);
}

int dequeue(Queue* Q)
{
    int retval;
    if(Q->depth)
    {
        int V;
        Node * N = Q->out;
        Q->depth --;
        if(Q->depth == 0)
        {
            Q->in = NULL;
            Q->out = NULL;
        }
        else
        {
            Q->out = N->previous;
            Q->out->next = NULL;
        }
        V = N->value;
        free(N);
        printf("Queue Info : dequeue %d depth %d\n", V, Q->depth);
        retval = V;
    }
    else
    {
        printf("Queue Info : empty\n");
        retval = -1;
    }
    print_queue(Q);
    return retval;
    
}

void stack_test(void)
{
    Stack S;
    init_stack(&S);
    push(&S,3);
    push(&S,5);
    push(&S,9);
    pop(&S);
    pop(&S);
    push(&S,4);
    push(&S,3);
    pop(&S);
    push(&S,7);
    pop(&S);
    pop(&S);
    push(&S,3);
    push(&S,11);
    push(&S,20);
    pop(&S);
    push(&S,3);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
}

void queue_test(void)
{
    Queue Q;
    init_queue(&Q);
    enqueue(&Q, 3);
    dequeue(&Q);
    enqueue(&Q, 5);
    enqueue(&Q, 4);
    enqueue(&Q, 11);
    enqueue(&Q, 2);
    dequeue(&Q);
    enqueue(&Q, 50);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    dequeue(&Q);
    enqueue(&Q, 4);
    enqueue(&Q, 11);
    enqueue(&Q, 2);

}

// void main()
// {
//     stack_test();
//     queue_test();
// }

