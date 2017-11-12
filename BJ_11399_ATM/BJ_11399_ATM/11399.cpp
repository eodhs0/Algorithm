#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int helpSum = 0;
	int answer = 0;
	cin >> n;

	int *people = new int[n];

	for (int k = 0; k < n; k++) {
		cin >> people[k];
	}

	sort(people, people + n);
	
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < i+1; k++) {
			helpSum += people[k];
		}
		answer += helpSum;
		helpSum = 0;
	}
	cout << answer << endl;
}