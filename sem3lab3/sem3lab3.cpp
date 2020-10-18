#include <iostream>
#include <cmath>
#include <clocale>
#include <math.h>
using namespace std;

class Vector
{
private:
	int size;
	double* x;
public:
	Vector(double NSize = 0, double* Array = NULL)
	{
		size = abs(NSize);
		x = NULL;
		if (NSize != 0)
		{
			x = new double[size];
			for (int i = 0; i < size; i++)
				x[i] = Array[i];
		}
	}
	Vector(const Vector& vector) : x(vector.x), size(vector.size) {}
	void ArrayResize(int NewSize)
	{
		double* Array = new double[NewSize];
		for (int i = 0; (i < size) && (i < NewSize); i++)
			Array[i] = x[i];
		size = NewSize;
		delete[]x;
		x = Array;
	}
	int Size()
	{
		return size;
	}
	void add(double value)
	{
		ArrayResize(size);
		x[size - 1] = value;
	}
	double Vec_Scolar(Vector vector)
	{
		return ((x[0] * vector.x[0]) + (x[1] * vector.x[1]));
	}
	double Vec_Angle(Vector vector)
	{
		return cos(Vec_Scolar(vector) / (Vec_Length() * vector.Vec_Length()));
	}
	double Vec_Length()
	{
		double Summ = 0;
		for (int i = 0; i < size - 1; i++)
			Summ += abs(sqrt((x[i] * x[i]) + (x[i + 1] * x[i + 1])));
		return Summ;
	}
	friend istream& operator>> (istream& is, Vector& vector)
	{
		for (int i = 0; i < vector.size; i++) if (vector.x[i] == NULL && vector.x[i] != 0)
		{
			is >> vector.x[i];
			return is;
		}
		vector.ArrayResize(vector.size + 1);
		is >> vector.x[vector.size - 1];
		return is;
	}
	friend ostream& operator<<(ostream& out, const Vector& vector)
	{
		if (vector.size == 0)
		{
			out << "Empty.\n" << endl;
			return out;
		}
		else
		{
			for (int i = 0; i < vector.size; i++)
			{
				out << i + 1 << ": " << vector.x[i] << endl;
			}
			return out;
		}
	}
	friend Vector operator+(const Vector& v1, const Vector& v2)
	{
		Vector vector;
		if (v1.size != v2.size)
		{
			cout << "Error, different vectors.\n";
			exit(0);
		}
		else
		{
			vector.ArrayResize(v1.size);
			for (int i = 0; i < vector.size; i++) vector.x[i] = v1.x[i] + v2.x[i];
		}
		return vector;
	}
	friend Vector operator*(const Vector& v1, const Vector& v2)
	{
		Vector vector;
		vector.ArrayResize(v1.size);
		for (int i = 0; i < v1.size; i++) vector.x[i] = v1.x[i] * v2.x[i];
		return vector;
	}
	friend Vector operator*(const Vector& v1, int a)
	{
		Vector vector;
		vector.ArrayResize(v1.size);
		for (int i = 0; i < v1.size; i++) vector.x[i] = v1.x[i] * a;
		return vector;
	}
	bool operator>(Vector& vector)
	{
		return Vec_Length() > vector.Vec_Length();
	}
	bool operator<(Vector& vector)
	{
		return Vec_Length() < vector.Vec_Length();
	}
	bool operator==(Vector& vector)
	{
		return Vec_Length() == vector.Vec_Length();
	}
	bool operator!=(Vector& vector)
	{
		return Vec_Length() != vector.Vec_Length();
	}
	double& operator[](int index)
	{
		if (size <= index || index <= 0)
		{
			cout << "Error, no needed variable number\n";
			exit(0);
		}
		else return x[index];
	}
	~Vector() {}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	int k;
	double s[] = { 1,2,3 };
	Vector vec1, vec2;
	cout << "Enter the coordinates of vector 1:\n";
	for (int i = 0; i < 3; i++)
	{
		cin >> vec1;
	}
	cout << "Enter the coordinates of vector 2 :\n";
	for (int i = 0; i < 3; i++)
	{
		cin >> vec2;
	}
	cout << "\nVector 1:\n" << vec1 << "Vector 2:\n" << vec2
		<< "\nVectors' summ:\n " << vec1 + vec2
		<< "\nVectors' multiplication:\n " << vec1 * vec2
		<< "\nMultiplication of vector and a number:\nEnter the number: "; cin >> k;
	cout << vec1 * k
		<< "\nVectors' scalar multiplication:" << vec1.Vec_Scolar(vec2) << "\n"
		<< "\nAngle: " << vec1.Vec_Angle(vec2) << "\n"
		<< "\nVector 1 > Vector 2: " << (vec1 > vec2) << "\n"
		<< "\nVector 1 < Vector 2: " << (vec1 < vec2) << "\n"
		<< "\nEquality: " << (vec1 == vec2) << "\n"
		<< "\nInequality: " << (vec1 != vec2) << "\n";
	return 0;
}