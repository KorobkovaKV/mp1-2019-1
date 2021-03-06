#define _CRT_SECURE_NO_WARNINGS 
#include<cstring> 
#include <iostream> 
#include <stdio.h> 
#include <locale.h> 
#include <cstdio> 
#include <stdio.h> 
#include <iostream> 
#include <string> 
using namespace std;

class String
{
	char *str;
	int len;
public:
	String()
	{
		len = 0;
		str = new char[1];
		str[0] = '\0';
	}
	//инициализатор 
	String(const String &s)
	{
		len = s.len;
		str = new char[len + 1];
		strcpy(str, s.str);
	}

	void set_string(char *_str)
	{
		len = strlen(_str);
		delete[] str;
		str = new char[len + 1];
		strcpy(str, _str);
	}

	~String()
	{
		delete[] str;
	}

	String& operator=(const String &a) //оператор присваивания 
	{
		if (this == &a)
			return *this;
		len = a.len;
		delete[] str;
		str = new char[len + 1];
		strcpy(str, a.str);
		return *this;
	}

	int Lenght_len() const//длина строки 
	{
		return len;
	}

	char& operator[](int index) //получить символ строки по его индексу 
	{
		if (str != 0 && index >= 0 && index <= len)
			return str[index];
		else
			throw "Ошибка(данного индекса не существует)";
	}

	char* Substring(char *str, int m, int n) //подстрока m - индекс начала подстроки , n - длина выделяемой подстроки 
	{
		char *newstr;
		int newlen = 0;
		int p, len = 0;
		int i, j = 0;
		for (i = 0; str != '\0'; i++)
		{
			len++;
		}
		if (n > 0)
		{
			if (m + n <= len + 1)
				p = m + n - 1; // индекс конца подстроки 
			else
				throw "Ошибка: подстрока выходит за пределы строки";
		}
		else
			throw "Wrong n";
		newlen = n;
		newstr = new char[n];

		for (i = m; i <= p; i++)
		{
			newstr[j] = str[i];
			j++;
		}
		return(newstr);
	}

	bool Search_palindrome(int i, int j) //палиндром или нет 
	{
		while (i <= j)
		{
			if (str[i] != str[j])
			{
				return false;
			}
			++i; --j;
		}
		return true;
	}

	int Palindrome()
	{
		int P; //палиндромы 
		for (int i = 0; i < Lenght_len(); ++i)
		{
			for (int j = i + 1; j < Lenght_len(); ++j)
			{
				if (Search_palindrome(i, j))
				{
					++P;
				}
			}
		}
		return P;
	}

	int Counting_elements(char *str)
	{
		int i, j, count = 0;
		for (i = 0; i < Lenght_len(); i++)
		{
			if (str[i] != 0)
			{
				for (j = i - 1; j < len; j--)
				{
					if (str[j] != str[i])
					{
						count++;
					}
				}
			}
		}
		return count;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	int a;
	String s;
	char *s1;
	s1 = new char[40];
	cout << "Здравствуйте! Начнем\n" << endl;
	cout << "Введите строку" << endl;
	cin.getline(s1, 40);
	cout << s1 << endl;
	s.set_string(s1);
	cout << "Хотите узнать длинну строки" << endl << "0-Да" << endl << "1-Нет" << endl;
	cin >> a;
	while (a < 0 || a > 1)
	{
		cout << "Неправильно введен номер! Попробуйте снова!" << endl;
		cout << "Хотите узнать длинну строки?" << endl << "0-Да" << endl << "1-Нет" << endl;
		cin >> a;

	}
	if (a == 0)
	{
		cout << s.Lenght_len();
	}
	cout << "Продолжим! Хотите узнать элемент массива по его индексу?" << endl << "0-Да" << endl << "1-Нет" << endl;
	cin >> a;
	while (a < 0 || a>1)
	{
		cout << "Неправильно введен номер! Попробуйте снова!" << endl;
		cout << "Хотите узнать элемент массива по его индексу?" << endl << "0-Да" << endl << "1-Нет" << endl;
		cin >> a;
	}
	if (a == 0)
	{
		int i;
		cout << "Введите индекс элемента, который вы хотите узнать" << endl;
		cin >> i;
		cout<<s.operator[](i);
	}
	if (a == 1)
	{
		cout << "Желаете задать элемент строки по его индексу?" << endl << "0-Да" << endl << "1-Нет" << endl;
		cin >> a;
		while (a < 0 || a>1)
		{
			cout << "Неправильно введен номер! Попробуйте снова!" << endl;
			cout << "Желаете задать элемент строки по его индексу?" << endl << "0-Да" << endl << "1-Нет" << endl;
			cin >> a;

		}
		if (a == 0)
		{
			int index;
			cout << "Введите индекс" << endl;
			cin >> index;
			printf("%c", s[index]);
		}
		if (a = 1)
		{
			cout << "Хотите выделить подстроку из строки?" << endl << "0-Да" << endl << "1-Нет" << endl;
			cin >> a;
			while (a < 0 || a>1)
			{
				cout << "Неправильно введен номер! Попробуйте снова!" << endl;
				cout << "Хотите выделить подстроку из строки ? " << endl << "0 - Да" << endl << "1 - Нет" << endl;
				cin >> a;
			}
			if (a == 0)
			{
				int p, l;
				cout << "Введите начальную позицию подстроки" << endl;
				cin >> p;
				cout << "Введите длину подстроки" << endl;
				cin >> l;
				cout << "Ваша подстрока:" << s.Substring(s1, p, l) << endl;
			}
			if (a = 1)
			{
				cout << "Продолжим! Хотите проверить строку на наличие палиндромов?" << endl << "0-Да" << endl << "1-Нет" << endl;
				cin >> a;
				while (a < 0 || a>1)
				{
					cout << "Неправильно введен номер! Попробуйте снова!" << endl;
					cout << "Хотите проверить строку на наличие палиндромов?" << endl << "0-Да" << endl << "1-Нет" << endl;
					cin >> a;
				}
				if (a == 0)
				{

				}

			}

		}
	}
	cout << a;
}