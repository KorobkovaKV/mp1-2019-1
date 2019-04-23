#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <locale.h> 
#include <iostream> 
#include <string>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

class ProcessingCenter
{
	int number; // номер счета
	string name; //ФИО
	int sum; // сумма на зарплатном счету
	string password; // пароль
	int credit;
	vector <int> NUMBER;		//база данных
	vector <string> NAME;
	vector <int> SUM;
	vector <string> PASSWORD;
	vector <int> CREDIT;
	vector <int> BALANCE; //оставшаяся сумма на счету

public:

	ProcessingCenter()
	{
		number = 0;
		sum = 0;
		credit = 0;
		name = "";
		password = "";
		NUMBER = { 0 };
		NAME = { 0 };
		SUM = { 0 };
		PASSWORD = { 0 };
		CREDIT = { 0 };
		BALANCE = { 0 };
	}

	ProcessingCenter(int num, string n, int s, string pas, int _credit)
	{
		number = num;
		sum = s;
		name = n;
		password = pas;
		credit = _credit;
		NUMBER.push_back(number);
		NAME.push_back(name);
		SUM.push_back(sum);
		PASSWORD.push_back(password);
		CREDIT.push_back(credit);
		BALANCE.push_back(credit);
	}

	void set_password(string _password)
	{
		password = _password;
	}

	void set_name(string _name)
	{
		name = _name;
	}

	void set_person(string _name, string _password, int _sum, int _number)
	{
		name = _name;
		password = _password;
		sum = _sum;
		number = _number;
		credit = 0;
	}

	int get_BALANCE(ProcessingCenter &PERSON)
	{
		for (int i = 0; i < 10000; i++)
		{
				if (PERSON.get_number() == NUMBER[i])
				{
					return BALANCE[i];
				}
				else
					cout << "Данного номера не существует!" << endl;
		}
	}

	~ProcessingCenter()
	{

	}

	ProcessingCenter& operator=(const ProcessingCenter &a)
	{
		name = a.name;
		number = a.number;
		sum = a.sum;
		password = a.password;
		return *this;
	}

	int get_sum()
	{
		return sum;
	}

	int get_number()
	{
		return number;
	}

	int get_credit()
	{
		return credit;
	}

	string get_pasword()
	{
		return password;
	}

	void get_person()
	{
		cout << "Ваше имя: " << name << endl;
		cout << "Номер счета:" << setfill('0') << setw(4) << number << endl;
		cout << "Сумма счета:" << sum << endl;
	}

	void database()
	{
		NUMBER.push_back(number);
		NAME.push_back(name);
		SUM.push_back(sum);
		PASSWORD.push_back(password);
		CREDIT.push_back(credit);
	}

	void set_number_database(int i)
	{
		for (i = 0; i < NUMBER.size(); i++) {
			cout << NUMBER[i] << " ";
		}
	}

	void set_sum_database(int i)
	{
		for (i = 0; i < SUM.size(); i++) {
			cout << SUM[i] << " ";
		}
	}

	void set_name_database(int i)
	{
		for (i = 0; i < NAME.size(); i++) {
			cout << NAME[i] << " ";
		}
	}

	void set_credit_database(int i)
	{
		for (i = 0; i < CREDIT.size(); i++) {
			cout << CREDIT[i] << " ";
		}
	}
	
	int take_SUM(ProcessingCenter &PERSON)							// вывод кредита
	{
		for (int i = 0; i < 10000; i++)
		{
			if (PERSON.get_number() == NUMBER[i])
			{
				return SUM[i];
			}
			else
				cout << "Данного номера не существует!" << endl;
		}

	}

	int take_credit(ProcessingCenter &PERSON)							// вывод кредита
	{
		for (int i = 0; i < 10000; i++)
		{
			if (PERSON.get_number() == NUMBER[i])
			{
				return CREDIT[i];
			}
			else
				cout << "Данного номера не существует!" << endl;
		}

	}

	void take_BALANCE(ProcessingCenter &PERSON, int L)							// вывод кредита
	{
		int k = 0;
		for (int i = 0; i < NUMBER.size(); i++)
			if (NUMBER[i] == PERSON.get_number())
			{
				k = i;
				break;
			}
		BALANCE.at(k) = L;
	}

	void set_CREDIT(int _c, int p)
	{
		int k = 0;
		for (int i = 0; i < NUMBER.size(); i++)
			if (NUMBER[i] == p)
			{
				k = i;
				break;
			}
		CREDIT.at(k) = _c;
		BALANCE.at(k) = _c;
	}

	void set_SUM(ProcessingCenter &PERSON, int _c)
	{
		int k = 0;
		for (int i = 0; i < NUMBER.size(); i++)
			if (NUMBER[i] == PERSON.get_number())
			{
				k = i;
				break;
			}
		SUM.at(k) = _c;
	}

