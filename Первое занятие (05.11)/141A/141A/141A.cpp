#include <iostream>
#include <string>
using namespace std;

//Возращаем индекс элемента
int indexOfElement(string text, char ch) {
	return text.find(ch);
}

//Проверяем включает ли третье слово все буквы из первого и второго слова
bool isInclude(string firstName, string secondName, string lettersInHeap) {
	int index;
	//Проверяем во все ли буквы из первого слова есть в третьем слове
	for (int i = 0; i < firstName.length(); i++)
	{
		index = indexOfElement(lettersInHeap, firstName[i]);
		if (index == -1)
		{
			return false;
		}
		else
		{
			lettersInHeap.erase(lettersInHeap.begin() + index);
		}
	}

	//Проверяем во все ли буквы из второго слова есть в третьем слове
	for (int i = 0; i < secondName.length(); i++)
	{
		index = indexOfElement(lettersInHeap, secondName[i]);
		if (index == -1)
		{
			return false;
		}
		else
		{
			lettersInHeap.erase(lettersInHeap.begin() + index);
		}
	}
	//0 = false, любое другое число = true, т.е. если строка пустая, то (bool) lettersInHeap.length() = false,
	//а not (bool) lettersInHeap.length() = true. P.s. неявное приведение типов делает сам c++.
	return not lettersInHeap.length();
}
int main()
{
	string firstName, secondName, lettersInHeap;

	cin >> firstName;
	cin >> secondName;
	cin >> lettersInHeap;

	if (isInclude(firstName, secondName, lettersInHeap))
	{
		cout << "YES";
	}
	else {
		cout << "NO";
	}

}