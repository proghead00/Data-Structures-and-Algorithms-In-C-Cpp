#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int data;
} *first = NULL;

void create(int value)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Memory couldn't be allocated");
        return;
    }

    t->data = value;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        struct Node *p = first;
        while (p->next != NULL)
            p = p->next;
        p->next = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{

    int n;
    printf("Enter size of the list: \n");
    scanf("%d", &n);

    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++)
    {
        int element;
        scanf("%d", &element);
        create(element);
    }

    display(first);

    return 0;
}