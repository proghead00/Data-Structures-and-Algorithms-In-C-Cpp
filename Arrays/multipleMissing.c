#include <stdio.h>
#include <math.h>
int main(void)
{
    int arr[6], i;
    for (i = 0; i < 6; i++)
    {
        printf("Enter element:");
        scanf("%d", &arr[i]);
    }

    int diff;
    diff = arr[0] - 0;

    for (i = 0; i < 6; i++)
    {

        if (arr[i] - i != diff)
        {
            while (diff < arr[i] - i)
            {
                printf("%d \n", i + diff);
                diff++;
            }
        }
    }
}
