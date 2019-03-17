#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <locale.h> 
#include <iostream>
using namespace std;

class Taylor_series {
	double N;				//  ����� ������ ������������������
	double Xn;				//   ��������

public:

	Taylor_series(double n = 0)
	{
		N = n;
	}

	Taylor_series(double x = 0)
	{
		Xn = x;
	}

	void SET_Xn(double x)
	{
		Xn = x;
	}

	void SET_N(double n)
	{
		N = n;
	}

	void GET_N()
	{
		cout << "����� ������ ����: " << N;
	}

	Taylor_series& operator=(const Taylor_series &a)
	{
		N = a.N;
		return *this;
	}

	Taylor_series& operator+(const Taylor_series &a)
	{
		Taylor_series temp(Xn + a.Xn);
		return temp;
	}

	double myexp(double x, double N)
	{
		//double x; // ���������� 
		//double N; // ����� ��������� 
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
		//double x; // ���������� 
		//double N; // ����� ��������� 
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
		//double x; // ���������� 
		//double N; // ����� ��������� 
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
		//double x; // ���������� 
		//double N; // ����� ��������� 
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
	
	




};
int main()
{
	setlocale(LC_ALL, "Rus");
	int F;
	int a;
	double n;
	double x;
	Taylor_series t;

	cout << "�������� �������"<<endl;
	cout << "'1' - ����������\n" << endl;
	cout << "'2' - �����\n" << endl;
	cout << "'3' - �������\n" << endl;
	cout << "'4' - ��������������� �������\n" << endl;
	cin>> F ;
	switch (F) {
	case 1:
		cout << "����������� ������� ������� ����������: Xn = Xn * (x / (i - 1))" << endl;
		cout << "������� ����������" << endl;
		cin >> x;
		cout << "������� ����� ��������� �� 1 �� 1000\n" << endl;
		cin >> n;
		cout << " "<<t.myexp(x,n) << endl;
			break;
	case 2:
		cout << "����������� ������� ������� ������: Xn *= (-1)*((x*x) / ((2 * i - 2)*(2 * i - 1)))" << endl;
		cout << "������� ����������" << endl;
		cin >> x;
		cout << "������� ����� ��������� �� 1 �� 1000\n" << endl;
		cin >> n;
		cout << " " << t.mysin(x, n) << endl;		
			break;
	case 3:
		cout << "����������� ������� ������� ��������: Xn *= (-1)*((x*x) / ((2 * i - 2)*(2 * i - 1)))" << endl;
		cout << "������� ����������" << endl;
		cin >> x;
		cout << "������� ����� ��������� �� 1 �� 1000\n" << endl;
		cin >> n;
		cout << "Xn *= (-1)*((x*x) / ((2 * i - 2)*(2 * i - 3)))" << t.mycos(x, n) << endl;
			break;
	case 4:
		cout << "����������� ������� ������� ���������������� ��������: Xn = Xn * (x / (i - 1))" << endl;
		cout << "������� ����������" << endl;
		cin >> x;
		cout << "������� ����� ��������� �� 1 �� 1000\n" << endl;
		cin >> n;
		cout << "Xn *= (-1)*((x*x) / ((2 * i - 2)*(2 * i - 3)))" << t.mych(x, n) << endl;
			break;
	default:
		cout << "����������� ������ �����";
			break;
	}

	cout << "������ ������ ������� ������� (������� 0, ���� ���; ������� 1, ���� ��)?" << endl;
	cin >> a;
	while (a < 0 || a > 1)
	{
		cout << "����������� ������ �����! ���������� �����!" << endl;
		cout << "������ ������ ������� ������� (������� 0, ���� ���; ������� 1, ���� ��)?" << endl;
		cin >> a;
	}
	if (a == 1)
		cout << "������� �������: " << F << endl;																	//&&&&&&&&&&
	else
	{
		cout << "������ ������ ������� ����� ������ ���� (������� 0, ���� ���; ������� 1, ���� ��)?" << endl;
		cin >> a;
		while (a < 0 || a > 1)
		{
			cout << "����������� ������ �����! ���������� �����!" << endl;
			cout << "������ ������ ������� ����� ������ ���� (������� 0, ���� ���; ������� 1, ���� ��)?" << endl;
			cin >> a;
		}
		if (a == 1)
			cout << "������� ����� ������ ����: " << n << endl;
		else
		{

		}

	
	

	

}