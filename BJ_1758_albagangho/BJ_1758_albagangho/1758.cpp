#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	long int answer = 0;
	int numOfPeople = 0;
	cin >> numOfPeople;

	int *tip = NULL;
	tip = new int[numOfPeople];
	
	for (int i = 0; i < numOfPeople; i++) {
		cin >> tip[i];
	}
	sort(tip, tip + numOfPeople, std::greater<int>());

	/*for (int i = 0; i < numOfPeople; i++) {
		cout << tip[i] << " ";
	}
	cout << endl;*/

	for (int i = 0; i < numOfPeople; i++) {
		long int sum = tip[i] - i;
		if (sum > 0) {
			answer += sum;
		}
	}
	cout << answer;
}