# include <iostream>
using namespace std;


void fillMas(int** mas, int length, int width) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			mas[i][j] = rand() % 41 + 10;
		}
	}
}


void printMas(int** mas, int length, int width) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
}



int main() {
	cout << "Input length of mas" << endl;
	int length, width;
	cin >> length;
	cout << "Input width of mas" << endl;
	cin >> width;
	int** mas = new int*[length];
	for (int i = 0; i < length; i++)
		mas[i] = new int[width];
	fillMas(mas, length, width);
	printMas(mas, length, width);

	return 0;
}