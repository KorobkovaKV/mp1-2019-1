#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <locale.h> 
#include <iostream> 
using namespace std;

class Taylor_series
{ 
	char *S;
	int len;
	double N; // число членов последовательности 
public:

	Taylor_series(double n = 0)
	{
		N = n;
	}

	void set_numbers(double n)
	{
		N = n;
	}

	char* get_function(int y)
	{
		char *s = { 0 };
		if (y == 1)
			s = "Экспонента";
		if (y == 2)
			s = "Синус";
		if (y == 3)
			s = "Косинус";
		if (y == 4)
			s = "Гиперболический косинус";
		return s;
	}

	void get_numbers()
	{
		cout << "Число членов ряда: " << N;
	}

	Taylor_series(const Taylor_series&s)
	{
		len = s.len;
		S = new char[len + 1];
		strcpy(S, s.S);
	}

	Taylor_series& operator=(const Taylor_series &a)
	{
		N = a.N;
		return *this;
	}

	double myexp(double x, double N)
	{
		//double x; // переменная 
		//double N; // число слагаемых 
		int i = 2;
		long double Xn = 1;
		long double result = 1;
		long double eps = 0.0000001;

		for (i = 2; i <= N; i++)
		{
			Xn = Xn * (x / (i - 1));
			result = result + Xn;
			if (fabs(result - exp(x)) < eps)
				break;
		}
		return result;
	}

	double mysin(double x, double N)
	{
		//double x; // переменная 
		//double N; // число слагаемых 
		int i;
		long double Xn = 1;
		long double result = x;
		long double eps = 0.0000001;

		for (i = 2; i <= N && (fabs(result - sin(x)) >= eps); i++)
		{
			Xn *= (-1)*((x*x) / ((2 * i - 2)*(2 * i - 1)));
			result = result + Xn;
		}
		N = i - 1;
		return result;
	}

	double mycos(double x, double N)
	{
		//double x; // переменная 
		//double N; // число слагаемых 
		int i;
		long double Xn = 1;
		long double result = 1;
		long double eps = 0.0000001;

		for (i = 2; i <= N && (fabs(result - cos(x)) >= eps); i++)
		{
			Xn *= (-1)*((x*x) / ((2 * i - 2)*(2 * i - 3)));
			result = result + Xn;
		}
		return result;
	}

	double mych(double x, double N)
	{
		//double x; // переменная 
		//double N; // число слагаемых 
		int i;
		long double Xn = 1;
		long double result = 1;
		long double eps = 0.0000001;

		for (i = 2; i <= N; i++)
		{
			Xn = Xn * (x / (i - 1));

			if (i % 2 == 1)
			{
				result = result + Xn;
			}

			if (fabs(result - cosh(x)) < eps)
				break;
		}
		N = i - 1;
		return result;
	}

	double Сompare_functions(int f, double x, double N)
	{
		double result=0;
		if (f == 1)
			result = fabs(myexp(x, N) - exp(x));
		if (f == 2)
			result = fabs(mysin(x, N) - sin(x));
		if (f == 3)
			result = fabs(mycos(x, N) - cos(x));
		if (f == 4)
			result = fabs(mych(x, N) - cosh(x));
		return result;
	}

