#include <iostream>
using namespace std;

class Diagonal
{
private:
    int n;
    int *a;

public:
    Diagonal(int n)
    {
        this->n = n;
        a = new int[n];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~Diagonal() { delete[] a; }
};

void Diagonal::set(int i, int j, int x)
{
    if (i == j)
        a[i - 1] = x;
}

int Diagonal ::get(int i, int j)
{
    if (i == j)
        return a[i - 1];
    else
        return 0;
}

void Diagonal ::display()
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                cout << a[i - 1] << " ";
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
    Diagonal dm(d);
    int x;
    cout << "Enter the elements:\n";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            dm.set(i, j, x);
        }
    }
    dm.display();

    return 0;
}