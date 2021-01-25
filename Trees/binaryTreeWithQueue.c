#include <stdio.h>
#include <stdlib.h>

struct Node *root = NULL;

struct Node
{
    struct Node *rchild;

    struct Node *lchild;
    int data;
};

struct Queue
{
    int size, front, rear;
    struct Node **Q;
};

void createQ(struct Queue *q, int size)
{

    q->size = size;
    q->front = q->rear = 0;

    q->Q = (struct Node **)malloc(sizeof(struct Node *));
}

void enq(struct Queue *q, struct Node *x)
{

    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is FULL\n");
    }

    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node *deq(struct Queue *q)
{
    struct Node *x = NULL;

    if (q->front == q->rear)
    {
        printf("Queue is EMPTY\n");
    }

    else
    {
        q->front = (q->front + 1) % q->size;

        x = q->Q[q->front];
    }

    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    createQ(&q, 100);

    printf("Enter root value:");
    scanf("%d", &x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enq(&q, root);

    while (!isEmpty(q))
    {
        p = deq(&q);
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct
                                             Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enq(&q, t);
        }

        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);

        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct
                                             Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enq(&q, t);
        }
    }
}

void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

int main()
{
    Treecreate();
    Preorder(root);
    printf("\nPost Order ");
    Postorder(root);

    return 0;
}