	void formula(int a)
	{
		if(a==1)
			cout<< "Рекурентная формула расчета экспоненты: Xn = Xn * (x / (i - 1))" << endl;
		if(a==2)
			cout << "Рекурентная формула расчета синуса: Xn *= (-1)*((x*x) / ((2 * i - 2)*(2 * i - 1)))" << endl;
		if(a==3)
			cout << "Рекурентная формула расчета косинуса: Xn *= (-1)*((x*x) / ((2 * i - 2)*(2 * i - 1)))" << endl;
		if(a==4)
			cout << "Рекурентная формула расчета гиперболического косинуса: Xn = Xn * (x / (i - 1))" << endl;
	}
	double get_znachenie(double x)
	{
		return x;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	int F;
	int a;
	double n;
	double x;
	Taylor_series t;
	
	cout << "Выберите функцию" << endl;
	cout << "'1' - экспонента\n" << endl;
	cout << "'2' - синус\n" << endl;
	cout << "'3' - косинус\n" << endl;
	cout << "'4' - гиперболический косинус\n" << endl;
	cin >> F;
	switch (F) {
	case 1:
		t.formula(F);
		cout << "Введите переменную" << endl;
		cin >> x;
		cout << "Введите число слагаемых от 1 до 1000\n" << endl;
		cin >> n;
		cout << " " << t.myexp(x, n) << endl;
		break;
	case 2:
		t.formula(F);
		cout << "Введите переменную" << endl;
		cin >> x;
		cout << "Введите число слагаемых от 1 до 1000\n" << endl;
		cin >> n;
		cout << " " << t.mysin(x, n) << endl;
		break;
	case 3:
		t.formula(F);
		cout << "Введите переменную" << endl;
		cin >> x;
		cout << "Введите число слагаемых от 1 до 1000\n" << endl;
		cin >> n;
		cout << " " << t.mycos(x, n) << endl;
		break;
	case 4:
		t.formula(F);
		cout << "Введите переменную" << endl;
		cin >> x;
		cout << "Введите число слагаемых от 1 до 1000\n" << endl;
		cin >> n;
		cout << " " << t.mych(x, n) << endl;
		break;
	default:
		cout << "Неправильно введен номер";
		break;
	}

	cout << "Хотите узнать текущую функцию (введите 0, если нет; введите 1, если да)?" << endl;
	cin >> a;
	while (a < 0 || a > 1)
	{
		cout << "Неправильно введен номер! Попробуйте снова!" << endl;
		cout << "Хотите узнать текущую функцию (введите 0, если нет; введите 1, если да)?" << endl;
		cin >> a;
	}
	if (a == 1)
	{
		cout << "Текущая функция: " << t.get_function(F) << endl;
		cout << "Введите 0, если хотите продолжить" << endl;
		cin >> a;
	}
	if (a == 0)
	{
		cout << "Хотите узнать текущее число членов ряда (введите 0, если нет; введите 1, если да)?" << endl;
		cin >> a;
		while (a < 0 || a > 1)
		{
			cout << "Неправильно введен номер! Попробуйте снова!" << endl;
			cout << "Хотите узнать текущее число членов ряда (введите 0, если нет; введите 1, если да)?" << endl;
			cin >> a;
		}
		if (a == 1)
		{
			cout << "Текущее число членов ряда: " << n << endl;
			cout << "Введите 0, если хотите продолжить" << endl;
			cin >> a;
		}
		if (a == 0)
		{
			cout << "Хотите узнать разницу выбранной вами функции класса и её эталонным значением (введите 0, если нет; введите 1, если да)?" << endl;
			cin >> a;
			while (a < 0 || a > 1)
			{
				cout << "Неправильно введен номер! Попробуйте снова!" << endl;
				cout << "Хотите узнать разницу выбранной вами функции класса и её эталонным значением (введите 0, если нет; введите 1, если да)?" << endl;
				cin >> a;
			}
			if (a == 1)
			{
				cout << "Разница составляет: " << t.Сompare_functions(F, x, n) << endl;
				cout << "Введите 0, если хотите продолжить" << endl;
				cin >> a;
			}
			if (a == 0)
			{
				cout << "Хотите узнать значение заданного члена ряда (введите 0, если нет; введите 1, если да)?" << endl;
				cin >> a;
				while (a < 0 || a > 1)
				{
					cout << "Неправильно введен номер! Попробуйте снова!" << endl;
					cout << "Хотите узнать значение заданного члена ряда (введите 0, если нет; введите 1, если да)?" << endl;
					cin >> a;
				}
				if (a == 1)
				{
					cout << "Значение заданного члена ряда равно: " << t.get_znachenie(x) << endl;
				}
			}
		}

	}
	cin >> a;
}