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


int negate(int num) {
	return (add(~num, 1));
}


int subtract(int num1, int num2) {
	return add(num1, negate(num2));
}


bool isNegative(int num) {
	return num >> 31;
}


int absolute(int num) {
	if (isNegative(num)) {
		return negate(num);
	}
	return num;
}


int multiply(int num1, int num2) {
	bool negative = isNegative(num1) ^ isNegative(num2);
	num1 = absolute(num1);
	num2 = absolute(num2);

	int i = 0;
	int res = 0;
	while (num2) {
		if (num2 & 1) {
			res = add(res, num1 << i);
		}
		num2 >>= 1;
		i = add(i, 1);
	}

	if (negative) {
		res = negate(res);
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
	cout << multiply(num1, num2);
	return 0;
}
