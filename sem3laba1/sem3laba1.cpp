#include <iostream>
using namespace std;

struct complex
{
	double k, l;
};

void Comp_slozh(complex a, complex b)
{
	cout << "Summa :" << a.k + b.k << " " << a.l + b.l << endl;
}
void Comp_umnozh(complex a, complex b)
{
	cout << "Proizvedenie :" << a.k * b.k << " " << a.l * b.l;
}

int main()
{
	complex a, b;
	cout << "Complex a: ";
	cin >> a.k >> a.l;
	cout << "Complex b: ";
	cin >> b.k >> b.l;
	Comp_slozh(a, b);
	Comp_umnozh(a, b);
}