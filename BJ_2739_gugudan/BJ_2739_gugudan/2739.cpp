#include <iostream>

using namespace std;

int main() {
	int gugu = 0;
	cin >> gugu;

	for (int i = 1; i <= 9; i++) {
		cout << gugu << " * " << i << " = " << gugu*i << endl;
	}
}