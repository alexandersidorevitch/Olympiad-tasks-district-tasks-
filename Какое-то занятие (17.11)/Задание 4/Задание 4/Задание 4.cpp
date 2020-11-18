#include <iostream>
#include <string>
using namespace std;
void countOfNumbers(string s, unsigned long long& countOne, unsigned long long& countTwo, unsigned long long& countThree) {
	countOne = countTwo = countThree = 0;
	for (auto number : s)
	{
		if (number == '1')
		{
			++countOne;
		}
		else if (number == '2')
		{
			++countTwo;
		}
		else
		{
			++countThree;
		}
	}
}
int main()
{
	unsigned long long countOne, countTwo, countThree, countOneTMP, countTwoTMP, countThreeTMP, N;
	string s;
	cin >> s;
	countOfNumbers(s, countOne, countTwo, countThree);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		countOneTMP = countOne;
		countTwoTMP = countTwo;
		countThreeTMP = countThree;
		countOne = countTwoTMP;
		countTwo = countOneTMP + countThreeTMP;
		countThree = countOneTMP;
	}
	cout << countOne << ' ' << countTwo << ' ' << countThree;
}
