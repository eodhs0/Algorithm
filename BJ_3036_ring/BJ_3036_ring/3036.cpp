#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;
void GCD(int a, int b);

int ring[101] = { 0 };

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ring[i];
	}

	for (int i = 1; i < n ; i++) {
		int standardNum = ring[0];
		int small = min(standardNum, ring[i]);
		for (int k = 2; k <= small; k++) {
			if (standardNum%k == 0 && ring[i] %k == 0) {
				standardNum /= k;
				ring[i] /= k;
				small = min(standardNum, ring[i]);
				k = 1;
			}
		}
		cout << standardNum << "/" << ring[i] << endl;
	}
}