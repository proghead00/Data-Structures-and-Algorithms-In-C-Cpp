#include <stdio.h>
int main()
{
    int i, l, h, mid, n, search, a[100];

    printf("Enter number of elements\n");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter value to find\n");
    scanf("%d", &search);

    l = 0;
    h = n - 1;
    mid = (l + h) / 2;

    while (l <= h)
    {
        if (a[mid] < search)
            l = mid + 1;
        else if (a[mid] == search)
        {
            printf("%d found at location %d.\n", search, mid + 1);
            break;
        }
        else
            h = mid - 1;

        mid = (l + h) / 2;
    }
    if (l > h)
        printf("Not found! %d isn't present in the list.\n", search);

    return 0;
}