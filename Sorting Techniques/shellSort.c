#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void shellSort(int a[], int n)
{

    for (int gap = n / 2; gap >= 1; gap /= 2)
    {
        {
            for (int j = gap; j < n; j++)
            {
                for (int i = j - gap; i >= 0; i -= gap)
                {
                    if (a[i + gap] > a[i])
                    {
                        break;
                    }
                    else
                        swap(&a[i + gap], &a[i]);
                }
            }
        }
    }
}
int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;

    shellSort(A, n);
    for (i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}