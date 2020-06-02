#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct bookinfo //структура инфы о книге
{
	string number = " "; //номер чит. билета
	string title = " "; //название книги
	string surname = " "; //фамилия автора
	float price = 0; //цена книги
};

bool cmpByAuthor(const bookinfo& r1, const bookinfo& r2) //сравнение по фамилии автора
{
	return r1.surname < r2.surname;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string x;
	bookinfo s;
	ifstream fin;
	fin.open("File.txt");
	int n(0);
	if (fin.is_open())
	{
		while (!fin.eof()) //узнаем, сколько книг всего
		{
			string s;
			getline(fin, s);
			n++;
		}
	}
	bookinfo* a = new bookinfo[n];
	fin.seekg(0, ios_base::beg);
	for (size_t i = 0; i < n; i++) //заносим данные в массив
	{
		getline(fin, x);
		istringstream iss(x);
		iss >> s.number >> s.title >> s.surname >> s.price;
		a[i] = s;
	}
	cout << "Информация о всех взятых книгах:\nНомер-Автор-Название-Цена:\n" << endl;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i].number != "NOTTAKEN")
		{
			cout << a[i].number << " "
				<< a[i].surname << " "
				<< a[i].title << " "
				<< a[i].price << " " << endl;
		}
	}
	cout << "\nИнформация о книгах автора Толстого, которые не взяли:\nАвтор-Название-Цена:\n" << endl;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i].number == "NOTTAKEN" && a[i].surname == "Tolstoj")
		{
			cout << a[i].surname << " "
				<< a[i].title << " "
				<< a[i].price << " " << endl;
		}
	}
	cout << "\nИнформация о книгах, чья стоимость не превышает 1000р, но больше 100р:\nАвтор-Название-Цена:\n" << endl;
	for (size_t i = 0; i < n; i++)
	{
		sort(a, a + n, cmpByAuthor);
		if (a[i].price < 1000 && a[i].price > 100)
		{
			cout << a[i].surname << " "
				<< a[i].title << " "
				<< a[i].price << " " << endl;
		}
	}
}