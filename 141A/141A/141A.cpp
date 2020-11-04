#include <iostream>
#include <string>
using namespace std;

//Возращаем индекс элемента
int indexOfElement(string text, char ch) {
	return text.find(ch);
}

//Проверяем включает ли третье слово все буквы из первого и второго слова
bool isInclude(string firstName, string secondName, string lettersInHead) {
	int index;
	//Проверяем во все ли буквы из первого слова есть в третьем слове
	for (int i = 0; i < firstName.length(); i++)
	{
		index = indexOfElement(lettersInHead, firstName[i]);
		if (index == -1)
		{
			return false;
		}
		else
		{
			lettersInHead.erase(lettersInHead.begin() + index);
		}
	}

	//Проверяем во все ли буквы из второго слова есть в третьем слове
	for (int i = 0; i < secondName.length(); i++)
	{
		index = indexOfElement(lettersInHead, secondName[i]);
		if (index == -1)
		{
			return false;
		}
		else
		{
			lettersInHead.erase(lettersInHead.begin() + index);
		}
	}
	return true;
}
int main()
{
	string firstName, secondName, lettersInHead;

	cin >> firstName;
	cin >> secondName;
	cin >> lettersInHead;

	if (isInclude(firstName, secondName, lettersInHead))
	{
		cout << "YES";
	}
	else {
		cout << "NO";
	}

}