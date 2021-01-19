
#ifndef STACK_H_
#define STACK_H_

/**
* @file Stack.h
*/

#include <limits.h>
#define STACK_EMPTY INT_MIN

/*
* Could replace with any type
*/
typedef int T;

/**
 * @brief Represent a stack node witch contain a value and pointer to the next (previus) value
*/
typedef struct Node_t
{
    T value;
    struct Node_t *next;
} Node;

/**
 * @brief Represent the stack. contain the pointer to the start of the stack
*/
typedef struct Stack_t
{
    Node *root;
    int errorCode;
} Stack;

/**
 * @brief Create a new stack.
 * @return a reference to the new stack
*/
Stack *CreateStack();

/**
 * @brief Ddelete the given stack with all his values.
 * @param stack the stack to delete
*/
void DeleteStack(Stack *stack);

/**
 * @brief Push an item to the stack.
 * @param stack the stack to push to
 * @param item the value to insert to the stack
*/
void StackPush(Stack *stack, T item);

/**
 * @brief Pop the top value from the given stack.
 * @param the stack to pop from him
 * @return the value in the top of the stack
*/
T StackPop(Stack *stack);

/**
 * @brief Retuen the last error code of the stack.
 * @param stack the given stack to check his last error code
 * @return the last error code 
*/
int StackGetLastError(Stack *stack);

/**
 * @brief Calculate the size if values in the stack.
 * @param  the stack to be calculate
 * @return the size of the stack
*/
size_t StackSize(Stack * stack);

/**
 * @brief Print the values in the stack.
 * @param stack the stack to be printed
*/
void StackPrint(Stack *stack);

#endif // !STACK_H_

