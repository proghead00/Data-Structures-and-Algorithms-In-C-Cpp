
#include "Queue.h"
#include <stdio.h>

void BFS(int G[][7], int start, int n)
{
    int i = start, j;
    int visited[7] = {0};
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);
    while (!isEmpty())
    {
        i = dequeue();
        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}
void DFS(int G[][7], int start, int n)
{

    static int visited[7] = {0};
    int j;
    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;
    }
    for (j = 1; j < n; j++)
    {
        if (G[start][j] == 1 && visited[j] == 0)
            DFS(G, j, n);
    }
}

int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};
    printf("BFS: ");
    BFS(G, 1, 7);

    printf("\n");

    printf("DFS: ");
    DFS(G, 4, 7);
    return 0;
}