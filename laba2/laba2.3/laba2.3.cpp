#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <random>
#include <Windows.h>
using std::cout;
using std::cin;
using std::endl;
void MENU();                                                       //меню
void fieldView(int** a, int n, int m);                             //показывание поля
int livingPoints(int** a, int n, int m);                           //живые точки
void neighborhood(int nb[][2], int x, int y);                      //соседние точки
int amountLivingNB(int** a, int n, int m, int x, int y);           //кол-во живых соседей
void NextGen(int** a, int** a1, int n, int m);                     //следующее поколение точек
void CopyCopy(int** a, int** a1, int n, int m);                    //копирование прошлого поля
int FieldsCompare(int** a, int** a1, int n, int m);                //сравнение полей
int main()
{
	int n, m, key;
    MENU();
    cout << endl << ":"; cin >> key;
    srand(time(NULL)); //выбор способа задания размера поля
    do
        switch (key)
        {
        case 1:
            n = rand() % 21;
            m = rand() % 21;
            break;
        case 2:
            cout << "Enter n and m\n";
            cin >> n;
            cin >> m;
            break;
        case 0:
            cout << "Goodbye! See you soon!\n";
            break;
        default:
            cout << "ERROR!\n";
            break;
        }
    while (n < 4 || m < 4);
    cout << "\nSize of the field: " << n << " rows and " << m << " columns\n";
    int** field; //задаем поле (многомерный массив)
    field = new int* [n];
    for (int i = 0; i < n; i++)
        field[i] = new int[m];
    std::random_device rd; //заполнение случайно точками
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int num = dis(gen);
            if (num % 2 == 0)
                field[i][j] = 1;
            else
                field[i][j] = 0;
        }
    int** PreviousField; //задаем поле для запоминания предыдущего поколения
    PreviousField = new int* [n];
    for (int i = 0; i < n; i++)
        PreviousField[i] = new int[m];
    int livingpoints = -1;
    bool Edem = false;
    do
    {
        fieldView(field, n, m);                                   //показ поля
        CopyCopy(field, PreviousField, n, m);                     //копируем поле
        NextGen(field, PreviousField, n, m);                      //генерируем новое
        Edem = FieldsCompare(field, PreviousField, n, m) == 0;    //сравниваем поля
        livingpoints = livingPoints(field, n, m);                 //проверяем количество живых клеток
        if (Edem)
            cout << "Edem Garden\n";                              //Эдемов сад
        if (livingpoints == 0)
            cout << "YOU DIED\n";                                 //все здохли. конец.
        Sleep(2000); //прерывание цикла, чтобы пользователь успел увидеть поле
    } while (livingpoints != 0 || !Edem);
	return 0;
}

void MENU() //меню
{
    cout << "\t!HELLO THERE!\n";
    cout << "Choose, how the program will work:\n";
    cout << endl;
    cout << "1 - random size\n";
    cout << "2 - you will set the size\n";
    cout << "0 - exit\n";
}

void fieldView(int** a, int n, int m) //вывод поля
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
                cout << '*';
            else
                cout << ' ';
            cout << ' ';
        }
        cout << endl;
    }
}

int livingPoints(int** a, int n, int m) //счет живых точек
{
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 1)
                count++;
    return count;
}

void neighborhood(int nb[][2], int x, int y) //координаты соседей точки
{
    int k = 0;
    for (int i = x - 1; i <= x + 1; i++)
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (i == x && j == y)
                continue;
            nb[k][0] = i;
            nb[k][1] = j;
            k++;
        }
}

int amountLivingNB(int** a, int n, int m, int x, int y) //кол-во живых соседей у клетки[x][y]
{
    int count = 0;
    int nb[8][2];
    int x_, y_;
    neighborhood(nb, x, y);
    for (int i = 0; i < 8; i++)
    {
        x_ = nb[i][0];
        y_ = nb[i][1];
        if (x_ < 0 || y_ < 0)
            continue;
        if (x_ >= n || y_ >= m)
            continue;
        if (a[x_][y_] == 1)
            count++;
    }
    return count;
}

void NextGen(int** a, int** a1, int n, int m) //следующее поколение точек
{
    int livingNB, p;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            p = a1[i][j];
            livingNB = amountLivingNB(a1, n, m, i, j);
            if (p == 0)
            {
                if (livingNB == 3)
                    a[i][j] = 1;
            }
            else
                if (livingNB < 2 || livingNB > 3)
                    a[i][j] = 0;
        }
}

void CopyCopy(int** a, int** a1, int n, int m) //копирование прошлого поля
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a1[i][j] = a[i][j];
}

int FieldsCompare(int** a, int** a1, int n, int m) //сравнение полей
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a != a1)
                return -1;
    return 0;
}