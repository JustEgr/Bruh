#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int a, b, n=0, y=0, k;
	int* mas;
	mas = new int[n];
	cout << "Enter the size of diapazone\n"; cin >> a; cin >> b; cout << endl;
	for (int i = a; i < b; i++)
	{
		
		mas[i] = rand() % 10 % 2 == 0 ? -1 * rand() % 10 : 1 * rand() % 10;
		cout << mas[i] << "\n";
	}
	cout << "Enter k:"; cin >> k;
	for (int i = a; i < b; i++)
	{
		int p = 1, x = mas[i];
		while (x > 0)
		{
			p = p * 10;
			x = x / 10;
			mas[i] = k * p + mas[i];
		}
		cout << mas[i] << "\n";
	}
	return 0;
}