#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
	int n, a, b, t;
	int n1[1000], a1[1000], b1[1000];
	string q = "qwertyuiopasdfghjklzxcvbnm";
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n1[i] >> a1[i] >> b1[i];
	}

	string resulte[1000];
	for (int i = 0; i < t; i++)
	{
		a = a1[i], b = b1[i], n = n1[i];
		string result = "";
		if (a == b)
		{
			for (int i = 0; i < n; i++)
			{
				result += q[i % q.length()];
			}
		}
		else if (n == a)
		{
			for (int i = 0; i < n; i++)
			{
				result += q[i % b];
			}
		}
		else if (a > b)
		{

			for (int i = 0; i < b; i++)
			{
				result += q[i];
			}
			string r = result;
			while (result.length() < n)
			{
				result += r;
			}
			result = result.substr(0, n);
		}
		resulte[i] = result;
	}
	for (int i = 0; i < t; i++)
	{
		cout << resulte[i] << endl;
	}


}