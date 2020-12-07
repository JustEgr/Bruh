#include <iostream>
using namespace std;
class Figure
{
public:
    virtual double CalcArea() const = 0;
    virtual void Show() const = 0;
    virtual ~Figure() {}
};
class Square : public Figure
{
    double a;
public:
    Square(double _a) : a(_a) {}
    ~Square() {}
    double CalcArea() const
    {
        return a * a;
    }
    void Show() const
    {
        cout << "Квадрат\n";
    }
};
class Circle : public Figure
{
    double r;
public:
    Circle(double _r) : r(_r) {}
    ~Circle() {}
    double CalcArea() const
    {
        return 3.14 * r * r;
    }
    void Show() const
    {
        cout << "Круг/Окружность/КРУЖОК\n";
    }
};
class Rectangle : public Figure
{
    double a, b;
public:
    Rectangle(double _a, double _b) : a(_a), b(_b) {}
    ~Rectangle() {}
    double CalcArea() const
    {
        return a * b;
    }
    void Show() const
    {
        cout << "Треугольник\n";
    }
};
int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, c, d, h, s, key;
    Figure* figure[3];
    cout << "0 - Квадрат;\n1 - Круг;\n2 - Треугольник;\n";
    cin >> key;
    switch (key)
    {
        case 0:
            cout << "Введите значения, не равные нулю: ";
            cin >> a; cin >> h;
            figure[0] = new Square(a);
            figure[0]->Show();
            s = figure[0]->CalcArea();
            s = s * h;
            cout << "Площадь фигуры: " << figure[0]->CalcArea() << "\nОбъем обобщенного цилиндра: " << s;
            delete figure[0];
            cout << "\n";
            break;
        case 1:
            cout << "Введите значения, не равные нулю: ";
            cin >> b; cin >> h;
            figure[1] = new Circle(b);
            figure[1]->Show();
            s = figure[1]->CalcArea();
            s = s * h;
            cout << "Площадь фигуры: " << figure[1]->CalcArea() << "\nОбъем обобщенного цилиндра: " << s;
            delete figure[1];
            cout << "\n";
            break;
        case 2:
            cout << "Введите два значения, не равных нулю: ";
            cin >> c; cin >> d; cin >> h;
            figure[2] = new Rectangle(c, d);
            figure[2]->Show();
            s = figure[2]->CalcArea();
            s = s * h;
            cout << "Площадь фигуры: " << figure[2]->CalcArea() << "\nОбъем обобщенного цилиндра: " << s;
            delete figure[2];
            cout << "\n";
            break;
        default:
            cout << "Неправильно введено число!\nПопробуйте в другой раз!\n";
            break;
    }
    return 0;
}