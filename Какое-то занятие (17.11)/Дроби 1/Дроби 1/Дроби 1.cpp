#include <iostream>

#define ui unsigned int
using namespace std;

ui gcd(ui a, ui b) {
	while (a && b)
		if (a > b)
			a %= b;
		else
			b %= a;
	return a + b;
}

int main()
{
	long double x, proiz;
	ui n;
	ios::sync_with_stdio(false);
	cin >> x >> n;
	ui c = 0;
	ui g, i, j;
	proiz = x * n;
	for (i = 1; i <= proiz; i++)
	{
		for (j = n; j > 1 && (long double)i / (long double)j <= x; j--)
		{

			if (gcd(i, j) == 1) ++c;
		}
	}
	cout << c;
}