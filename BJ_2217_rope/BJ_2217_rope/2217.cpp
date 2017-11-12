#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int *rope = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}
	sort(rope, rope + n);

	long int tempMax = 0;
	long int realMax = 0;

	for (int i = 0; i < n; i++) {
		tempMax = rope[i] * (n-i);

		if (tempMax > realMax) {
			realMax = tempMax;
			//cout << realMax << endl;
			tempMax = 0;
		}
	}
	cout << realMax << endl;
}