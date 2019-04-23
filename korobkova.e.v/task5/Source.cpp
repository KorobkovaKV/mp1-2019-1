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
	int number; // ����� �����
	string name; //���
	int sum; // ����� �� ���������� �����
	string password; // ������
	int credit;
	vector <int> NUMBER;		//���� ������
	vector <string> NAME;
	vector <int> SUM;
	vector <string> PASSWORD;
	vector <int> CREDIT;
	vector <int> BALANCE; //���������� ����� �� �����

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
					cout << "������� ������ �� ����������!" << endl;
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
		cout << "���� ���: " << name << endl;
		cout << "����� �����:" << setfill('0') << setw(4) << number << endl;
		cout << "����� �����:" << sum << endl;
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
	
	int take_SUM(ProcessingCenter &PERSON)							// ����� �������
	{
		for (int i = 0; i < 10000; i++)
		{
			if (PERSON.get_number() == NUMBER[i])
			{
				return SUM[i];
			}
			else
				cout << "������� ������ �� ����������!" << endl;
		}

	}

	int take_credit(ProcessingCenter &PERSON)							// ����� �������
	{
		for (int i = 0; i < 10000; i++)
		{
			if (PERSON.get_number() == NUMBER[i])
			{
				return CREDIT[i];
			}
			else
				cout << "������� ������ �� ����������!" << endl;
		}

	}

	void take_BALANCE(ProcessingCenter &PERSON, int L)							// ����� �������
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
				cout << "������������! " << NAME[i] << endl;
				set_person(NAME[i], PASSWORD[i], SUM[i], NUMBER[i]);
				return 1;
			}
		cout << "������� ������ �� ����������!" << endl;
		return 0;
	}
};

class Credit
{
	int dT; // ������� ������� ������
	int T;
public:
	int percent1[5] = { 19, 17, 16, 15, 13 };		//�������
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

	void authorization(ProcessingCenter &PERSON)		// �����������
	{
		string ps;
		int n;
		cout << "������� ����� �����" << endl;
		cin >> n;
		//���������� n �� ����� �������� �� ���� ������		
		if (PERSON.sravnenie(n))
		{
			cout << "������� ������" << endl;
			cin >> ps;
			while (ps != PERSON.get_pasword())
			{
				cout << "������ ������ �������!"<<endl;
				cin >> ps;
			}
			cout << "������ ������ �������! �� ����� � �������!" << endl;
		}
	}