	bool sravnenie(int p)
	{
		for (int i = 0; i < NUMBER.size(); i++)
			if (p == NUMBER[i])
			{
				cout << "Здравствуйте! " << NAME[i] << endl;
				set_person(NAME[i], PASSWORD[i], SUM[i], NUMBER[i]);
				return 1;
			}
		cout << "Данного номера не существует!" << endl;
		return 0;
	}
};

class Credit
{
	int dT; // сколько времени прошло
	int T;
public:
	int percent1[5] = { 19, 17, 16, 15, 13 };		//процент
	int percent2[5] = { 18, 17, 15, 13, 10 };
	int percent3[5] = { 18, 16, 15, 12, 12 };
	int percent4[5] = { 19, 19, 17, 17, 15 };

	Credit()
	{
		dT = 0;
		T = 0;
	}

	Credit(int b, int _dT, int _T)
	{
		dT = _dT;
		T = _T;
	}

	void set_time(int _dT)
	{
		dT = _dT;
	}

	void authorization(ProcessingCenter &PERSON)		// авторизация
	{
		string ps;
		int n;
		cout << "Введите номер счета" << endl;
		cin >> n;
		//сравниваем n со всеми номерами из базы данных		
		if (PERSON.sravnenie(n))
		{
			cout << "Введите пароль" << endl;
			cin >> ps;
			while (ps != PERSON.get_pasword())
			{
				cout << "Пароль введен неверно!"<<endl;
				cin >> ps;
			}
			cout << "Пароль введен успешно! Вы вошли в систему!" << endl;
		}
	}

	void available_loans(ProcessingCenter PERSON)						//  доступные кредиты
	{
		int l;
		int loans[6][4] = { {100000, 500000, 1000000, 3000000}, {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {5, 5, 5, 5}, {15, 15, 15, 15} };
		if (PERSON.get_sum() > 0)
		{
			cout << "Вам доступен кредит до " << loans[0][0] << " рублей" << endl;

			if (PERSON.get_sum() > 100000)
			{
				cout << "Также вам доступен кредит от 100000 до " << loans[0][1] << " рублей" << endl;

				if (PERSON.get_sum() > 500000)
				{
					cout << "Также вам доступен кредит от 500000 до " << loans[0][2] << " рублей" << endl;

					if (PERSON.get_sum() > 1000000)
					{
						cout << "Также вам доступен кредит от 1000000 до " << loans[0][3] << " рублей" << endl;

					}
				}
			}
		}
	}

	void check_credits(ProcessingCenter &PERSON)					//проверка наличия взятого в банке кредита
	{
		if (PERSON.take_credit(PERSON) == 0)
		{
			cout << "У вас нет открытого кредита" << endl;
		}
			else
				cout << "У вас есть открытый кредит, вы не можете открыть новый кредит, не закрыв данный" << endl << "Ваш кредит составляет " << PERSON.take_credit(PERSON) << endl;
			
	}


	void check_to_get(ProcessingCenter &PERSON, int _c, int _l)						//проверка возможности получения кредита и получение
	{
		int p;
		int i = 0, d = -1; //d-кредит для выбранной суммы и кол-ва лет
		p = PERSON.get_number();
		for (i = 0; i < 7; i++)
		{
			if (_l == i + 1)
			{
				if (_c < 100000)
					d = percent1[i];
				if (100000 <= _c < 500000)
					d = percent2[i];
				if (500000 <= _c < 1000000)
					d = percent3[i];
				if (1000000 <= _c < 3000000)
					d = percent4[i];
			}
		}
		cout << "Вы берете кредит на сумму " << _c << " рублей под " << d << "% годовых" << endl;
		PERSON.set_CREDIT(_c, p);

		p = ((_c*(1 + (d / 100.0)*_l)) / (2 * _l));				//выплата за 6 месяцев
		cout << "Ежемесячные выплаты по кредиту составляют: " << p / 6 << endl;

		if (_c >= p)
		{
			cout << "Кредит одобрен" << endl;
		}
		else
			cout << "Кредит не одобрен" << endl;
	}

	void status_of_credit(ProcessingCenter &PERSON)					//состояние
	{
		cout << "Остаток на счете, который осталось погасить: " << PERSON.get_BALANCE(PERSON);
	}

	void TIME(ProcessingCenter &PERSON, int _c, int _l, int _t)
	{
		int p, balance;
		int i = 0, d = -1; //d-кредит для выбранной суммы и кол-ва лет
		p = PERSON.get_number();
		for (i = 0; i < 7; i++)
		{
			if (_l == i + 1)
			{
				if (_c < 100000)
					d = percent1[i];
				if (100000 <= _c < 500000)
					d = percent2[i];
				if (500000 <= _c < 1000000)
					d = percent3[i];
				if (1000000 <= _c < 3000000)
					d = percent4[i];
			}
		}
		p = ((_c*(1 + (d / 100.0)*_l)) / (2 * _l));
		balance = PERSON.get_BALANCE(PERSON) - (p / 6.0)*(_t);
		if (balance < 0)
		{
			balance = 0;
		}
		PERSON.take_BALANCE(PERSON, balance);
		PERSON.set_SUM(PERSON, PERSON.take_SUM(PERSON) - balance);
	}


	void credit_repayment(ProcessingCenter &PERSON)					//погашение
	{
		if (PERSON.get_BALANCE(PERSON) == 0)
		{
			PERSON.set_CREDIT(0, PERSON.get_number());
			cout << "Кредит закрыт!" << endl;
		}
		else
			cout << "Кредит не может быть закрыт!" << endl;
	}

	void close_CREDIT(ProcessingCenter &PERSON, int _c, int _l)						//досрочное погашение
	{
		Credit c;
		int _t = 100;
		while (PERSON.get_BALANCE(PERSON) != 0)
		{
			c.TIME(PERSON, _c, _l, _t);
		}
		c.credit_repayment(PERSON);
	}
};

int main()
{
	int a, s, l, c = 0;
	string FIO = "";
	string key;
	string name;

	setlocale(LC_ALL, "ru");

	cout << "Здравствуйте!";
	cout << "Введите свой номер счета от 0001 до 9999" << endl;
	cin >> a;
	while (a < 1 || a > 9999)
	{
		cout << "Данного номера не существует!" << endl;
		cout << "Введите свой номер счета от 0001 до 9999" << endl;
		cin >> a;
	}
	cout << "Введите ФИО" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> name;
		FIO += name;
		FIO += " ";
	}

