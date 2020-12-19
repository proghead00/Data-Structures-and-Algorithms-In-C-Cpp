#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n;

    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter elements:  \n");
        scanf("%d", &a[i]);
    }
    printf("Elements: \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    // insertion
    int x, index;

    printf(" \n Enter element to be inserted: \n ");
    scanf("%d", &x);

    printf("Enter index : \n");
    scanf("%d", &index);

    int Length = sizeof(a) / sizeof(int);

    for (int i = n; i > index; i--)
    {

        a[i] = a[i - 1];
    }
    a[index] = x;

    printf("After insertion: \n");
    for (int i = 0; i < n + 1; i++)
    {
        printf("%d ", a[i]);
    }
}