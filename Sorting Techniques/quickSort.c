#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[], int start, int end)
{
    int pivot = a[end];
    int pIndex = start;

    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(&a[i], &a[pIndex]);
            pIndex++;
        }
    }
    swap(&a[pIndex], &a[end]);
    return pIndex;
}

void quicksort(int a[], int start, int end)
{

    if (start < end)
    {

        int pindex = partition(a, start, end);
        quicksort(a, start, pindex - 1);
        quicksort(a, pindex + 1, end);
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    quicksort(A, 0, 9);

    for (int i = 0; i < 9; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}