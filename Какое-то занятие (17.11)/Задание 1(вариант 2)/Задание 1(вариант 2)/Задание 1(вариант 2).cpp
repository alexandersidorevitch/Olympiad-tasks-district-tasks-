﻿#include <iostream>
using namespace std;
int main()
{
	int simpleNumbers[21] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73 };
	int n;
	cin >> n;
	cout << simpleNumbers[n - 1];
}
