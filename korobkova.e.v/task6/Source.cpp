#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <locale.h> 
#include <iostream> 
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

class GAME
{
	int cow;
	int bull;
	vector<int> number;

public:
	GAME()
	{
		cow = 0;
		bull = 0;
		for (int i = 0; i < 5; i++)
			number.push_back(0);
	}

	GAME(int c, int b, vector<int> n)
	{
		cow = c;
		bull = b;
		number = n;
	}

	vector<int> get_numbers()
	{
		return number;
	}

	int get_cow()
	{
		return cow;
	}

	int get_bull()
	{
		return bull;
	}

	GAME& operator=(const GAME &a)
	{
		cow = a.cow;
		bull = a.bull;
		number = a.number;
		return *this;
	}

	vector<int> random_number(int n)
	{
		int p = 1;
		int r = 1;
		while (r > 0)
		{
			r = 0; // r=0 - тогда нет повторов 
			for (int i = 0; i < n; i++)
			{
				if (i == (n - 1))
					number[i] = 1 + rand() % 9; // для первой цифры числа 9 вариантов цифры от 1 до 9 
				else
					number[i] = rand() % 10; // для следующих цифр числа 10 вариантов цифр от 0 до 9 
			}
			for (int i = 0; i < n; i++)
				for (int m = i + 1; m < n; m++)
				{
					if (number[i] == number[m])
					{
						r = 1; // значит есть повторы 
						break;
					}
				}
		}
		for (int i = 0; i < n; i++)
			p = p * 10;
		return number;
	}

	int find_bull(int n, int*B)
	{
		bull = 0;
		for (int i = 0; i < n; i++)
		{
			for (int m = 0; m < n; m++)
			{
				if (B[i] == number[m] && i == m)
					bull++;
			}
		}
		return bull;
	}

	int find_cow(int n, int*B)
	{
		cow = 0;
		for (int i = 0; i < n; i++)
		{
			for (int m = 0; m < n; m++)
			{
				if (B[i] == number[m] && i != m)
					cow++;
			}
		}
		return cow;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n; //n - количество цифр в числе 
	int K[5] = { 0 }; // массив для хранения загаданного числа 
	int B[5] = { 0 }; // массив для хранения моего числа 
	int cow = 0; //"коровы" 
	int bull = 0; //"быки" 
	//p - отвечает за контроль длины вводимого числа 
	int z = 0; // z - наши попытки угадать загаданное число 
	GAME RRR;

	cout << "Условие игры: вы пытаетесь угадать число, загаданное компьютером, сow - сколько цифр угадано без совпадения с их позициями в загаданном числе, а bull - сколько цифр угадано вплоть до позиции в загаданном числе" << endl;

	do
	{
		cout << "Введите количество цифр в числе" << endl;
		cin >> n;
	} while (n < 2 || n > 5);

	RRR.random_number(n);

	cout << "Начнем игру!" << endl;;	

	bool flag = true;
	do
	{
		flag = true;
		cout << "Введите число с неповторяющимися цифрами (Вводите числа через пробел!):" << endl;
		for (int j = 0; j < n; j++)
		{
			cin >> B[j];
			if (B[0] == 0)
				flag = false;
			if (B[j] < 0)
				flag = false;
			if (B[j] > 9)
				flag = false;
		}
		for (int j = 0; j < n; j++)
			for (int k = j+1; k < n-1; k++)
			{
				if(B[k]==B[j])
					flag = false;
			}

	} while (!flag);

	while (RRR.get_bull() != n)
	{
		RRR.find_cow(n, B);
		RRR.find_bull(n, B);
		z++;

		cout << "БЫКИ   -   " << RRR.get_bull() << endl;
		cout << "КОРОВЫ -   " << RRR.get_cow() << endl;
		cout << "ЧИСЛО ПОПЫТОК -   " << z << endl;

		if (RRR.get_bull() == n)
		{
			cout << "Победааа!!!!!" << endl;
			break;
		}

		do
		{
			flag = true;
			cout << "Введите число с неповторяющимися цифрами (Вводите числа через пробел!):" << endl;
			for (int j = 0; j < n; j++)
			{
				cin >> B[j];
				if (B[0] == 0)
					flag = false;
				if (B[j] < 0)
					flag = false;
				if (B[j] > 9)
					flag = false;
			}
			for (int j = 0; j < n; j++)
				for (int k = j + 1; k < n - 1; k++)
				{
					if (B[k] == B[j])
						flag = false;
				}

		} while (!flag);
	}

	cin >> z;
}