#include<iostream>
// Пперегрузка operator (операции +, -, *, /). Двух точек с координатами x и y
class Fraction
{
private:
	double _x;
	double _y;
public:
	Fraction(double x, double y) : _x{x}, _y{y}{ }

	void Show()
	{
		std::cout << '(' << _x << ',' << _y << ')' << std::endl;
	}
	// Перегрузка оператора (+) с помощью friend функции (Имеет доступ к private полям)
	friend const Fraction operator+(const Fraction& point1,	const Fraction& point2)
	{
		return (point1, point2);
	}

	// Умножение точки (1,1) На число value
	friend const Fraction operator+(const Fraction& point, double value)
	{
		return Fraction(point._x * value, point._y * value);
		//return point + value;
	}

	// Унарный минус Перегрузка оператора (-) изменение знака точки На противоположный
	const Fraction operator-()
	{
		return Fraction(-_x, -_y);
	}

	// Перегрузка оператора (-) Вычитание точек по координатам
	friend const Fraction operator-(const Fraction& point1, const Fraction& point2)
	{
		return Fraction(point1._x - point2._x, point1._y - point2._y);
	}

	// Перегрузка оператора (*)  Умножение двух точек 
	friend const Fraction operator*(const Fraction& point1, const Fraction& point2)
	{
		return Fraction(point1._x * point2._x, point1._y * point2._y);
	}

	// Перегрузка оператора (*) Координаты точки (1,1) на число  value
	friend const Fraction operator*(const Fraction& point, double value)
	{
		//return Fraction(point._x * value, point._y * value);
		return point * value;
	}

	// Перегрузка оператора (/) Деление двух точек
	friend const Fraction operator/(const Fraction & point1, const Fraction & point2)
	{
		return Fraction(point1._x / point2._x, point1._y / point2._y);
	}

	// Деление координаты точки (1,1) на число value
	friend const Fraction operator/(const Fraction& point, double value)
	{
		//return Fraction(point._x / value, point._y / value);
		return point / value;
	}
};

int main()
{
	Fraction A(2.2, 4.5);
	Fraction B(4.8, 5.5);
	double a = 10;


	Fraction C1 = (A,a);
	C1.Show();

	/*Fraction C = A - B;
	C.Show();

	Fraction D = (A * B);
	D.Show();

	Fraction E = (A / B);
	E.Show();

	Fraction K = (A + B);
	K.Show();

	C.operator-();
	C.Show();	*/
	
	

	/*A.operator-();
	A.Show();
	B.operator-();
	B.Show();*/


	return {};
}