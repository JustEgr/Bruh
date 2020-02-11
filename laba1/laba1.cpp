#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

int main()
{
	int* mass;
	int k;
	cout << "Enter the size of massive:"; cin >> k;
	mass = new int[k];
	string path = "C:\\Work\\laba1\\Text1.txt";
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "ERROR\n";
		return 0;
	}
	for (int i = 0; i < k; i++)
		fin >> mass[i];
	for (int i = 0; i < k; i++)
		cout << mass[i] << "\n";
}