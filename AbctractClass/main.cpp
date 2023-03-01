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
class triangle :public  Shape // �����������
{
	double a; // 1 �������
	double b; // 2 �������
	double c; // 3 �������
public:

	double get_perimetr()const
	{
		return a + b + c;
	}
	double get_area()const
	{
		return sqrt(get_perimetr() / 2 * (get_perimetr() / 2 - a) * (get_perimetr() / 2 - b) * (get_perimetr() / 2 - c)); // ������� ������.
	};
	void draw()const
	{
		for (size_t i = 0; i < get_perimetr(); i++)
		{
			
		}
	}

};
class circle:Shape // ����
{
	Color color;
	const double pi = 3.14; // ����� ��
	double R; // ������ 
public:
	double get_perimetr()const // ��������/����� ����������
	{
		return 2 * pi * R;
	}
	double get_area()const // ������� ���������
	{
		return (pow(get_perimetr(), 2) / 4 * pi); // ������� ����� ��������
	}
	void draw()const
	{

	}
};
class square :Shape // �������
{
	double a; // �������
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
class rectangle :Shape // �������������
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