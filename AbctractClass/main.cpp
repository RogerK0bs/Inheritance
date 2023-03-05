#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

namespace Geometry
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,
		white = 0x00FFFFFF,

		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_default = 0x07
	};
	class Shape
	{
	protected:
		Color color;
		int start_x;
		int start_y;
		int line_width;

		static const int MIN_START_X = 50;
		static const int MIN_START_Y = 50;
		static const int MAX_START_X = 1000;
		static const int MAX_START_Y = 550;
		static const int MIN_SIZE = 50;
		static const int MAX_SIZE = 550;
		static const int MIN_LINE_WIDTH = 1;
		static const int MAX_LINE_WIDTH = 25;

	public:
		int get_start_x()const
		{
			return start_x;
		}
		int get_start_y()const
		{
			return start_y;
		}
		int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(int start_x)
		{
			if (start_x < MIN_START_X)start_x = MIN_START_X;
			if (start_x > MAX_START_X)start_x = MAX_START_X;
			this->start_x = start_x;
		}
		void set_start_y(int start_y)
		{
			if (start_y < MIN_START_Y)start_y = MIN_START_Y;
			if (start_y > MAX_START_Y)start_y = MAX_START_Y;
			this->start_y = start_y;
		}
		void set_line_width(int line_width)
		{
			if (line_width < MIN_LINE_WIDTH)line_width = MIN_LINE_WIDTH;
			if (line_width > MAX_LINE_WIDTH)line_width = MAX_LINE_WIDTH;
			this->line_width = line_width;
		}

		Shape(Color color, int start_x, int start_y, int line_width) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
			this;
		}
		virtual ~Shape() {}

		virtual double get_area()const = 0;
		virtual double get_perimetr()const = 0;
		virtual void draw()const = 0;

		virtual void info()const
		{
			cout << "S = " << get_area() << endl;
			cout << "P = " << get_perimetr() << endl;
			draw();
		}

	};
	class triangle :public  Shape // треугольник
	{
		double a; // 1 сторона
		double b; // 2 сторона
		double c; // 3 сторона
	public:

		double Get_a()
		{
			return a;
		}
		double Get_b()
		{
			return b;
		}
		double Get_c()
		{
			return c;
		}
		void set_a(double side)
		{
			if (side < 5)side = 5;
			if (side > 15)side = 15;
			this->a = side;
		}
		void set_b(double side)
		{
			if (side < 5)side = 5;
			if (side > 15)side = 15;
			this->b = side;
		}
		void set_c(double side)
		{
			if (side < 5)side = 5;
			if (side > 15)side = 15;
			this->c = side;
		}
		triangle(double a, double b, double c, Color color, int start_x, int start_y, int line_width) :Shape(color, start_x, start_y, line_width)
		{
			set_a(a);
			set_b(b);
			set_c(c);
		}
		~triangle() {};
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
			HWND hwnd = GetConsoleWindow(); // получение обработчика окна консоли
			HDC hdc = GetDC(hwnd);			// Получаем контекст устройства окна консоли
			HPEN hPen = CreatePen(PS_SOLID, 5, color); // Pen () - карандаш, рисует контур фигуры
													  // PS_SOLID - сплошная линия
													  // 5 - толщина линии в 5 пикселей
			HBRUSH hBrush = CreateSolidBrush(color);
			//Brush - кисть, рисует заливку замкнутой фигуры

			//Выбираем чем рисовать:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			// Когда все инструменты созданы и выбраны можно вызывать функцию для рисования нужной фигуры: 
		/*	::LineTo(hdc, a*50,a*100 );
			::LineTo(hdc, b*50,b*100);
			::LineTo(hdc, c*50, c*100 );*/

			MoveToEx(hdc, start_x, start_y,NULL);
			LineTo(hdc,start_x+20,start_y+20);
			LineTo(hdc,start_x+40,start_y+40);
			LineTo(hdc,start_x+60, start_y+60);
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);// освобождаем контекст устройства
		}

	};
	class circle :Shape // круг
	{
		Color color;
		const double pi = 3.14; // число Пи
		double R; // Радиус 
	public:
		circle(double R, Color color, int start_x, int start_y, int line_width) :Shape(color, start_x, start_y, line_width)
		{
			set_R(R);
		}
		~circle() {};
		double get_R()const
		{
			return R;
		}
		void set_R(double R)
		{
			if (R < 5)R = 5;
			if (R > 15)R = 15;

			this->R = R;
		}
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
			HWND hwnd = GetConsoleWindow(); // получение обработчика окна консоли
			HDC hdc = GetDC(hwnd);			// Получаем контекст устройства окна консоли
			HPEN hPen = CreatePen(PS_SOLID, line_width, color); // Pen () - карандаш, рисует контур фигуры
													  // PS_SOLID - сплошная линия
													  // 5 - толщина линии в 5 пикселей
			HBRUSH hBrush = CreateSolidBrush(color);
			//Brush - кисть, рисует заливку замкнутой фигуры

			//Выбираем чем рисовать:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			// Когда все инструменты созданы и выбраны можно вызывать функцию для рисования нужной фигуры: 
			::Ellipse(hdc, start_x, start_y, start_x + 2*R, start_y + 2*R);

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);// освобождаем контекст устройства
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "R = " << R << endl;
			Shape::info();
		}
	};
	class square :public Shape // квадрат
	{
		double a; // сторона
	public:
		double get_a()const
		{
			return a;
		}
		void set_a(double side)
		{
			if (side < 5)side = 5;
			if (side > 20)side = 20;
			this->a = side;
		}
		square(double a, Color color, int start_x, int start_y, int line_width) :Shape(color, start_x, start_y, line_width)
		{
			set_a(a);
		}
		~square() {}
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
			HWND hwnd = GetConsoleWindow(); // получение обработчика окна консоли
			HDC hdc = GetDC(hwnd);			// Получаем контекст устройства окна консоли
			HPEN hPen = CreatePen(PS_SOLID, line_width, color); // Pen () - карандаш, рисует контур фигуры
													  // PS_SOLID - сплошная линия
													  // 5 - толщина линии в 5 пикселей
			HBRUSH hBrush = CreateSolidBrush(color);
			//Brush - кисть, рисует заливку замкнутой фигуры

			//Выбираем чем рисовать:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			// Когда все инструменты созданы и выбраны можно вызывать функцию для рисования нужной фигуры: 
			::Rectangle(hdc, start_x, start_y, start_x + a, start_y + a);

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);// освобождаем контекст устройства

		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны a = " << a << endl;
			Shape::info();
		}
	};
	class Rectangle :public Shape // прямоугольник
	{
		double a;
		double b;
	public:
		double Get_a()const
		{
			return a;
		}
		double Get_b()const
		{
			return b;
		}
		void set_a(double side1)
		{
			if (side1 < 5)side1 = 5;
			if (side1 > 20)side1 = 20;
			this->a = side1;
		}
		void set_b(double side2)
		{
			if (side2 < 5)side2 = 5;
			if (side2 > 20)side2 = 20;
			this->b = side2;
		}
		Rectangle(double a, double b, Color color, int start_x, int start_y, int line_width) :Shape(color, start_x, start_y, line_width)
		{
			set_a(a);
			set_b(b);
		}
		~Rectangle() {}
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
			/*	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, color);
				for (size_t i = 0; i < b; i++)
				{
					for (size_t j = 0; j < a; j++)
					{
						cout << "@";
					}
					cout << endl;
				}
				SetConsoleTextAttribute(hConsole, Color::console_default);*/
			HWND hwnd = GetConsoleWindow(); // получение обработчика окна консоли
			HDC hdc = GetDC(hwnd);			// Получаем контекст устройства окна консоли
			HPEN hPen = CreatePen(PS_SOLID , line_width, color); // Pen () - карандаш, рисует контур фигуры
													  // PS_SOLID - сплошная линия
													  // 5 - толщина линии в 5 пикселей
			HBRUSH hBrush = CreateSolidBrush(color);
			//Brush - кисть, рисует заливку замкнутой фигуры

			//Выбираем чем рисовать:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			// Когда все инструменты созданы и выбраны можно вызывать функцию для рисования нужной фигуры: 
			::Rectangle(hdc, start_x, start_y, start_x + a, start_y + b);

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);// освобождаем контекст устройства
		}
		void info()const
		{
			cout << "a = " << a << endl;
			cout << "b = " << b << endl;
			Shape::info();
		}
	};
};

void main()
{
	setlocale(LC_ALL, "");

	Geometry::square square(200, Geometry::Color::red, 300, 50, 5);
	square.info();

	Geometry::Rectangle rect(120, 75, Geometry::Color::blue, 550, 50, 8);
	rect.info();

	Geometry::circle circle(100, Geometry::Color::blue, 800, 50, 5);
	circle.info();

	Geometry::triangle triangle(10,13,5, Geometry::Color::green, 500, 150, 2);
	triangle.info();

}