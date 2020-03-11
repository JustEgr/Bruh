#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

int main()
{
	int size = 0, a;
	ifstream input("Text1.txt");
	while (input >> a)
		size++;
	int* mass;
	int k;
	cout << "Enter k:"; cin >> k;
	mass = new int[size];
	string path = "C:\\Work\\laba1\\Text1.txt";
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "ERROR\n";
		return 0;
	}
	for (int i = 0; i < size; i++)
		if (mass[i] < k)
			fin >> mass[i];
	int temp;
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (mass[j] > mass[j + 1])
			{
				temp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = temp;
			}
	for (int i = 0; i < size; i++)
		if (mass[i] < k)
			cout << mass[i] << "\n";
}

