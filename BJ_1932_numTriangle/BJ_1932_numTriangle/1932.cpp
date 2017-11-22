#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int triangle[500][500] = { 0 };
int dp[500][500] = { 0 };

int main() {
	int floor = 0;

	cin >> floor;

	/* input triangle number */
	for (int i = 0; i < floor; i++) {
		for (int k = 0; k < i + 1; k++) {
			cin >> triangle[i][k];
		}
	}

	dp[0][0] = triangle[0][0];

	/* lets go DP */
	for (int i = 1; i < floor; i++) {
		for (int k = 0; k < i + 1; k++) {

			if (k == 0) { /* the leftest side number in each floor */
				dp[i][k] = dp[i - 1][k] + triangle[i][k];
			}

			else if (k == i) { /* the rightest side number in each floor */
				dp[i][k] = dp[i - 1][k-1] + triangle[i][k];
			}

			else { /* the midle number in each floor */
				dp[i][k] = max(dp[i - 1][k - 1], dp[i - 1][k]) + triangle[i][k];
			}
		}
	}

	int max = 0;
	/* find max num in lowest floor */
	for (int i = 0; i < floor; i++) {
		if (max < dp[floor-1][i])
			max = dp[floor-1][i];
	}
	cout << max << endl;
}