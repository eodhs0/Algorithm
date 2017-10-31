#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int testCase = 0;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int n = 0;
		cin >> n;

		int dp[2][100002] = { 0 };

		/* 2-dimensional array */
		int **sticker = NULL;
		sticker = new int*[2];

		for (int j = 0; j < 2; j++) { 
			sticker[j] = new int[n+2];
		}

		/* input sticker number */
		for (int row = 0; row < 2; row++) {
			for (int col = 2; col< n+2; col++) {
				cin >> sticker[row][col];
			}
		}

		for (int k = 2; k < n+2; k++) {
			dp[0][k] = max(max(dp[0][k - 1], dp[1][k - 1] + sticker[0][k]), dp[1][k - 2] + sticker[0][k]);
			dp[1][k] = max(max(dp[1][k - 1], dp[0][k - 1] + sticker[1][k]), dp[0][k - 2] + sticker[1][k]);
		}

		if (dp[0][n + 1] < dp[1][n + 1])
			cout << dp[1][n + 1] << endl;
		else    
			cout << dp[0][n + 1] << endl;
	}
}