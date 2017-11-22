#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

//3 
//
//1 20 30
//
//50 5 6
//
//9 3 7
// 이거 해결해야함.

int house[1001][3];
int dp[1002][3] = { 0 };

/* House order : Red, Green Blue */

int main() {
	int numOfHouse = 0;
	cin >> numOfHouse;

	/* input */
	for (int i = 0; i < numOfHouse; i++) {
		for (int k = 0; k < 3; k++) {
			cin >> house[i][k];
		}
	}
	
	dp[0][0] = house[0][0];
	dp[0][1] = house[0][1];
	dp[0][2] = house[0][2];

	/* dp */
	for (int i = 1; i < numOfHouse; i++) {
		for (int k = 0; k < 3; k++) {
			if (k == 0) {
				dp[i][k] = min(dp[i - 1][1], dp[i-1][2]) + house[i][k];
			}
			else if (k == 1) {
				dp[i][k] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][k];
			}
			else {
				dp[i][k] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][k];
			}
		}
	}

	/* print dp */
	/*for (int i = 0; i < numOfHouse; i++) {
		for (int k = 0; k < 3; k++) {
			cout << dp[i][k] << " ";
		}
		cout << endl;
	}*/
	
	/* find minimum price */
	int min = 999999999;
	for (int i = 0; i < 3; i++) {
		if (dp[numOfHouse - 1][i] < min)
			min = dp[numOfHouse - 1][i];
	}
	cout << min << endl;
}