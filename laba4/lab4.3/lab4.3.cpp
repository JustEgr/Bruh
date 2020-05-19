#include <iostream>

using namespace std;

long long int F(int n);
long long int G(int n);

int main()
{
    cout << "F(1) =  " << F(1) << "; G(1) = " << G(1) << endl;
    for (int i = 2; i <= 10; i++)
    {
        cout << "F(" << i << ") =  " << F(i) << "; G(" << i << ") = " << G(i) << endl;
    }
    return 0;
}

long long int F(int n)
{
    return n == 1 ? -2 : 4 * F(n - 1) * G(n - 1);
}

long long int G(int n)
{
    return n == 1 ? 1 : 5 * F(n - 1) + G(n - 1);
}