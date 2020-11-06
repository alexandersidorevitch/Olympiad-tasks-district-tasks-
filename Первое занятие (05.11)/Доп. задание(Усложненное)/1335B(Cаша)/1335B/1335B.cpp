#include <iostream>
#include <string>
using namespace std;
//Инициализация английского алфавита
char* GetAlphabet() {
	char* Alphabet = new char[26];
	for (int i = 0; i < 26; i++)
	{
		Alphabet[i] = char(i + 97);
	}
	return Alphabet;
}
//Базовая строка от которой мы все начинаем
string GetInitStr(int lenghtSubstring, int differentLetters, char* Alphabet) {
	string s;
	for (int i = 0; i < differentLetters; i++)
	{
		s += Alphabet[i];
	}
	for (int i = 0; i < lenghtSubstring - differentLetters; i++)
	{
		s += Alphabet[0];
	}
	return s;
}
int main()
{
	int n, lenghtSubstring, differentLetters;
	int t;
	cin >> t;
	char* Alphabet = GetAlphabet();
	string initStr;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cin >> lenghtSubstring;
		cin >> differentLetters;

		initStr = GetInitStr(lenghtSubstring, differentLetters, Alphabet);

		for (int j = 0; j < n - lenghtSubstring; j++)
		{
			initStr += initStr[j];
		}
		cout << initStr << endl;
	}
}
