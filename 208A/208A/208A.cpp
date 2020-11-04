﻿#include <iostream>
#include <string>
//Подключаем библиотеку regex
#include <regex>
using namespace std;

//удаление пробелов из начала и конца строки
string trim(string text, char whitestring = ' ')
{
	while (text[0] == whitestring)
	{
		text.erase(text.begin());
	}
	while (text[0] == whitestring)
	{
		text.erase(text.end());
	}
	return text;
}

int main()
{
	//Создаем регулярное вырожение которое ищет одно или несколько вхождений подстроки WUB подряд
	regex r("(WUB)+");

	string text;
	cin >> text;

	//Меняем все вхождения подстроки WUB которые идут подряд
	cout << trim(regex_replace(text, r, " "));

}
