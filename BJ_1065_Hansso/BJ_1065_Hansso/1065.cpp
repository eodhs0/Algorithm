#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int num = 0;
	int answer = 0;
	cin >> num;

	if (num < 100) {
		answer = num;
	}
	else {
		int a, b, c;
		answer = 99; // 1 ~ 99 is 99
		for (int i = 100; i <= num; i++) {
			int initial = i;

			a = i / 100;
			i = i - a * 100;
			b = i / 10;
			i = i - b * 10;
			c = i;

			i = initial;

			if ((a - b) == (b - c)) {
				answer++;
			}
		}
	}
	cout << answer << endl;
}