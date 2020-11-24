#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int StringLenght(string s) {
	return s.length();
}
bool IsCorrectChar(char c) {
	if ((c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '2' && c <= '9' ) && c != 'l' && c != 'O' && c != 'I')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool IsCorrectString(string s) {
	if (StringLenght(s) == 8)
	{
		for (auto c : s) {
			if (not IsCorrectChar(c))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
int main()
{
	ifstream input("input.txt");
	unsigned int correctPasswords = 0, N;
	string s;
	input >> N;
	getline(input, s);
	for (unsigned int i = 0; i < N; ++i)
	{
		getline(input, s);
		if (IsCorrectString(s))
		{
			++correctPasswords;
		}
	}
	input.close();
	ofstream output("output.txt");
	output << correctPasswords << ' ' << N - correctPasswords;
	output.close();
	return 0;
}
