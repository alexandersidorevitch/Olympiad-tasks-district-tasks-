#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	string s, news;
	int t;
	cin >> t;
	int n, a, b;
	//Небольшое замечание на будущее, 3 вложенных for - зло.
	//В этом случае нормально, но в других случаях это может сыграть злую шутку
	while (t != 0) {
		cin >> n >> a >> b;
		for (int i = 0; i < n;) {
			for (int j = 0; j < a; j++) {
				char f;
				f = 97;
				for (int m = 0; m < b; ++m) {
					cout << f;
					j++;
					i++;
					f++;
					if (i == n)
						break;
				}
				f = 97;
				if (i == n)
					break;
			}
			if (i == n)
				break;
		}
		t--;
		cout << "\n";
	}
}