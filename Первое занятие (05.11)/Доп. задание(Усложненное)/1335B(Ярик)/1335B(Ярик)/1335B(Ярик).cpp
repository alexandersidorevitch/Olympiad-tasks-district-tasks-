#include <iostream>
#include <string>
using namespace std;

void task(int n, int a, int b) {
	int len = 0;
	int tmp_char = 97;
	string s;
	while (n > len) {
		s += (char)tmp_char;
		if (tmp_char - 97 == b - 1)
			tmp_char = 97;
		else tmp_char++;
		len++;
	}
	cout << s << endl;
}

int main()
{
	int t; cin >> t;
	while (t) {
		//Лучше не инициализровать внутри цикла, так как каждый раз компилятор неявно создает 
		//и удаляет переменную, на что тратиться память и время.
		int n, a, b;
		cin >> n >> a >> b;
		task(n, a, b);
		t--;
	}
}