	cout << "Введите пароль длинной больше трех символов" << endl;
	cin >> key;
	while (key.length() < 4)
	{
		cout << "Данный пароль не больше трех символов! Ваш пароль должен быть больше трех символов" << endl;
		cin >> key;
	}

	cout << "Укажите сумму вашего счета" << endl;
	cin >> s;
	while (s < 0)
	{
		cout << "Вы ввели отрицательную сумму!" << endl;
		cin >> s;
	}

	ProcessingCenter person(a, FIO, s, key, c);
	person.get_person();

	Credit cr;
	int h = 1;
	int t = 0;
	while (h != 0)
	{
		cout << endl<<"Выберите, что хотите сделать далее" << endl << "1 - регистрация" << endl << "2 - авторизация" << endl << "3 - узнать доступные кредиты" << endl << "4 - проверить на наличие кредитов" << endl << "5 - проверить возможность получения выбранного кредита и получить выбранный кредит" << endl << "6 - промотать время" << endl << "7 - показать состояние кредита" << endl << "8 - погаситть начисления по кредиту" << endl << "9 - досрочно погасить кредит" << endl << "0 - закончить работу" << endl << endl;
		cin >> h;

		switch (h)
		{
		case 1:
		{
			cout << "Введите свой номер счета от 0001 до 9999" << endl;
			cin >> a;
			while (a < 1 || a>9999)
			{
				cout << "Данного номера не существует!" << endl;
				cout << "Введите свой номер счета от 0001 до 9999" << endl;
				cin >> a;
			}
			cout << "Введите ФИО" << endl;
			for (int i = 0; i < 3; i++)
			{
				cin >> name;
				FIO += name;
				FIO += " ";
			}

			cout << "Введите пароль длинной больше трех символов" << endl;
			cin >> key;

			cout << "Укажите сумму вашего счета" << endl;
			cin >> s;
			person.set_person(name, key, s, a);
			person.database();
			person.get_person();
		}
		break;
		case 2:
		{
			cr.authorization(person);
		}
		break;
		case 3:
		{
			cr.available_loans(person);
		}
		break;
		case 4:
		{
			cr.check_credits(person);
		}
		break;
		case 5:
		{
			cout << "Выберите, на сколько лет вы хотите взять кредит" << endl << "1 - На 1 год" << endl << "2 - На 2 года" << endl << "3 - На 3 года" << endl << "5 - На 5 лет" << endl << " 15 - На 15 лет" << endl;
			cin >> l;
			cout << "Введите сумму кредита" << endl;
			cin >> c;
			cr.check_to_get(person, c, l);
		}
		break;
		case 6:
		{
			cout << "Укажите, сколько времени прошло" << endl;
			cin >> t;
			cr.TIME(person, c, l, t);
		}
		break;
		case 7:
		{
			cr.status_of_credit(person);
			cout << endl << "Остаток на вашем счете: " << person.take_SUM(person) << endl;
		}
		break;
		case 8:
		{
			cr.credit_repayment(person);

		}
		break;
		case 9:
		{
			cr.close_CREDIT(person, c, l);
		}
		break;
		default:
			break;
		}
	}

	cin >> a;

	cout << "";

	//person.set_number_database(j);
	//person.set_credit_database(j);
}