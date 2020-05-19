#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

static void RecursionSel(int* mas, int n);

int main()
{
    int n;
    cout << "Enter n:" << endl; cin >> n;
    int* mas;
    mas = new int[n];
    int key = 1;
    cout << "1 - rand\n2 - manual\n"; //выбрать ввод данных в массив
    cin >> key;
    srand(time(NULL));
    switch (key)
    {
    case 1:
        for (int i = 0; i < n; i++)
            mas[i] = (rand() % 10) - (rand() % +10); //ранд
        break;
    case 2:
        for (int i = 0; i < n; i++)
        {
            cout << "Enter Mas[" << i + 1 << "]: "; //ручной ввод
            cin >> mas[i];
        }
        break;
    default:
        cout << "No u\n";
        break;
    }
    cout << endl;
    RecursionSel(mas, n); //сортировка
    for (int i = 0; i < n; i++)
        cout << "Mas[" << i + 1 << "]: " << mas[i] << endl; //вывод
    return 0;
}

static void RecursionSel(int* mas, int n)
{
    if (n == 1)
        return;
    int max = INT_MIN; //задается самое мин. знач., чтобы сравнивать с эл-и массива
    int temp; //запоминающая переменная элемента
    int i1 = 0; //запоминающая переменная индекса элемента
    for (int i = 0; i < n - 1; i++)
        if (mas[i] > max)
        {
            max = mas[i];
            i1 = i;
        }
    if (max > mas[n - 1]) //сама сортировка
    {
        temp = mas[n - 1];
        mas[n - 1] = mas[i1];
        mas[i1] = temp;
    }
    RecursionSel(mas, n - 1); //РеКуРсЕя
}