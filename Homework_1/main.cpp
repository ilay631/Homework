// Level HARD
#include <iostream>
#include <string>
#include <time.h>
using namespace std;


int BMSearch(string source, string template_) {
	int sourceLen = source.length();
	int templateLen = template_.length();

	int* shiffTable = new int[templateLen];
	string shiffTableContent = "";

	// Filling shiff table.
	int j = 0;
	for (int i = templateLen - 2; i >= 0; i--) {
		if (shiffTableContent.find(template_[i]) == -1) {
			shiffTable[j] = templateLen - i - 1;
			shiffTableContent += template_[i];
			j++;
		}
	}
	if (shiffTableContent.find(template_[templateLen - 1]) == -1) {
		shiffTable[j] = templateLen;
		shiffTableContent += template_[templateLen - 1];
	}

	// Search
	int p = 0;
	while (p + templateLen <= sourceLen) {
		for (int i = p + templateLen - 1; i >= p; i--) {
			if (source[i] == template_[i - p]) {
				if (i > p)
					continue;
				else
					return p;
			}
			else {
				if (i == p + templateLen - 1) {
					if (shiffTableContent.find(source[i]) != -1)
						p += shiffTable[shiffTableContent.find(source[i])];
					else
						p += templateLen;
				}
				else {
					p += shiffTable[shiffTableContent.find(template_[i - p])];
				}
			}
		}
	}

	return -1;
}



int main() {
	string source;
	string template_;

	cout << "Input source string\n";
	cin >> source;
	cout << "Input template to find it\n";
	cin >> template_;

	clock_t st = clock();
	cout << BMSearch(source, template_) << endl;
	clock_t end = clock();
	cout << "My search time = " << (double) (end - st) / CLOCKS_PER_SEC << endl;

	st = clock();
	cout << source.find(template_) << endl;
	end = clock();
	cout << "Built-in search time = " << (double)(end - st) / CLOCKS_PER_SEC << endl;

	return 0;
}
