﻿#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
class Table
{
public:
    Table()
    {
        int* size;
        char* color;
    }
    Table(int size1, char* color1)
    {
        if (size1 > 0)
        {
            size = new int;
            *size = size1;
        }
        else
        {
            cerr << "У стола размер больше нуля, введено: " << size1 << ". Выход.\n";
            exit(1);
        }
        color = new char[20];
        strcpy_s(color, 20, color1);
    }
    Table(int size1)
    {
        if (size1 > 0)
        {
            size = new int;
            *size = size1;
        }
        else
        {
            cerr << "У стола размер больше нуля, введено: " << size1 << ". Выход.\n";
            exit(1);
        }
        color = new char[10];
    }
    ~Table()
    {
        delete size;
        delete[] color;
    }
    void show()
    {
        cout << "Table:" << "\n\t size: " << *size << "\n\t color: " << color << "\n";
    }
    int calc_volume()
    {
        return pow(*size, 3);
    }
private:
    int* size;
    char* color;
};

class CompTable : public Table
{
public:
    CompTable()
        : Table()
    {
        int* h;
        char* material;
    }
    CompTable(int size1, char* color1, int h1, char* material1)
        : Table(size1, color1)
    {
        if (h1 > 0)
        {
            h = new int;
            *h = h1;
        }
        else {
            cerr << "У комп. стола высота больше нуля, введена: " << h1 << ". Выход.\n";
            exit(1);
        }
        material = new char[20];
        strcpy_s(material, 20, material1);
    }
    ~CompTable()
    {
        delete h;
        delete[] material;
    }
    int calc_volume_ct()
    {
        return calc_volume() + std::pow(*h, 3);
    }
    void show_ct()
    {
        cout << "CompTable:" << "\n\th = " << *h << "\n\tmaterial: " << material << "\n";
        show();
    }
private:
    int* h;
    char* material;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    char b[] = "brown";
    Table* tab1 = new Table(4, b);
    tab1->show();
    cout << "Объем стола № 1: " << tab1->calc_volume() << "\n";
    delete tab1;
    tab1 = nullptr;
    char w[] = "white"; char wo[] = "wood";
    CompTable* tab2 = new CompTable(4, w, 1, wo);
    tab2->show();
    cout << "Объем стола № 2: " << tab2->calc_volume_ct() << "\n";
    delete tab2;
    tab2 = nullptr;
    return 0;
}