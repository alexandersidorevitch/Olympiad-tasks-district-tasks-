#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>
#include <string>

using namespace std;
struct Interval {
	int a;
	int b;
	bool operator<(const Interval& other) const {

		if (a < other.a)
		{
			return true;
		}
		if (a > other.a)
			return false;
		if (b < other.b)
		{
			return false;
		}
		return true;
	}
};
int main()
{
	int n, a, b;
	set<Interval> intervals;
	Interval tmpInteval;
	string s;
	ios::sync_with_stdio(false);

	getline(cin, s);
	n = stoi(s);

	for (size_t i = 0; i < n; i++)
	{
		getline(cin, s, ' ');
		a = stoi(s);
		getline(cin, s);
		b = stoi(s);
		tmpInteval.a = a;
		tmpInteval.b = b;
		intervals.insert(tmpInteval);

	}
	int count = intervals.size();
	set<Interval>::iterator first_it = intervals.begin(), second_it = intervals.begin(), tmp_it;

	for (first_it; first_it != intervals.end(); first_it = second_it)
	{
		tmp_it = first_it;
		for (second_it++; second_it != intervals.end() && (*first_it).a <= (*second_it).a && (*first_it).b >= (*second_it).b; ++second_it)
		{
			--count;
		}
	}
	cout << count;
}