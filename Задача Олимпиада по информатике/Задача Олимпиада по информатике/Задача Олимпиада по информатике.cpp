#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

#define cin input
#define cout output
using namespace std;
struct Participant
{
	int id;
	int summaryOfMarks;
	int command;
};
bool cmp(Participant a, Participant b) {
	if (a.summaryOfMarks > b.summaryOfMarks)
	{
		return true;
	}
	if (a.summaryOfMarks < b.summaryOfMarks)
	{
		return false;
	}
	if (a.id < b.id)
	{
		return true;
	}
	return false;
}
int main()
{
	int i;
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	//vector<int> countByDistrict;
	vector<int> quatByDistricts;
	int countOfDistricts, tmp_count, countAllComands = 0, countAllQuats = 0;
	cin >> countOfDistricts;
	vector<Participant> participantsByDistricts(countOfDistricts, Participant());

	for (size_t i = 0; i < countOfDistricts; i++)
	{
		cin >> tmp_count;
		countAllComands += tmp_count;
	}
	for (size_t i = 0; i < countOfDistricts; i++)
	{
		cin >> tmp_count;
		quatByDistricts.push_back(tmp_count);
		countAllQuats += tmp_count;
	}
	int id, sumOfMarks = 0, command;
	double mark;
	Participant participant;
	for (size_t i = 0; i < countAllComands; i++)
	{

		cin >> id >> command;
		participant.id = id;
		for (size_t j = 0; j < 4; j++)
		{
			cin >> mark;
			sumOfMarks += mark * 100;
		}
		participant.summaryOfMarks = sumOfMarks;
		participant.command = command;
		if (participant.summaryOfMarks != 0)
		{
			participantsByDistricts.push_back(participant);
		}
		sumOfMarks = 0;
	}
	sort(participantsByDistricts.begin(), participantsByDistricts.end(), cmp);


	participantsByDistricts;
	vector<vector<Participant>> answers(countOfDistricts, vector<Participant>());

	cout.precision(5);
	cout << __min(countAllQuats, participantsByDistricts.size()) << '\n';
	for (size_t i = 0; i < __min(countAllQuats, participantsByDistricts.size()); i++)
	{
	
		if (quatByDistricts[participantsByDistricts[i].command - 1] != 0 or answers[participantsByDistricts[i].command - 1][answers[participantsByDistricts[i].command - 1].size()-1].summaryOfMarks == participantsByDistricts[i].summaryOfMarks)
		{
			cout << participantsByDistricts[i].id << ' ' << (double)participantsByDistricts[i].summaryOfMarks / 100 << '\n';
		}
	}
}
