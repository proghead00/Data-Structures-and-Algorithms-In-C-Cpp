#include <stdio.h>

int main(void)
{
    int m, n;
    printf("Enter the value of m: "); //m
    scanf("%d", &m);

    printf("Enter the value of n: "); //n
    scanf("%d", &n);
    int a[m], b[n], c[m + n];
    printf("Enter elements for 'a' \t: ");

    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]); //a

    printf("Enter elements for b \t: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]); //b

    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    for (; i < m; i++)
        c[k++] = a[i];

    for (; j < n; j++)
        c[k++] = b[j];

    printf("Printing the sorted merged array: ");
    for (i = 0; i < (m + n); i++)
    {
        printf("%d ", c[i]);
    }
    return 0;
}
