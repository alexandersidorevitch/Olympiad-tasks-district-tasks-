#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#define ll long long
using namespace std;
ll NOD(ll a, ll b) {
	a = abs(a);
	b = abs(b);
	while (a && b)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}
int main()
{
	ll n, count = 0;

	ll firstNumber, secondNumber, nod;
	ifstream input("input.txt");
	input >> n;
	set <pair<ll, ll>> fractions;
	for (size_t i = 0; i < n; ++i)
	{
		//cin >> firstNumber >> secondNumber;
		input >> firstNumber >> secondNumber;
		nod = NOD(firstNumber, secondNumber);
		fractions.insert(make_pair(firstNumber / nod, secondNumber / nod));
	}
	input.close();

	ofstream file("output.txt");
	file << fractions.size();
	file.close();

}
