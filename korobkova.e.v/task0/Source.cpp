#include <string>
#include <iostream>
#include <stdio.h>
#include <locale.h>

class convertweight {
	float KG;
public:

	void PRINT()
	{
		printf_s("Вес в килограммах: %f", KG);
	}

	convertweight(float l)
	{
		KG = l;
	}

	convertweight()
	{
		KG = 0;
	}

	convertweight& operator=(const convertweight &a)
	{
		KG = a.KG;
		return *this;
	}

	float convert_lb() //funt
	{
		return KG * 2.2046226218;
	}

	float convert_pud() //pud
	{
		return KG * 0.06104821097;
	}

	float convert_t() //tonna
	{
		return KG * 0.001;
	}

	float convert_oz() // uncia
	{
		return KG * 35.2739619496;
	}

	float see_in_kg()
	{
		return KG;
	}

};

int main()
{
	setlocale(LC_ALL, "Rus");
	int p;
	int c;
	convertweight m;
	printf_s("Здравствуйте! Введите массу в кг \n");
	scanf_s("%f", &m);

	printf_s("Выберите, что вы хотите сделать \n Если вы хотите узнать вес в кг, введите 1 \n Если вы хотите узнать вес в других единицах измерения, введите 2 \n");
	scanf_s("%d", &p);

	if (p > 0 && p < 3)
	{
		if (p == 1)
		{
			m.PRINT;
		}
		if (p == 2)
		{
			printf_s("Выберите величину, в которую вы хотите перевести массу\n 1 - фунт\n 2 - пуд\n 3 - тонна\n 4 - унция\n");
			scanf_s("%d", &c);

			switch (c)
			{
			case 1:
				printf_s("Масса в фунтах = %f", m.convert_lb());
				break;
			case 2:
				printf_s("Масса в пудах = %f", m.convert_pud());
				break;
			case 3:
				printf_s("Масса в тоннах = %f", m.convert_t());
				break;
			case 4:
				printf_s("Масса в унциях = %f", m.convert_oz());
				break;
			}
		}
	}
	else
		printf_s("Попробуйте снова!\n");

	scanf_s("%d", &p);
}