	void available_loans(ProcessingCenter PERSON)						//  ��������� �������
	{
		int l;
		int loans[6][4] = { {100000, 500000, 1000000, 3000000}, {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {5, 5, 5, 5}, {15, 15, 15, 15} };
		if (PERSON.get_sum() > 0)
		{
			cout << "��� �������� ������ �� " << loans[0][0] << " ������" << endl;

			if (PERSON.get_sum() > 100000)
			{
				cout << "����� ��� �������� ������ �� 100000 �� " << loans[0][1] << " ������" << endl;

				if (PERSON.get_sum() > 500000)
				{
					cout << "����� ��� �������� ������ �� 500000 �� " << loans[0][2] << " ������" << endl;

					if (PERSON.get_sum() > 1000000)
					{
						cout << "����� ��� �������� ������ �� 1000000 �� " << loans[0][3] << " ������" << endl;

					}
				}
			}
		}
	}

	void check_credits(ProcessingCenter &PERSON)					//�������� ������� ������� � ����� �������
	{
		if (PERSON.take_credit(PERSON) == 0)
		{
			cout << "� ��� ��� ��������� �������" << endl;
		}
			else
				cout << "� ��� ���� �������� ������, �� �� ������ ������� ����� ������, �� ������ ������" << endl << "��� ������ ���������� " << PERSON.take_credit(PERSON) << endl;
			
	}


	void check_to_get(ProcessingCenter &PERSON, int _c, int _l)						//�������� ����������� ��������� ������� � ���������
	{
		int p;
		int i = 0, d = -1; //d-������ ��� ��������� ����� � ���-�� ���
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
		cout << "�� ������ ������ �� ����� " << _c << " ������ ��� " << d << "% �������" << endl;
		PERSON.set_CREDIT(_c, p);

		p = ((_c*(1 + (d / 100.0)*_l)) / (2 * _l));				//������� �� 6 �������
		cout << "����������� ������� �� ������� ����������: " << p / 6 << endl;

		if (_c >= p)
		{
			cout << "������ �������" << endl;
		}
		else
			cout << "������ �� �������" << endl;
	}

	void status_of_credit(ProcessingCenter &PERSON)					//���������
	{
		cout << "������� �� �����, ������� �������� ��������: " << PERSON.get_BALANCE(PERSON);
	}

	void TIME(ProcessingCenter &PERSON, int _c, int _l, int _t)
	{
		int p, balance;
		int i = 0, d = -1; //d-������ ��� ��������� ����� � ���-�� ���
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


	void credit_repayment(ProcessingCenter &PERSON)					//���������
	{
		if (PERSON.get_BALANCE(PERSON) == 0)
		{
			PERSON.set_CREDIT(0, PERSON.get_number());
			cout << "������ ������!" << endl;
		}
		else
			cout << "������ �� ����� ���� ������!" << endl;
	}

	void close_CREDIT(ProcessingCenter &PERSON, int _c, int _l)						//��������� ���������
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

	cout << "������������!";
	cout << "������� ���� ����� ����� �� 0001 �� 9999" << endl;
	cin >> a;
	while (a < 1 || a > 9999)
	{
		cout << "������� ������ �� ����������!" << endl;
		cout << "������� ���� ����� ����� �� 0001 �� 9999" << endl;
		cin >> a;
	}
	cout << "������� ���" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> name;
		FIO += name;
		FIO += " ";
	}

	cout << "������� ������ ������� ������ ���� ��������" << endl;
	cin >> key;
	while (key.length() < 4)
	{
		cout << "������ ������ �� ������ ���� ��������! ��� ������ ������ ���� ������ ���� ��������" << endl;
		cin >> key;
	}

	cout << "������� ����� ������ �����" << endl;
	cin >> s;
	while (s < 0)
	{
		cout << "�� ����� ������������� �����!" << endl;
		cin >> s;
	}

	ProcessingCenter person(a, FIO, s, key, c);
	person.get_person();

	Credit cr;
	int h = 1;
	int t = 0;
	while (h != 0)
	{
		cout << endl<<"��������, ��� ������ ������� �����" << endl << "1 - �����������" << endl << "2 - �����������" << endl << "3 - ������ ��������� �������" << endl << "4 - ��������� �� ������� ��������" << endl << "5 - ��������� ����������� ��������� ���������� ������� � �������� ��������� ������" << endl << "6 - ��������� �����" << endl << "7 - �������� ��������� �������" << endl << "8 - ��������� ���������� �� �������" << endl << "9 - �������� �������� ������" << endl << "0 - ��������� ������" << endl << endl;
		cin >> h;

		switch (h)
		{
		case 1:
		{
			cout << "������� ���� ����� ����� �� 0001 �� 9999" << endl;
			cin >> a;
			while (a < 1 || a>9999)
			{
				cout << "������� ������ �� ����������!" << endl;
				cout << "������� ���� ����� ����� �� 0001 �� 9999" << endl;
				cin >> a;
			}
			cout << "������� ���" << endl;
			for (int i = 0; i < 3; i++)
			{
				cin >> name;
				FIO += name;
				FIO += " ";
			}

			cout << "������� ������ ������� ������ ���� ��������" << endl;
			cin >> key;

			cout << "������� ����� ������ �����" << endl;
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
			cout << "��������, �� ������� ��� �� ������ ����� ������" << endl << "1 - �� 1 ���" << endl << "2 - �� 2 ����" << endl << "3 - �� 3 ����" << endl << "5 - �� 5 ���" << endl << " 15 - �� 15 ���" << endl;
			cin >> l;
			cout << "������� ����� �������" << endl;
			cin >> c;
			cr.check_to_get(person, c, l);
		}
		break;
		case 6:
		{
			cout << "�������, ������� ������� ������" << endl;
			cin >> t;
			cr.TIME(person, c, l, t);
		}
		break;
		case 7:
		{
			cr.status_of_credit(person);
			cout << endl << "������� �� ����� �����: " << person.take_SUM(person) << endl;
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