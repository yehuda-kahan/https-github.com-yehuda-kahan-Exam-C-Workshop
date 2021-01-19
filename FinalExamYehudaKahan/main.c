
#include <stdio.h>
#include "Stack.h"

/*
* Assumption : The use of the functions of the stack will be always on initialized stack
*/

int main()
{
    Stack *stack1 = CreateStack();
    Stack *stack2 = CreateStack();

    printf_s("Stack 1 :\n");
    
    StackPush(stack1, 1);
    StackPush(stack1, 2);
    StackPush(stack1, 8);
    StackPush(stack1, -5);

    StackPrint(stack1);

    T popValue = StackPop(stack1);
    printf_s("\n%i\n\n", popValue);

    StackPrint(stack1);

    DeleteStack(stack1);

    printf_s("Stack 2 :\n");

    StackPush(stack2, 10);
    StackPush(stack2, 20);
    StackPush(stack2, 80);
    StackPush(stack2, -50);

    StackPrint(stack2);

    popValue = StackPop(stack2);
    printf_s("\n%i\n\n", popValue);

    StackPrint(stack2);

    DeleteStack(stack2);
    
    return 0;
}