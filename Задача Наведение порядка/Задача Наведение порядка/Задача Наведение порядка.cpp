#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	map<string, int> chessPieces;
	ifstream input("input.txt");
	ofstream output("output.txt");
	int n;
	string s;
	input >> n;
	input.ignore();
	for (size_t i = 0; i < n; i++)
	{
		getline(input, s);
		++chessPieces[s];
	}
	int answer = 0, tmp;
	answer = chessPieces["black pawn"] / 8;
	answer = __min(answer, chessPieces["white pawn"] / 8);
	answer = __min(answer, chessPieces["black king"]);
	answer = __min(answer, chessPieces["white king"]);
	answer = __min(answer, chessPieces["black queen"]);
	answer = __min(answer, chessPieces["white queen"]);
	answer = __min(answer, chessPieces["black rook"] / 2);
	answer = __min(answer, chessPieces["white rook"] / 2);
	answer = __min(answer, chessPieces["black bishop"] / 2);
	answer = __min(answer, chessPieces["white bishop"] / 2);
	answer = __min(answer, chessPieces["black knight"] / 2);
	answer = __min(answer, chessPieces["white knight"] / 2);
	output << answer;

}
