#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
	int length;
	int left;
	int right;
};

struct Node arr[100000];

int main() {
	int numOfNode = 0;
	cin >> numOfNode;

	for (int i = 0; i < numOfNode; i++) {
		int vertex = 0;
		cin >> vertex;

		int input, len;

		cin >> input;
		while (input != -1) {
			cin >> len;
			arr[input].length = len;
			cin >> input;
		}
	}0
}