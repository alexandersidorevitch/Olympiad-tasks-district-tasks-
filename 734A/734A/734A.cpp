#include <iostream>
#include <string>
using namespace std;

//Высчитываем кол-во вигранных матчей и возращаем значения в переданные переменные
void countOfWins(string outcomesOfChessMatches, int& countWinsAnton, int& countWinsDanik) {
	for (int i = 0; i < outcomesOfChessMatches.length(); i++)
	{
		if (outcomesOfChessMatches[i] == 'A')
		{
			countWinsAnton += 1;
		}
		else {
			countWinsDanik += 1;
		}
	}
}
int main()
{
	int tmp;
	string outcomesOfChessMatches;

	cin >> tmp;

	cin >> outcomesOfChessMatches;

	int countWinsAnton = 0;
	int countWinsDanik = 0;

	countOfWins(outcomesOfChessMatches, countWinsAnton, countWinsDanik);


	if (countWinsAnton > countWinsDanik)
	{
		cout << "Anton";
	}
	else if (countWinsAnton < countWinsDanik)
	{
		cout << "Danik";
	}
	else {
		cout << "Friendship";
	}

}
