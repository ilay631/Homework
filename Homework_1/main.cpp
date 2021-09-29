/*
Level - hard
*/
# include <iostream>


int add(int num1, int num2) {
	int res = num1 ^ num2;
	int shift = num1 & num2;
	while (shift) {
		shift <<= 1;
		int tmp = res;
		res = tmp ^ shift;
		shift = tmp & shift;
	}
	return res;
}


int main() {
	using namespace std;
	setlocale(LC_ALL, "Russian");
	int num1, num2;
	cout << "¬ведите первое число ";
	cin >> num1;
	cout << "¬ведите второе число ";
	cin >> num2;
	cout << add(num1, num2);
	return 0;
}
