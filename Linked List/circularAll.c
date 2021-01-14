#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

// typedef int datatype;

// typedef struct node1
// {
//     datatype data;
//     struct Node *next;
// } node1;

struct Node *createnode(int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL)
        printf("ERROR: Memory Couldn't be Allocated!!\n");
    else
    {
        newnode->data = value;
        newnode->next = NULL;
    }
    return newnode;
}
void create(int value)
{
    struct Node *t = createnode(value);
    // struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    // t->data = value;
    t->next = first;
    if (first == NULL)
    {
        first = t;
        first->next = first;
    }
    else
    {
        struct Node *p = first;
        while (p->next != first)
            p = p->next;
        p->next = t;
    }
}

void display(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != first);
    printf("\n");
}

int count(struct Node *p)
{
    int c = 0;
    if (p == NULL)
        return c;
    while (p->next != first)
    {
        c++;
        p = p->next;
    }
    return ++c;
}

void insertAny(int pos, int x)
{
    struct Node *p = first;
    if (pos >= count(first))
    {
        create(x);
        return;
    }

    struct Node *t = createnode(x);

    t->data = x;
    if (pos == 1)
    {
        t->next = first;
        while (p->next != first)
            p = p->next;
        first = t;
        p->next = first;
        return;
    }
    while (--pos)
        p = p->next;
    t->next = p->next;
    p->next = t;
}

void delAny(int pos)
{
    struct Node *p = first;
    if (pos < 1 && pos > count(first))
    {
        printf("Deletion Not Possible!!");
        return;
    }
    --pos;
    if (pos == 0)
    {
        while (p->next != first)
            p = p->next;
        // first = p->next->next;
        first = first->next;
    }
    else
    {
        while (--pos)
            p = p->next;
    }
    struct Node *temp = p->next;
    p->next = p->next->next;
    free(temp);
}

void search(int key)
{
    struct Node *p = first;
    while (p->next != first)
    {
        if (p->data == key)
        {
            printf("Found\n");
            return;
        }
        p = p->next;
    }
    printf("Not Found\n");
}

void sortedInsert(int x)
{
    struct Node *t = createnode(x);

    struct Node *p = first;
    struct Node *prev = NULL;
    while (t->data > p->data && p->next != first)
    {
        prev = p;
        p = p->next;
    }
    if (t->data > p->data)
    {
        prev = p;
        p = p->next;
    }
    if (prev == NULL)
    {
        t->next = first;
        while (p->next != first)
            p = p->next;
        first = t;
        p->next = first;
    }
    else
    {
        t->next = prev->next;
        prev->next = t;
    }
}
// void duplicates(struct Node *p)
// {
//     struct Node *q = p->next;
//     while (q != first)
//     {
//         if (p->data != q->data)
//         {
//             p = q;
//             q = q->next;
//         }
//         else
//         {
//             p->next = q->next;
//             free(q);
//             q = q->next;
//         }
//     }
// }
int main()
{
    int n;
    printf("Enter size of the list: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for (int i = 0; i < n; i++)
    {
        int element;
        scanf("%d", &element);
        create(element);
    }
    // insertAny(1, 110);
    // delAny(1);
    search(4);
    // sortedInsert(3);
    // duplicates(p);
    display(first);
    return 0;
}