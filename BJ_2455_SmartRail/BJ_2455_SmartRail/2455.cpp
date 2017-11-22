#include <iostream>

using namespace std;

int station[4][2] = { 0 };
int people = 0;

int main() {

	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 2; k++) {
			cin >> station[i][k];
		}
	}

	int max = 0;

	for (int i = 0; i < 4; i++) {
		people += station[i][1] - station[i][0];
		if (max < people) {
			max = people;
		}
	}
	cout << max << endl;
}