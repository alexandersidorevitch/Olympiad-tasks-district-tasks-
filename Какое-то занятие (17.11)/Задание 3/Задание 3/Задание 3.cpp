#include <iostream>
#include <cmath>
using namespace std;
int CountOfDigits(int n) {
	int count = 0;
	while (n)
	{
		n /= 10;
		++count;
	}
	return count;
}

int DigitByIndex(int n, int index) {
	return (n % (int)pow(10, index + 1) / (int)pow(10, index));
}
bool IsPalindrom(int n) {
	int lenght = CountOfDigits(n);
	for (int i = 0; i < lenght/2; i++)
	{
		if (DigitByIndex(n, i) != DigitByIndex(n,lenght - (i + 1)))
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	int i = n;
	while (not IsPalindrom(++i))
	{

	}
	cout << i;
}
