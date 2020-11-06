#include <iostream>
#include <string>
#include <set>
using namespace std;

int countOfDifferentLetters(string s) {
	//SET создает коллекцию данных, из не повторяющихся элементов
	set<char> differentLetters;
	for (auto letter : s) {
		differentLetters.insert(letter);
	}
	return differentLetters.size();
}

bool isOdd(int n) {
	return n % 2;
}

int main()
{
	string s;
	cin >> s;
	
	if (isOdd(countOfDifferentLetters(s)))
	{
		cout << "IGNORE HIM!";
	}
	else {
		cout << "CHAT WITH HER!";
	}
}
