#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

#define cin input
#define cout output
#define pii pair<int, int>

using namespace std;

char moveKnight(pii posKing, pii posKhight) {
	if (posKhight.first >= 0 && posKhight.first <= 7 && posKhight.second >= 0 && posKhight.second <= 7 && ((abs(posKhight.first - posKing.first) == 1 && abs(posKhight.second  - posKing.second) == 2) || (abs(posKhight.first - posKing.first) == 2 && abs(posKhight.second - posKing.second) == 1)))
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
		
		if (moveKnight(posKing, make_pair(moveFirst.first + posKhight.first, moveFirst.second + posKhight.second)) == 'Y')
		{
			return 'Y';
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

	char anwerKnight = moveKnight(kingPos, knightPos);
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
