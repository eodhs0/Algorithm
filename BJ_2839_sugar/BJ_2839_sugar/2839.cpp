#include <iostream>

using namespace std;

int main() {
	int sugar = 0;
	cin >> sugar;

	// count valuable of 3, 5
	int five = 0;
	int three = 0;
	
	int inifive = sugar / 5;
	int flag = 0;

	while (inifive > -1) {
		if ((sugar - inifive * 5) % 3 == 0) {
			five = inifive;
			three = (sugar - (inifive * 5)) / 3;
			break;
		}
		else {
			inifive--;
		}
		if (inifive < 0)
			flag = 1;
	}
	if (flag == 0)
		cout << five + three << endl;
	else
		cout << -1 << endl;
}