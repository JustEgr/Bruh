#include <iostream>
#include <algorithm>
using namespace std;
class ComplexNumbers
{
private:
	double a, b, i;
public:
	ComplexNumbers(double A = 0, double B = 0)
	{
		a = A;
		b = B;
		i = 1;
	}
	ComplexNumbers(const ComplexNumbers& complex) : a(complex.a), b(complex.b) {}
	void seta(double A)
	{
		a = A;
	}
	void setb(double B)
	{
		b = B;
	}
	void setab(double A, double B)
	{
		a = A;
		b = B;
	}
	double geta()
	{
		return a;
	}
	double getb()
	{
		return b;
	}
	double LengthComplex()
	{
		return abs(sqrt((a * a) + (b * b)));
	}
	friend ComplexNumbers operator+(const ComplexNumbers& c1, const ComplexNumbers& c2)
	{
		return ComplexNumbers(c1.a + c2.a, c1.b + c2.b);
	}
	friend ComplexNumbers operator-(const ComplexNumbers& c1, const ComplexNumbers& c2)
	{
		return ComplexNumbers(c1.a - c2.a, c1.b - c2.b);
	}
	friend ComplexNumbers operator*(const ComplexNumbers& c1, const ComplexNumbers& c2)
	{
		return ComplexNumbers(((c1.a * c2.a) + (c1.b * c2.b) * -1), ((c1.b * c2.a) + (c1.a * c2.b)));
	}
	friend ComplexNumbers operator/(const ComplexNumbers& c1, const ComplexNumbers& c2)
	{
		return ComplexNumbers((((c1.a * c2.a) + (c1.b * c2.b)) / ((c2.a * c2.a) + (c2.b * c2.b))), (((c1.b * c2.a) - (c1.a * c2.b)) / ((c2.a * c2.a) + (c2.b * c2.b))));
	}
	bool operator>(ComplexNumbers& complex)
	{
		return LengthComplex() > complex.LengthComplex();
	}
	bool operator<(ComplexNumbers& complex)
	{
		return LengthComplex() < complex.LengthComplex();
	}
	bool operator==(ComplexNumbers& complex)
	{
		return LengthComplex() == complex.LengthComplex();
	}
	bool operator!=(ComplexNumbers& complex)
	{
		return LengthComplex() != complex.LengthComplex();
	}
	friend ostream& operator<<(ostream& out, const ComplexNumbers& complex)
	{
		if (complex.i == 0)
		{
			if (complex.a == 0 && complex.b == 0) out << "0\n";
			else if (complex.a == 0) out << complex.b << endl;
			else if (complex.b == 0) out << complex.a << endl;
			else if (complex.b > 0) out << complex.a << " + " << complex.b << endl;
			else out << complex.a << " " << complex.b << endl;
		}
		else
		{
			if (complex.a == 0 && complex.b == 0) out << "0\n";
			else if (complex.a == 0) out << complex.b << "*i\n";
			else if (complex.b == 0) out << complex.a << endl;
			else if (complex.b > 0) out << complex.a << " + " << complex.b << "*i\n";
			else out << complex.a << " " << complex.b << "*i\n";
		}
		return out;
	}
	friend istream& operator>> (istream& is, ComplexNumbers& complex)
	{
		is >> complex.a >> complex.b;
		return is;
	}
};

template<class T> class Vector;
template<class T>
istream& operator>> (istream& is, Vector<T>& vector);

