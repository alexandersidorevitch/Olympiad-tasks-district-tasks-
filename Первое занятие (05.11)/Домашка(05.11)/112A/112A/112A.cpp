#include <iostream>
#include <string>
using namespace std;

string ToLower(string s) {
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);
	}
	return s;
}
int main()
{
	string firstString, secondString;
	cin >> firstString >> secondString;

	firstString = ToLower(firstString);
	secondString = ToLower(secondString);

	if (firstString == secondString)
	{
		cout << 0;
	}
	else if (firstString < secondString) 
	{
		cout << -1;
	}
	else
	{
		cout << 1;
	}
}