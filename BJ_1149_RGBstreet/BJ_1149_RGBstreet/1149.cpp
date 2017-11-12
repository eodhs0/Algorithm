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

void dpF(int arr[][3], int idx, int numOfHouse) {
	int initialidx = idx;
	int first = 0, firstidx = 0;
	int second = 0, secondidx = 0;
	for (int i = 1; i < numOfHouse; i++) {
		first = 0; second = 0;
		for (int k = 0; k < 3; k++) {
			if (idx == k) {
				continue;
			} 
			if (first == 0) {
				first = arr[i][k];
				firstidx = k;
			}
			else {
				second = arr[i][k];
				secondidx = k;
			}
		}
		if (first < second) {
			dp[i][initialidx] = first + dp[i - 1][initialidx];
			idx = firstidx;
		}
		else {
			dp[i][initialidx] = second + +dp[i - 1][initialidx];
			idx = secondidx;
		}
	}
}

int main() {
	int numOfHouse = 0;

	cin >> numOfHouse;

	for (int i = 0; i < numOfHouse; i++) {
		cin >> house[i][0] >> house[i][1] >> house[i][2];
	}

	int dp0idx = 0;
	int dp1idx = 1;
	int dp2idx = 2;

	dp[0][0] = house[0][0]; dp[0][1] = house[0][1]; dp[0][2] = house[0][2];
	
	dpF(house, 0, numOfHouse);
	dpF(house, 1, numOfHouse);
	dpF(house, 2, numOfHouse);

	//cout << dp[numOfHouse - 1][0] << " " << dp[numOfHouse - 1][1] << " " << dp[numOfHouse - 1][2] << endl;

	cout << min(min(dp[numOfHouse - 1][0], dp[numOfHouse - 1][1]), dp[numOfHouse - 1][2]) << endl;
}