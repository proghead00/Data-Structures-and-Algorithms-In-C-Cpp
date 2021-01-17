#include <iostream>
using namespace std;

class Queue
{

    int *arr;
    int f, r, cs, ms; // front, rear, current size, max size

public:
    Queue(int ds = 5)
    {
        arr = new int[ds];
        cs = 0;
        ms = ds;
        f = 0;
        r = ms - 1;
    }

    bool full()
    {

        return cs == ms;
    }

    bool empty()
    {
        return cs == 0;
    }

    void push(int data)
    {
        if (!full())
        {
            r = (r + 1) % ms;
            arr[r] = data;
            cs++;
        }
    }

    void pop()
    {
        if (!empty())
        {
            f = (f + 1) % ms;
            cs--;
        }
    }

    int front()
    {

        return arr[f];
    }
    ~Queue()
    {
        if (arr != NULL)
        {
            delete[] arr;
            arr = NULL;
        }
    }
};

int main()
{

    Queue q;

    for (int i = 0; i < 5; i++)
    {
        q.push(i);
    }

    q.pop();
    q.push(7);

    while (!q.empty())
    {
        cout << q.front() << " ";

        q.pop();
    }

    return 0;
}