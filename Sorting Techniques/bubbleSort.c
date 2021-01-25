#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(int A[], int n)
{
    int i, j, flag = 0;

    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

int main()
{
    int n;

    printf("Enter size of the array: \n ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements: \n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    bubble(a, n);

    printf("After sorting: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
