#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

#define cin input
#define cout output
#define pii pair<int, int>

using namespace std;

char moveKnight(pii posKing, pii posKhight, vector<pii> movesKnight) {
	if ((abs(posKhight.first - posKing.first) == 1 && abs(posKhight.second  - posKing.second) == 2) || (abs(posKhight.first - posKing.first) == 2 && abs(posKhight.second - posKing.second) == 1))
	{
		return 'Y';
	}
	return 'N';
}
char moveKing(pii posKing, pii posKhight) {
	if (abs(posKing.first - posKhight.first) <= 1 && abs(posKing.second - posKhight.second) <= 1)
	{
		return 'Y';
	}
	return 'N';
}

char moveKnightDouble(pii posKing, pii posKhight, vector<pii> movesKnight) {
	int newPosKhightX;
	int newPosKhightY;
	for (auto moveFirst : movesKnight)
	{
		for (auto moveSecond : movesKnight)
		{
			newPosKhightX = posKhight.first + moveFirst.first;
			newPosKhightY = posKhight.second + moveFirst.second;
			if ((newPosKhightX >= 0 && newPosKhightX <= 7) && newPosKhightX + moveSecond.first == posKing.first && (newPosKhightY >= 0 && newPosKhightY <= 7) && newPosKhightY + moveSecond.second == posKing.second)
			{
				return 'Y';
			}
		}
	}
	return 'N';
}
char moveKingDouble(pii posKing, pii posKhight) {
	if (abs(posKing.first - posKhight.first) <= 2 && abs(posKing.second - posKhight.second) <= 2)
	{
		return 'Y';
	}
	return 'N';
}
int main()
{
	vector<pii> movesKnight;
	movesKnight.push_back(make_pair(-1, -2));
	movesKnight.push_back(make_pair(-2, -1));
	movesKnight.push_back(make_pair(-2, 1));
	movesKnight.push_back(make_pair(-1, 2));
	movesKnight.push_back(make_pair(1, 2));
	movesKnight.push_back(make_pair(2, 1));
	movesKnight.push_back(make_pair(2, -1));
	movesKnight.push_back(make_pair(1, -2));


	ifstream cin("input.txt");
	ofstream cout("output.txt");
	string s;
	pii kingPos, knightPos;
	cin >> s;

	kingPos = make_pair(s[0] - 'a', s[1] - '1');
	cin >> s;
	knightPos = make_pair(s[0] - 'a', s[1] - '1');
	cin.close();

	char anwerKnight = moveKnight(kingPos, knightPos, movesKnight);
	if (anwerKnight == 'Y')
	{
		cout << anwerKnight << 'N';
	}
	else
	{
		cout << anwerKnight << moveKnightDouble(kingPos, knightPos, movesKnight);
	}
	anwerKnight = moveKing(kingPos, knightPos);
	if (anwerKnight == 'Y')
	{
		cout << anwerKnight << 'N';
	}
	else
	{
		cout << anwerKnight << moveKingDouble(kingPos, knightPos);
	}
}
