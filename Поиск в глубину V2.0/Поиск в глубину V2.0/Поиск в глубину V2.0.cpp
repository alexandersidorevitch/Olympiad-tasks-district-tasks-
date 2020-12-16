#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
using namespace std;
struct Point
{
	string name;
	string inheritor;
	bool isVisited;
	bool operator ==(string other) {
		if (name == other)
		{
			return true;
		}
		return false;
	}
};
string printPath(string startCity, string endCity, vector<Point> Cities) {
	Point ptr = *find(Cities.begin(), Cities.end(), endCity);
	string answer = "";
	while (ptr.name != startCity)
	{
		answer = " -> " + ptr.name + answer;
		ptr = *find(Cities.begin(), Cities.end(), ptr.inheritor);
	}
	return startCity + answer;
}
int main()
{
	map<string, vector<string>> Graph;
	int countOfCities, countOfRoads;
	string firstCity, secondCity;
	Point city;
	string cityName;
	vector<Point> allCities;

	cin >> countOfCities;
	for (size_t i = 0; i < countOfCities; i++)
	{
		cin >> cityName;
		city.name = cityName;
		city.inheritor = "";
		city.isVisited = false;
		allCities.push_back(city);
	}

	cin >> countOfRoads;
	for (size_t i = 0; i < countOfRoads; i++)
	{
		cin >> firstCity >> secondCity;
		Graph[firstCity].push_back(secondCity);
		Graph[secondCity].push_back(firstCity);
	}

	string startCity, endCity, currentCity;
	cin >> startCity >> endCity;



	(*find(allCities.begin(), allCities.end(), startCity)).isVisited = true;

	stack<string> Stack;
	Stack.push(startCity);
	while (!Stack.empty())
	{
		currentCity = Stack.top();
		Stack.pop();
		for (auto town : Graph[currentCity])
		{
			auto el = find(allCities.begin(), allCities.end(), town);
			if (not (*el).isVisited)
			{
				(*el).isVisited = true;
				Stack.push((*el).name);
				(*el).inheritor = currentCity;
			}

		}

	}
	if ((*find(allCities.begin(), allCities.end(), endCity)).isVisited)
	{
		cout << printPath(startCity, endCity, allCities);
	}
	else
	{
		cout << "Пути нет";
	}
}
