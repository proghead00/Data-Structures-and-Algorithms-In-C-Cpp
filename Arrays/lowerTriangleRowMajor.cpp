#include <iostream>
using namespace std;

class LowerT
{
private:
    int n;
    int *a;

public:
    LowerT(int n)
    {
        this->n = n;
        a = new int[n];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~LowerT() { delete[] a; }
};

void LowerT::set(int i, int j, int x)
{
    if (i >= j)
        a[i * (i - 1) / 2 + j - 1] = x;
}

int LowerT ::get(int i, int j)
{
    if (i >= j)
        return a[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}

void LowerT ::display()
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << a[i * (i - 1) / 2 + j - 1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
int main()
{
    int d;
    cout << "Enter dimension: ";
    cin >> d;
    LowerT lt(d);
    int x;
    cout << "Enter the elements:\n";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            lt.set(i, j, x);
        }
    }
    lt.display();

    return 0;
}