#include <iostream>
#include <cmath>
#include "Header1.h"
using namespace std;

int main()
{
	int k;
	double s[] = { 1,2,3 };
	Matrix Matr1(3, 3), Matr2;
	Vector vec1;
	Matr2.setSize(3, 3);
	cout << "Enter the Matrix 1:\n"; cin >> Matr1;
	cout << "Enter the Matrix 2:\n"; cin >> Matr2;
	cout << "Matrix 1:\n" << Matr1
		<< "Matrix 2:\n" << Matr2 << "\n"
		<< "Matrixes' summ: " << Matr1 + Matr2 << "\n"
		<< "Matrix's multiplication on the number: \n"
		<< "Enter the number: "; cin >> k;
	cout << Matr1 * k << "\n"
		<< "Matrixes's multiplication: " << Matr1 * Matr2 << "\n"
		<< "Matrix's multiplication on the vector:\n";
	for (int i = 0; i < 3; i++)
	{
		cin >> vec1;
	}
	cout << "Vector: \n" << vec1 << "\n" << Matr1 * vec1;
}