template <class T>
class Vector
{
private:
	int size;
	T* x;
public:
	Vector(int NSize = 0, T* Array = NULL)
	{
		size = abs(NSize);
		x = NULL;
		if (NSize != 0)
		{
			x = new T[size];
			for (int i = 0; i < size; i++)
				x[i] = Array[i];
		}
	}
	Vector(const Vector<T>& vector) : x(vector.x), size(vector.size) {}
	void ArrayResize(int NewSize)
	{
		T* Array = new T[NewSize];
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
	void add(T value)
	{
		ArrayResize(size);
		x[size - 1] = value;
	}
	double Scolar(Vector<T> vector)
	{
		return ((x[0] * vector.x[0]) + (x[1] * vector.x[1]));
	}
	double Angle(Vector vector)
	{
		return cos(Scolar(vector) / (LengthVector() * vector.LengthVector()));
	}
	double LengthVector()
	{
		double Summ = 0;
		for (int i = 0; i < size - 1; i++)
			Summ += abs(sqrt((x[i] * x[i]) + (x[i + 1] * x[i + 1])));
		return Summ;
	}
	friend istream& operator>> <T>(istream& is, Vector& vector);
	friend ostream& operator<<(ostream& out, const Vector& vector)
	{
		if (vector.size == 0)
		{
			out << "This array empty.\n" << endl;
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
			cout << "Error, different size vectors.\n";
			exit(0);
		}
		else
		{
			vector.ArrayResize(v1.size);
			for (int i = 0; i < vector.size; i++) vector.x[i] = v1.x[i] + v2.x[i];
		}
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
		return LengthVector() > vector.LengthVector();
	}
	bool operator<(Vector& vector)
	{
		return LengthVector() < vector.LengthVector();
	}
	bool operator==(Vector& vector)
	{
		return LengthVector() == vector.LengthVector();
	}
	bool operator!=(Vector& vector)
	{
		return LengthVector() != vector.LengthVector();
	}
	T& operator[](int index)
	{
		if (size <= index || index < 0)
		{
			cout << "Error, there is no variable with this index\n";
			exit(0);
		}
		else return x[index];
	}
	~Vector() {}
};

template<>
double Vector<ComplexNumbers>::LengthVector()
{
	double Summ = 0;
	for (int i = 0; i < size - 1; i++)
		Summ += abs(sqrt((x[i].geta() * x[i].geta()) + (x[i].getb() * x[i].getb())));
	return Summ;
}
template <>
istream& operator>>(istream& is, Vector<ComplexNumbers>& vector)
{
	for (int i = 0; i < vector.size; i++) if (vector.x[i].geta() == NULL && vector.x[i].geta() != 0)
	{
		is >> vector.x[i];
		return is;
	}
	vector.ArrayResize(vector.size + 1);
	is >> vector.x[vector.size - 1];
	return is;
}
template <class T>
istream& operator>>(istream& is, Vector<T>& vector)
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
template <>
double Vector<ComplexNumbers>::Scolar(Vector<ComplexNumbers> vector)
{
	return ((x[0] * vector.x[0]).geta() + (x[1] * vector.x[1]).geta()) + ((x[0] * vector.x[0]).getb() + (x[1] * vector.x[1]).getb());
}

template <class T>
class Many
{
private:
	int size;
	T* x;
public:
	Many(int Nsize = 0, T* Array = NULL)
	{
		size = abs(Nsize);
		x = NULL;
		if (Nsize != 0)
		{
			x = new T[size];
			for (int i = 0; i < size; i++)
				x[i] = Array[i];
		}
	}
	int relation(Many& many)
	{
		bool rel, cross = false;
		for (int i = 0; i < many.size; i++)
		{
			rel = false;
			for (int j = 0; j < size; j++)
			{
				if (many[i] == x[j])
				{
					cross = true;
					rel = true;
					break;
				}
			}
			if (!rel) break;
		}
		if (!rel)
			for (int i = 0; i < size; i++)
			{
				rel = false;
				for (int j = 0; j < many.size; j++)
				{
					if (x[i] == many[j])
					{
						rel = true;
						break;
					}
				}
				if (!rel) break;
			}
		if (rel) return -1;
		else if (cross) return 1;
		else return 0;
	}
	int getSize()
	{
		return size;
	}
	void ArrayResize(int NewSize)
	{
		T* Array = new T[NewSize];
		for (int i = 0; (i < size) && (i < NewSize); i++)
			Array[i] = x[i];
		size = NewSize;
		delete[]x;
		x = Array;
	}
	bool find(T f)
	{
		for (int i = 0; i < size; i++)
			if (x[i] == f) return true;
		return false;
	}
	int findElement(T f)
	{
		for (int i = 0; i < size; i++)
			if (x[i] == f) return i;
		return -1;
	}
	void insert(T val)
	{
		ArrayResize(size + 1);
		x[size - 1] = val;
	}
	void deleteLast()
	{
		if (size != 0) ArrayResize(size - 1);
	}
	void deleteIndex(int index)
	{
		if (index >= 0 && index < size)
		{
			for (int i = index; i < size - 1; i++)
				x[i] = x[i + 1];
			deleteLast();
		}
		else cout << "Element with such index was not found.\n";
	}
	void deleteDuplicate()
	{
		Many Nmany;
		for (int i = 0; i < size; i++)
			if (!Nmany.find(x[i])) Nmany.insert(x[i]);
		delete[] x;
		x = Nmany.x;
		size = Nmany.size;
		sort(x, x + size);
	}
	Many operator*(Many& many)
	{
		Many Nmany;
		for (int i = 0; i < many.size; i++)
			for (int j = 0; j < size; j++)
				if (many[i] == x[j]) Nmany.insert(many[i]);
		Nmany.deleteDuplicate();
		return Nmany;
	}
	Many operator+(Many& many)
	{
		Many Nmany;
		for (int i = 0; i < many.size; i++)
			Nmany.insert(many[i]);
		for (int j = 0; j < size; j++)
			Nmany.insert(x[j]);
		Nmany.deleteDuplicate();
		return Nmany;
	}
	friend ostream& operator<<(ostream& out, const Many& many)
	{
		if (many.size == 0)
		{
			out << "This array empty.\n" << endl;
			return out;
		}
		else
		{
			for (int i = 0; i < many.size; i++)
			{
				out << i + 1 << ": " << many.x[i] << endl;
			}
			return out;
		}
	}
	friend istream& operator>>(istream& is, Many& many)
	{
		T value;
		is >> value;
		many.insert(value);
		return is;
	}
	T& operator[](int index)
	{
		if (size <= index || index < 0)
		{
			cout << "Error, there is no variable with this index\n";
			exit(0);
		}
		else return x[index];
	}
	bool equal(T Val)
	{
		return false;
	}
	~Many() {}
};
template <>
bool Many<int>::equal(int Val)
{
	return ((Val % 2) == 0);
}

int main()
{
	setlocale(LC_ALL, "Russian"); //задание 1
	//вещественные числа
	cout << "Задание 1. Шаблон класса Вектор.\nТест на вещественных числах работы вектора:\n";
	double s[] = { 1.5,2.7,3.3,4.9,5.1 };
	Vector<double> v1(5, s), v2;
	for (int i = 0; i < 5; i++)
	{
		cin >> v2;
	}
	cout << "вектор 1:\n" << v1 << "вектор 2:\n" << v2
		<< "Сумма: \n" << v1 + v2 << "\n"
		<< "Умножение на число: \n" << v1 * 5 << "\n"
		<< "Скалярное произведение: \n" << v1.Scolar(v2) << "\n"
		<< "Угол м/у векторами: \n" << v1.Angle(v2) << "\n"
		<< "Больше: \n" << (v1 > v2) << "\n"
		<< "Меньше: \n" << (v1 < v2) << "\n";
	//целые числа
	cout << "Тест на целых числах работы вектора:\n";
	int a[] = { 5,7,3,9,1 };
	Vector<int> n1(5, a), n2;
	for (int i = 0; i < 5; i++)
	{
		cin >> n2;
	}
	cout << "вектор 1:\n" << n1 << "вектор 2:\n" << n2
		<< "Сумма: \n" << n1 + n2 << "\n"
		<< "Умножение на число: \n" << n1 * 5 << "\n"
		<< "Скалярное произведение: \n" << n1.Scolar(n2) << "\n"
		<< "Угол м/у векторами: \n" << n1.Angle(n2) << "\n"
		<< "Больше: \n" << (n1 > n2) << "\n"
		<< "Меньше: \n" << (n1 < n2) << "\n";
	//комплексные числа
	cout << "Тест на комплексных числах работы вектора:\n";
	ComplexNumbers c[5] = { ComplexNumbers(1,2),ComplexNumbers(2,3),ComplexNumbers(3,4),ComplexNumbers(4,5),ComplexNumbers(5,6) };
	Vector<ComplexNumbers> k1(5, c), k2;
	for (int i = 0; i < 5; i++)
	{
		cin >> k2;
	}
	cout << "вектор 1:\n" << k1 << "вектор 2:\n" << k2
		<< "Сумма: \n" << k1 + k2 << "\n"
		<< "Умножение на число: \n" << k1 * 5 << "\n"
		<< "Скалярное произведение: \n" << k1.Scolar(k2) << "\n"
		<< "Угол м/у векторами: \n" << k1.Angle(k2) << "\n"
		<< "Больше: \n" << (k1 > k2) << "\n"
		<< "Меньше: \n" << (k1 < k2) << "\n";

	cout << "Задание 2. Шаблон класса множество.\n"; //задание 2
	int z[] = { 1,2,3,4,5 };
	Many<int> ma1(5, z), ma2;
	for (int i = 0; i < 5; i++)
	{
		cin >> ma2;
	}
	cout << "мн-во 1:\n" << ma1 << "мн-во 2:\n" << ma2 << "\n"
		<< "Пересечение множеств: \n" << ma1 * ma2 << "\n"
		<< "Объединение множеств: \n" << ma1 + ma2 << "\n"
		<< "Принадлежность элемента мн-ву: \n" << ma2.find(5) << "\n";
	ma2.deleteIndex(2);
	cout << "Удаление элементов: \n" << ma2 << "\n";
}