#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack
{
    int top;
    int array[MAX_SIZE];
};


void initialize_stack(struct Stack* stack)
{
    stack ->top = -1;

}
int isEmpty(struct Stack* stack)
{
    return stack->top==-1;
}

int isFull(struct Stack* stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack,int data)
{
    if(isFull(stack))
    {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = data;
    printf("%d pushed on to the stack\n",data);

}

int pop(struct Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack underflow\n");
        return -1;
    }
    int data = stack->array[stack->top];
    stack->top--;
    return data;
}

int peek(struct Stack* stack)
{
    if(isEmpty==1)
    {
        printf("The stack is empty\n");
        return -1;
    }
    return stack->array[stack ->top];
}

int main()
{
    struct Stack stack;
    initialize_stack(&stack);
    push(&stack,10);
    push(&stack,20);
    push(&stack,30);

    printf("%d popped from the stack\n",pop(&stack));

    printf("Top element: %d",peek(&stack));
    return 0;
}