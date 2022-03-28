#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>

int CURRENT_DAY = 20220328;
using namespace std;

class Person {
private:
	string lastName, firstName, birthday;

	int countAge() {
		int bday[3], i = 0;
		string v;
		stringstream st(this->birthday);
		while (getline(st, v, '.')) bday[i++] = stoi(v);
		st.clear();
		int day = bday[2] * 10000 + bday[1] * 100 + bday[0];
		return (CURRENT_DAY - day) / 10000;
	}

	string getDay() {
		int bday[3], i = 0;
		string v;
		stringstream st(this->birthday);
		while (getline(st, v, '.')) bday[i++] = stoi(v);
		st.clear();
		int Y(bday[2]), M(bday[1]), D(bday[0]);
		int a, y, m, R;
		a = (14 - M) / 12;
		y = Y - a;
		m = M + 12 * a - 2;
		R = 7000 + (D + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
		string days[7] = { "воскресенье", "понедельник", "вторник", "среда", "четверг", "пятница", "суббота" };
		return days[R % 7];
	}

public:


	Person() {};
	~Person() {};
	Person(string ln, string fn, string bd) : lastName(ln), firstName(fn), birthday(bd) {};

	string getFirstName() { return this->firstName; }
	string getLastName() { return this->lastName; }
	string getBirthday() { return this->birthday; }

	void printFullNameAge() {
		cout << this->getLastName() << ' ' << this->getFirstName() << ": " << this->countAge() << " полных лет" << endl;
	}

	void printBirthday() {
		cout << this->getBirthday() << ", " << this->getDay() << endl;
	}

};


int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	string fn, ln, bd;
	cin >> ln >> fn >> bd;
	Person p1 = Person(ln, fn, bd);
	p1.printFullNameAge();
	p1.printBirthday();
	return 0;
}

