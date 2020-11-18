#include <iostream>
#include <cmath>
using namespace std;
bool isSquareNumber(unsigned long long n) {
	double sqrtOfNumber = sqrt(n);
	if (sqrtOfNumber - (int)sqrtOfNumber < 0.00000000001)
	{
		return true;
	}
	return false;
}
int main()
{
	unsigned long long N, M;
	cin >> N;
	unsigned long long i = 0;
	while (!isSquareNumber(N * ++i))
	{

	}
	cout << i;
}
