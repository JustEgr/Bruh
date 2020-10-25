using namespace std;
class Matrix;
class Vector
{
	friend Matrix;
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
	double LengthVector()
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
class Matrix
{
private:
	int Sx, Sy;
	double** XY;
public:

	void ArrayResize(int NewSize1, int NewSize2)
	{
		double** Array = new double* [NewSize1];
		for (int i = 0; i < NewSize1; i++)
			Array[i] = new double[NewSize2];

		for (int i = 0; (i < Sx) && (i < NewSize1); i++)
			for (int j = 0; (j < Sy) && (j < NewSize2); j++)
				Array[i][j] = XY[i][j];

		for (int i = 0; i < Sx; i++) delete[]XY[i];
		delete[]XY;

		Sx = NewSize1;
		Sy = NewSize2;

		XY = Array;
	}

	void setSize(int NewSize1, int NewSize2)
	{
		XY = new double* [NewSize1];
		for (int i = 0; i < NewSize1; i++)
			XY[i] = new double[NewSize2];

		Sx = NewSize1;
		Sy = NewSize2;
	}

	Matrix(int NSx = 0, int NSy = 0)
	{
		Sx = abs(NSx);
		Sy = abs(NSy);
		XY = NULL;
		if (Sx != 0 && Sy != 0)
		{
			XY = new double* [Sx];
			for (int i = 0; i < Sx; i++)
				XY[i] = new double[Sy];

			for (int i = 0; i < Sx; i++)
				for (int j = 0; j < Sy; j++)
					XY[i][j] = NULL;
		}
	}

	Matrix(const Matrix& matrix) : XY(matrix.XY), Sx(matrix.Sx), Sy(matrix.Sy) {}

	~Matrix() {}

	friend istream& operator>> (istream& is, Matrix& matrix)
	{
		for (int i = 0; i < matrix.Sx; i++)
			for (int j = 0; j < matrix.Sy; j++)
				is >> matrix.XY[i][j];
		return is;
	}

	friend ostream& operator<<(ostream& out, const Matrix& matrix)
	{
		if (matrix.Sx == 0 || matrix.Sy == 0)
		{
			out << "This array empty.\n" << endl;
			return out;
		}
		else
		{
			for (int i = 0; i < matrix.Sx; i++)
			{
				out << endl;
				for (int j = 0; j < matrix.Sy; j++)
				{
					out.width(3);
					out << matrix.XY[i][j] << " | ";
				}
			}
			out << endl;
		}
		return out;
	}

	friend Matrix operator+(const Matrix& m1, const Matrix& m2)
	{
		Matrix matrix;
		if (m1.Sx != m2.Sx || m1.Sy != m2.Sy)
		{
			cout << "Error, different size matrix.\n";
			exit(0);
		}
		else
		{
			matrix.ArrayResize(m1.Sx, m1.Sy);
			for (int i = 0; i < matrix.Sx; i++)
				for (int j = 0; j < matrix.Sy; j++)
					matrix.XY[i][j] = m1.XY[i][j] + m2.XY[i][j];
		}
		return matrix;
	}

	friend Matrix operator*(const Matrix& m1, int a)
	{
		Matrix matrix;
		matrix.ArrayResize(m1.Sx, m1.Sy);
		for (int i = 0; i < matrix.Sx; i++)
			for (int j = 0; j < matrix.Sy; j++)
				matrix.XY[i][j] = m1.XY[i][j] * a;

		return matrix;
	}

	friend Vector operator*(const Matrix& m1, Vector& v1)
	{
		Vector vector;
		vector.ArrayResize(v1.Size());

		if (m1.Sx != v1.Size() || m1.Sy != v1.Size())
		{
			cout << "Error, different size matrix.\n";
			exit(0);
		}
		else
		{
			for (int j = 0; j < v1.Size(); j++)
				for (int i = 0; i < v1.Size(); i++)
					m1.XY[i][j] = m1.XY[i][j] * v1[j];

			for (int i = 0; i < v1.Size(); i++)
				for (int j = 0; j < v1.Size(); j++)
					vector[i] = m1.XY[i][j];
		}
		return vector;
	}

	friend Matrix operator*(const Matrix& m1, const Matrix& m2)
	{
		Matrix matrix;
		if ((m1.Sx != m2.Sy || m1.Sy != m2.Sx) && (m1.Sx != m2.Sx || m1.Sy != m2.Sy))
		{
			cout << "Error, different size matrix.\n";
			exit(0);
		}
		else
		{
			matrix.ArrayResize(m1.Sx, m1.Sy);
			for (int i = 0; i < matrix.Sx; i++)
				for (int j = 0; j < matrix.Sy; j++)
				{
					double sum = 0;
					for (int k = 0; k < matrix.Sy; k++)
						sum += m1.XY[i][k] * m2.XY[k][j];
					matrix.XY[i][j] = sum;
				}
		}
		return matrix;
	}
};