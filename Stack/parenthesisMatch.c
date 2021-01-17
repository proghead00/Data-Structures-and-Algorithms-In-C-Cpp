#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;

    struct Node *next;

} *top = NULL;

void push(char x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
    {
        printf("Stack is Full");
    }

    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}