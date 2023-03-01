#include <iostream>
#include <cmath>
using namespace std;
enum Color
{
	console_blue=0x99,
	console_green=0xAA,
	console_red=0xCC,
	console_default=0x07
};
class Shape
{
protected:
	Color color;
	
public:
	Shape(Color color) :color(color) {};
	virtual ~Shape() {}

	virtual double get_area()const=0;
	virtual double get_perimetr()const = 0;
	virtual void draw()const = 0;
	
};
class triangle :public  Shape // треугольник
{
	double a; // 1 сторона
	double b; // 2 сторона
	double c; // 3 сторона
public:

	double get_perimetr()const
	{
		return a + b + c;
	}
	double get_area()const
	{
		return sqrt(get_perimetr() / 2 * (get_perimetr() / 2 - a) * (get_perimetr() / 2 - b) * (get_perimetr() / 2 - c)); // формула Герона.
	};
	void draw()const
	{
		for (size_t i = 0; i < get_perimetr(); i++)
		{
			
		}
	}

};
class circle:Shape // круг
{
	Color color;
	const double pi = 3.14; // число Пи
	double R; // Радиус 
public:
	double get_perimetr()const // Периметр/длина окружности
	{
		return 2 * pi * R;
	}
	double get_area()const // Площадь периметра
	{
		return (pow(get_perimetr(), 2) / 4 * pi); // Площадь через периметр
	}
	void draw()const
	{

	}
};
class square :Shape // квадрат
{
	double a; // сторона
public:
	double get_perimetr()const
	{
		return 4 * a;
	}
	double get_area()const
	{
		return pow(a, 2);
	}
	void draw()const
	{

	}

};
class rectangle :Shape // прямоугольник
{
	double a;
	double b;
public:
	double get_area()const
	{
		return a * b;
	}
	double get_perimetr()const
	{
		return 2 * (a + b);
	}
	void draw()const
	{

	}

};

void main()
{
	setlocale(LC_ALL, "");
}