#include <iostream>
#include "windows.h"

using namespace std;

bool Poli(char* text) {

	for (int i = 0, j = strlen(text) - 1; i < j;) {
		if (isalpha((unsigned char)text[i])) {
			if (isalpha((unsigned char)text[j])) {
				if (tolower(text[i]) != tolower(text[j])) return 0;
				i++; j--;
			}
			else j--;
		}
		else i++;
	}

	return 1;
}

bool Poli2(char* text) {

	int n = strlen(text);
	int i = 0;
	while (i < n) {
		if (!isalpha((unsigned char)text[i])) {
			for (int j = i; j < n - 1; j++)
				text[j] = text[j + 1];
			n--;
		}
		text[i] = tolower(text[i]);
		i++;
	}
	text[n] = '\0';

	n = strlen(text);
	for (int i = 0; i < n / 2; i++)
		if (text[i] != text[n - i - 1])
			return 0;

	return 1;
}

bool Poli3(char* text1, char* text2) {

	int n = strlen(text1);

	int k = 0;
	for (int i = 0; i < n; i++) {
		if (isalpha((unsigned char)text1[i])) {
			text2[k++] = tolower(text1[i]);
		}
	}

	for (int i = 0; i < n / 2; i++) {
		if (text2[i] != text2[n - i - 2])
			return 0;
	}

	return 1;
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char* text = new char[255];
	cout << "Введите строку длиной не более 255 символов: ";
	cin.getline(text, 255);

	char* text2 = new char[255];
	//cout << "1 способ" << endl;
//if(Poli(text)) cout << "Палиндром\n"; else cout << "Не палиндром\n";
	//cout << "2 способ" << endl;
  // if(Poli2(text)) cout << "Палиндром\n"; else cout << "Не палиндром\n";
	cout << "3 способ" << endl;
	if (Poli3(text, text2)) cout << "Палиндром\n"; else cout << "Не палиндром\n";

	system("pause");
	return 0;
}