#include <iostream>
#include <fstream> 
#include <string>

using namespace std;
int main()
{
	char str1[100];
	char str2[100];                                 //"строки"
	char str3[100];
	char mass[3][41];
	const char p = '\n';
	string path = "C:\\Work\\lab3.2\\File.txt";     //НУЖНО ЛИШЬ ЧТОБЫ СЧИТАТЬ ФАЙЛ, НЕ БЕЙТЕ У МЕНЯ В ПЕРВОЙ ЛАБЕ ТАКАЯ ШТУКА ПРИМЕНЯЛАСЬ
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "ERROR\n";
		return 0;
	}
	for (int i = 0; i < 3; i++)
	{
		fin.getline(mass[i], 41 - 1, p);            //вносим в массив данные с файла
	}
	char substr[100] = "programming";               //искомое слово
	char* temp = str1;                              //установка указателя на начало строки
	int n = 0;                                      //счетчик
	strcpy_s(str1, mass[0]);                        //копируем строку из массива
	cout << str1 << endl;
	while ((temp = strstr(temp, substr)) != NULL)   //цикл поиска вхождения подстроки до тех пор,
	{                                               //пока ф-я strstr не вернет NULL - значит искать больше нечего
		n++;
		temp++;
	}
	temp = str2;                                    //повторяем действия, которые делали с 1-ой строкой
	strcpy_s(str2, mass[1]);
	cout << str2 << endl;
	while ((temp = strstr(temp, substr)) != NULL)
	{
		n++;
		temp++;
	}
	temp = str3;
	strcpy_s(str3, mass[2]);
	cout << str3 << endl;
	while ((temp = strstr(temp, substr)) != NULL)
	{
		n++;
		temp++;
	}
	cout << "\nThe word programming was met " << n << " times.\n";
	return 0;
}
