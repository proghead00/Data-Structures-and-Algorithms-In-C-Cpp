#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter size of stack: ");
    scanf("%d", &st->size);
    st->top = -1;

    st->S = (int *)malloc(st->size * sizeof(int));
}

void display(struct Stack st)
{
    for (int i = st.top; i >= 0; i--)
    {
        printf("%d ", st.S[i]);
        printf("\n");
    }
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack overflow\n");
    }

    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;

    if (st->top == -1)
    {
        printf("Stack underflow");
    }
    else
    {

        x = st->S[st->top--];
    }
    return x;
}

int peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("Invalid Index \n");
    x = st.S[st.top - index + 1];
    return x;
}
