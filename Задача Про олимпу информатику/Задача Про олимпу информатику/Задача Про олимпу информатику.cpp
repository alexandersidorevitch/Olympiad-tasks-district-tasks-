#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

#define cin input
#define cout output
#define cmpDouble(a,b) abs(a - b) < 0.005 ? true : false
using namespace std;
struct Participant
{
	int id;
	double summaryOfMarks;
	int command;
	char status;
};
bool cmp(Participant a, Participant b) {
	if (cmpDouble(a.summaryOfMarks, b.summaryOfMarks))
	{
		if (a.id < b.id)
		{
			return true;
		}
		return false;
	}
	if (a.summaryOfMarks > b.summaryOfMarks)
	{
		return true;
	}
	if (a.summaryOfMarks < b.summaryOfMarks)
	{
		return false;
	}
	
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	vector<Participant> participantsByDistricts;
	vector<int> countByDistrict;
	vector<int> maxQuatByDistricts;
	int countOfDistricts, tmp_count, allParticipants = 0, allQuats = 0;
	cin >> countOfDistricts;
	vector<vector<Participant>> participantsByQuats(countOfDistricts, vector<Participant>());
	vector<double> minByDistricts(countOfDistricts, 0x3f3f3f3f);
	vector<int> quatByDistricts(countOfDistricts,0);

	for (size_t i = 0; i < countOfDistricts; i++)
	{
		cin >> tmp_count;
		countByDistrict.push_back(tmp_count);
		allParticipants += tmp_count;
	}
	for (size_t i = 0; i < countOfDistricts; i++)
	{
		cin >> tmp_count;
		maxQuatByDistricts.push_back(tmp_count);
	}
	unsigned int id,  command, size = 0;
	double mark, sumOfMarks = 0;
	Participant participant;
	for (size_t i = 0; i < allParticipants; i++)
	{
		cin >> id >> command;
		participant.id = id;
		for (size_t j = 0; j < 4; j++)
		{
			cin >> mark;
			sumOfMarks += mark;
		}
		participant.summaryOfMarks = sumOfMarks;
		participant.command = command - 1;
		participant.status = 'n';
		participantsByDistricts.push_back(participant);

		sumOfMarks = 0;
	}


	sort(participantsByDistricts.begin(), participantsByDistricts.end(), cmp);
	for (size_t i = 0; i < participantsByDistricts.size() && participantsByDistricts[i].summaryOfMarks != 0; i++)
	{
		
		if (maxQuatByDistricts[participantsByDistricts[i].command] > quatByDistricts[participantsByDistricts[i].command] || cmpDouble(minByDistricts[participantsByDistricts[i].command], participantsByDistricts[i].summaryOfMarks) )
		{
			minByDistricts[participantsByDistricts[i].command] =  participantsByDistricts[i].summaryOfMarks;
			++quatByDistricts[participantsByDistricts[i].command];
			participantsByDistricts[i].status = 'y';
			++size;
		}
	}
	unsigned int n;
	cout << size << '\n';
	cout.precision(5);
	for (size_t i = 0; i < participantsByDistricts.size() && participantsByDistricts[i].summaryOfMarks != 0; i++)
	{

		if (participantsByDistricts[i].status == 'y')
		{

			cout << participantsByDistricts[i].id << ' ' << participantsByDistricts[i].summaryOfMarks << '\n';
			
		}
	}
}
