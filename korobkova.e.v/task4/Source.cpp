#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <locale.h> 
#include <iostream> 
#include <fstream>
using namespace std;

class person
{
	char*name;
	int len;
public:

	person()
	{
		len = 0;
		name = new char[1];
		name[0] = '\0';
	}

	person(const person&s)
	{
		len = s.len;
		name = new char[len + 1];
		strcpy(name, s.name);
	}

	void set_name(char *_name)
	{
		len = strlen(_name);
		delete[] name;
		name = new char[len + 1];
		strcpy(name, _name);
	}

	~person()
	{
		delete[] name;
	}

	person& operator=(const person &a)
	{
		name = a.name;
		return *this;
	}
	friend ostream& operator<<(ostream &os, const person &S);
};

class Data
{
	int day;
	int month;
	int year;
public:

	Data(int d = 0, int m = 0, int y = 0)
	{
		day = d;
		month = m;
		year = y;
	}

	int set_data(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}

	void Print_data()
	{
		cout << day << month << year;

	}

	Data& operator=(const Data &a)
	{
		day = a.day;
		month = a.month;
		year = a.year;
		return *this;
	}

	int get_day() { return day; }
	int get_month() { return month; }
	int get_year() { return year; }

	friend ostream& operator<<(ostream &os, const Data &D);
};
ostream& operator<<(ostream &os, const Data &D)
{
	os << D.day << " " << D.month << " " << D.year << " ";
	return os;
}
ostream& operator<<(ostream &os, const person &D)
{
	os << D.name;
	return os;
}
class scale								// весы
{
	float *NP;
	Data *D;
	person *N;
	int *P;
	int count;
	Data D1;
	bool is_data_set;

public:

	scale()										//конструктор
	{
		count = 1; // число элементов в массивах
		D = new Data[count];
		NP = new float[count];
		P = new int[count];
		N = new person[5];
		is_data_set = false;
	}

	scale(const scale &c)
	{
		count = c.count;
		delete[] D;
		delete[] NP;
		delete[] P;
		for (int i = 0; i < 5; i++)
			N[i] = c.N[i];
		is_data_set = c.is_data_set;
		D = new Data[count];
		NP = new float[count];
		P = new int[count];
		for (int i = 0; i < count; i++)
		{
			D[i] = c.D[i];
			NP[i] = c.NP[i];
			P[i] = c.P[i];
		}
	}

	void add()
	{
		scale temp = *this;
		delete[] D;
		delete[] NP;
		delete[] P;
		D = new Data[count + 1];
		NP = new float[count + 1];
		P = new int[count + 1];
		for (int i = 0; i < count; i++)
		{
			D[i] = temp.D[i];
			NP[i] = temp.NP[i];
			P[i] = temp.P[i];
		}
		NP[count] = 0;
		P[count] = 0;
		count++;
	}

	void set_start_date(Data d)					//установить начальную дату наблюдений
	{
		D1 = d;
		is_data_set = true;
	}

	Data get_data()					//узнать начальную дату наблюдений
	{
		cout << "Начальная дата наблюдений:";
		return D1;
	}

	void set_observation(int person, float _NP)								//задать наблюдение
	{
		if (!is_data_set)
			throw "Дата не установлена";
		NP[count - 1] = _NP;
		D[count - 1] = D1;
		P[count - 1] = person;
		add();
	}

	void find_out_weight(int k)				//узнать вес в выбранном наблюдении
	{
		cout << "Для члена семьи: " << N[P[k]] << "вес составляет:" << NP[k] << endl;
	}
	
	
	//найти средний вес члена семьи в выбранном месяце или за всю историю наблюдений






	// найти минимальный вес члена семьи в выбранном месяце или за всю историю наблюдений



};

int main()
{
	setlocale(LC_ALL, "Rus");
	float c;
	scale KG;
	Data d;
	int k, a;
	person Name;
	int day, month, year;
	int count = 0;

	cout << "Начнем работу!" << endl;
	/*cout << "Введите членов семьи" << endl;
	Name.set_name;
	cout << "Введите дату (день, месяц, год): " << endl;
	cin >> day >> month >> year;
	d.set_data(year, month, day);*/
	cout << "Хотите задать начальную дату? 1-yes, 0-no" << endl;
	cin >> a;
	if (a == 1)
	{
		KG.set_start_date(d);
		cout << "Вы ввели начальную датy! Продолжим! Хотите узнать начальную дату наблюдений?" << endl;
		cin >> a;
		if (a == 1)
		{
			cout << KG.get_data();
		}
	}

	ofstream fout("test.txt");
	fout << "1";
	fout.close();

	ifstream fin("test.txt");
	fin >> c;
	fin.close();
	cin >> k;
}