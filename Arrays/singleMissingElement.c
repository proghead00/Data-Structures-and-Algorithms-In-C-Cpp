// missing element -> sum series

#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, i, j;
    printf("Enter no. of elements: \n");
    scanf("%d", &n);
    int arr[n];
    int sum = 0, s = 0;
    printf("Enter elements in the array: \n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        s = s + arr[i];
    }
    
    n = arr[n - 1];
    
    sum = (n * (n + 1)) / 2;
    int diff;
    diff = sum - s;
    printf("Missing element is: %d", abs(diff));

    return 0;
}
