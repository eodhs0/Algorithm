#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int stairs[302] = { 0 };
int dp[3][302] = { 0 };

int main() {
	int numOfStairs = 0;
	cin >> numOfStairs;

	/* input */
	for (int i = 0; i < numOfStairs; i++) {
		cin >> stairs[i];
	}

	dp[0][0], dp[1][0] = stairs[0];
	dp[2][0] = 0;

	/* dp */
	for (int i = 1; i < numOfStairs; i++) {
		for (int k = 0; k < 3; k++) {
			if (k == 0) {
				dp[k][i] = dp[1][i - 1] + stairs[i];
			}
			else if (k == 1) {
				dp[k][i] = max((dp[2][i - 1] + stairs[i]), (dp[1][i - 2] + stairs[i]));
			}
			else {
				if (i == numOfStairs - 1)
					continue;
				else {
					dp[k][i] = dp[0][i - 1];
				}
			}
		}
	}

	/*for (int i = 0; i < numOfStairs; i++) {
		for (int k = 0; k < 3; k++) {
			cout << dp[k][i] << " ";
		}
		cout << endl;
	}*/

	/* find max */
	int findMax = 0;
	for (int i = 0; i < 3; i++) {
		if (findMax < dp[i][numOfStairs - 1])
			findMax = dp[i][numOfStairs - 1];
	}
	cout << findMax << endl;
}