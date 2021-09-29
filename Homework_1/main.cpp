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


int divide(int num1, int num2) {
	bool negative = isNegative(num1) ^ isNegative(num2);
	num1 = absolute(num1);
	num2 = absolute(num2);
	
	int res = 0;
	while (num1 >= num2) {
		res = add(res, 1);
		num1 = subtract(num1, num2);
	}

	if (negative) {
		res = negate(res);
	}
	return res;
}


int mod(int num1, int num2) {
	bool negative = isNegative(num1);
	num1 = absolute(num1);
	num2 = absolute(num2);

	while (num1 >= num2) {
		num1 = subtract(num1, num2);
	}

	int res = num1;
	if (negative) {
		res = negate(res);
	}
	return res;
}


int power(int num1, int num2) {
	int res = 1;
	for (int i = 0; i < num2; i = add(i, 1)) {
		res = multiply(res, num1);
	}

	return res;
}


void calculate(int num1, int num2, char oper) {
	using namespace std;
	switch (oper)
	{
	case '+':
		cout << add(num1, num2) << endl;
		break;
	case '-':
		cout << subtract(num1, num2) << endl;
		break;
	case '*':
		cout << multiply(num1, num2) << endl;
		break;
	case '/':
		if (num2 != 0)
			cout << divide(num1, num2) << endl;
		else
			cout << "Divider must not be zero..." << endl;
		break;
	case '%':
		if (num2 != 0)
			cout << mod(num1, num2) << endl;
		else
			cout << "Divider must not be zero..." << endl;
		break;
	case '^':
		if (num2 >= 0)
			cout << power(num1, num2) << endl;
		else
			cout << "Degree must be non-negative..." << endl;
		break;
	default:
		cout << "Такой команды не существует..." << endl;
		break;
	}
}


int main() {
	using namespace std;
	setlocale(LC_ALL, "Russian");
	int num1, num2;
	char oper;
	cout << "Enter first number ";
	cin >> num1;
	cout << "Enter second number ";
	cin >> num2;
	cout << "Enter operator ";
	cin >> oper;

	calculate(num1, num2, oper);

	return 0;
}
