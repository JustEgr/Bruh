#include <iostream>

using namespace std;

int F(int a, int d, int n);

int main()
{
    int a, d, n;
    cout << "Enter a: "; cin >> a;
    cout << "Enter d: "; cin >> d;
    cout << "Enter n: "; cin >> n;
    cout << "\nResult: " << F(a, d, n);
    return 0;
}

int F(int a, int d, int n)
{
    if (n == 1)
        return a;
    else
        return F(a, d, n - 1) + d;
}
