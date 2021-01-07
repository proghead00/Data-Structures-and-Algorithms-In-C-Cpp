#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
struct Node
{
    int data;
    struct Node *next;

} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 0; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
int Max(struct Node *p)
{
    int max = INT32_MIN;

    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
int main()
{
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);

    printf("Max %d\n", Max(first));

    return 0;
}
