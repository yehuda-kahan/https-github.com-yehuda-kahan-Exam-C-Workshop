
#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack *CreateStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
    {
        
        printf_s("ERROR with the allocation !");
        exit(1);
    }

    stack->root = NULL;
    stack->errorCode = 0;
    return stack;
}

void DeleteStack(Stack *stack)
{
    
    if (stack->root == NULL)
    {
        free(stack);
    }
    else
    {
        while (stack->root != NULL)
        {
            Node *temp = stack->root;
            stack->root = stack->root->next;
            temp->next = NULL;
            free(temp);
            temp = NULL;
        }
        free(stack);
    }
}

void StackPush(Stack *stack, T item)
{
    
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf_s("ERROR with the allocation !");
        exit(1);
    }

    temp->value = item;

    if (stack->root == NULL)
    {
        stack->root = temp;
        temp->next = NULL;
        temp = NULL;
    }
    else
    {
        temp->next = stack->root;
        stack->root = temp;
        temp = NULL;
    }
}

T StackPop(Stack *stack)
{
    
    if (stack->root == NULL)
    {
        stack->errorCode = STACK_EMPTY;
        return stack->errorCode;
    }
    else
    {
        T tempValue = stack->root->value;
        Node *temp = stack->root;
        stack->root = stack->root->next;
        temp->next = NULL;
        free(temp);
        temp = NULL;
        return tempValue;
    }
}

int StackGetLastError(Stack *stack)
{
    return stack->errorCode;
}

size_t StackSize(Stack *stack)
{
    if (stack->root == NULL)
    {
        return 0;
    }
    else
    {
        size_t result = 0;

        Node *tempNode = stack->root;
        while (tempNode != NULL)
        {
            result++;
            tempNode = tempNode->next;
        }
        return result;
    }
}

void StackPrint(Stack *stack)
{
    if (stack->root == NULL)
    {
        return;
    }
    else
    {
        Node *tempNode = stack->root;
        while (tempNode != NULL)
        {
            printf_s(" %i\n", tempNode->value);
            tempNode = tempNode->next;
        }
    }
}

