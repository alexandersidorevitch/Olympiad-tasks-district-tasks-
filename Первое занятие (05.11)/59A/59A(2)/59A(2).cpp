#include <iostream>
#include <string>
using namespace std;

//Проверка по таблице ascii, прописная ли буква
bool isUpper(char ch) {
	//В таблице ascii большие буквы латинского(английского) алфавита храняться с 65 по 95 индексами
	if (ch >= 65 and ch <= 90)
	{
		return true;
	}
	return false;
}

//Находит кол-во больишх букв в слове
int countUpper(string text) {

	int countUpperLetters = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (isUpper(text[i]))
		{
			countUpperLetters++;
		}
	}
	return countUpperLetters;
}

//Переводит всё строку в нижний регистр
string ToLower(string text) {
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = tolower(text[i]);
	}
	return text;
}

//Переводит всё строку в вверхний регистр
string ToUpper(string text) {
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = toupper(text[i]);
	}
	return text;
}

int main()
{
	string text;
	cin >> text;

	int countUpperLetters = countUpper(text);

	//кол-во букв в нижнем регистре равно кл-ву букв в слове минус кол-ву больших букв
	//т.к. в слово по условию может входить только буквы. Цифр и спец. символов
	int countLowerLetters = text.length() - countUpperLetters;

	//Если число букв в нижнем регистре меньше или равно числу больших букв, то переводим в нижний регистр
	if (countLowerLetters >= countUpperLetters)
	{
		cout << ToLower(text);
	}
	else
	{
		cout << ToUpper(text);
	}
}