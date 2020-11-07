#include <iostream>
#include <string>
using namespace std;

string Capitalize(string s) {
	s[0] = toupper(s[0]);
	return s;
}

int main()
{
	string s;
	cin >> s;

	cout << Capitalize(s);
}
