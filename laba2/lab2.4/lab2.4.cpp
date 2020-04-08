#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;
void MENU();
void cin_test_matrix(float** matrix, float* x, int n);
void cin_rand_matrix(float** matrix, float* x, int n);
void which_row_is_null(float** matrix, int n);
void cout_matrix(float** matrix, float* x, int n);
float* gauss_method(float** matrix, float* x, int n);
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    float** matrix, * x, * y;
    cout << "Введите количество уравнений: "; cin >> n;
    matrix = new float* [n];
    x = new float[n];
    int key = 1;
    srand(time(NULL));
    do
    {
        MENU();
        cout << endl << ":"; cin >> key;
        switch (key)
        {
        case 1:
            cin_test_matrix(matrix, x, n);
            break;
        case 2:
            cin_rand_matrix(matrix, x, n);
            break;
        case 3:
            cin_test_matrix(matrix, x, n);
            which_row_is_null(matrix, n);
            break;
        default:
            cout << "ERROR!\n";
            break;
        }
    } while (key == 0 || key > 3);
    cout << endl;
    cout_matrix(matrix, x, n);
    y = gauss_method(matrix, x, n);
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << "x[" << i << "] = " << y[i] << endl;
    return 0;
}

void MENU() //меню
{
    cout << "\nChoose the matrix for testing:\n";
    cout << endl;
    cout << "1 - TEST MATRIX (110% works(maybe...))\n";
    cout << "2 - RANDOM MATRIX\n";
    cout << "3 - NULL MATRIX\n";
}

void cin_test_matrix(float** matrix, float* x, int n) //ручной ввод матрицы
{
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new float[n];
        for (int j = 0; j < n; j++)
        {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "y[" << i << "] = ";
        cin >> x[i];
    }
}

void cin_rand_matrix(float** matrix, float* x, int n) //рандом ввод матрицы
{
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new float[n];
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = (rand() % 10) - (rand() % +10);
        }
    }
    for (int i = 0; i < n; i++)
    {
        x[i] = (rand() % 100) - (rand() % +100);
    }
}

void which_row_is_null(float** matrix, int n) //нахождение нулевой строки
{
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < n; j++)
        {
            if (matrix[i][j] != 0)
                break;
        }
        if (j == n)
            cout << "Null row is the row number " << i << endl;
    }
}

void cout_matrix(float** matrix, float* x, int n) //вывод системы уравнений
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "*x" << j;
            if (j < n - 1)
                cout << " + ";
        }
        cout << " = " << x[i] << endl;
    }
    return;
}

float* gauss_method(float** matrix, float* x, int n) //метод гаусса
{
    float* y, max;
    int k, index;
    const float eps = 0.00001;  // точность
    y = new float[n];
    k = 0;
    while (k < n)
    {
        max = abs(matrix[k][k]);
        index = k;
        for (int i = k + 1; i < n; i++)
        {
            if (abs(matrix[i][k]) > max)
            {
                max = abs(matrix[i][k]);
                index = i;
            }
        }
        // Перестановка строк
        if (max < eps)
        {
            // нет ненулевых диагональных элементов
            cout << "Решение получить невозможно из-за нулевого столбца ";
            cout << index << " матрицы A" << endl;
            return 0;
        }
        for (int j = 0; j < n; j++)
        {
            float temp = matrix[k][j];
            matrix[k][j] = matrix[index][j];
            matrix[index][j] = temp;
        }
        float temp = x[k];
        x[k] = x[index];
        x[index] = temp;
        for (int i = k; i < n; i++)
        {
            float temp = matrix[i][k];
            if (abs(temp) < eps) continue;
            for (int j = 0; j < n; j++)
                matrix[i][j] = matrix[i][j] / temp;
            x[i] = x[i] / temp;
            if (i == k)  continue;
            for (int j = 0; j < n; j++)
                matrix[i][j] = matrix[i][j] - matrix[k][j];
            x[i] = x[i] - x[k];
        }
        k++;
    }
    for (k = n - 1; k >= 0; k--)
    {
        y[k] = x[k];
        for (int i = 0; i < k; i++)
            x[i] = x[i] - matrix[i][k] * y[k];
    }
    return y;
}