#include <iostream>
#include <fstream> 
#include <string>
using namespace std;
int main()
{
    char str2[300];
    char mass[3][41];
    const char p = '\n';
    string path = "C:\\Work\\lab3.2\\File.txt";
    ifstream fin;
    fin.open(path);
    if (!fin.is_open())
    {
        cout << "ERROR\n";
        return 0;
    }
    for (int i = 0; i < 3; i++)
    {
        fin.getline(mass[i], 41 - 1, p);
    }
    strcpy_s(str2, mass[1]);
    cout << "Before sorting: " << str2 << endl;
    char* str = new char[300];
    str = str2;
    int words[150];
    int num, i, j, temp, flag;
    for (num = 0, flag = 1, i = 0; str[i]; i++)
    {
        if (str[i] == ' ')
        {
            str[i] = 0;
            flag = 1;
        }
        else if (flag)
        {
            words[num++] = i;
            flag = 0;
        }  
    }
    for (j = num - 1; j > 0; j--)
        for (i = 0; i < j; i++)
            if (strcmp(&str[words[i]], &str[words[i + 1]]) > 0)
            {
                temp = words[i];
                words[i] = words[i + 1];
                words[i + 1] = temp;
            }
    cout << endl << "After sorting:\n";
    for (i = num - 1; i >= 0; i--)
        cout << &str[words[i]] << endl;
    return 0;
}


