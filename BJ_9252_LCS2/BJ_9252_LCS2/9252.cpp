#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int LCS[1001][1001] = { 0 };
//int LCS[501][501] = { 0 };
char sentence1[1001];
char sentence2[1001];
int senSize1 = 0;
int senSize2 = 0;

int main() {

	vector<char>answer;

	cin >> sentence1 >> sentence2;

	senSize1 = strlen(sentence1);
	senSize2 = strlen(sentence2);

	/* calculate LCS */
	for (int i = 1; i <= senSize1; i++) {
		for (int k = 1; k <= senSize2; k++) {
			if (sentence1[i - 1] == sentence2[k - 1]) {
				LCS[i][k] = LCS[i - 1][k - 1] + 1;
			}
			else {
				LCS[i][k] = (LCS[i - 1][k] > LCS[i][k - 1] ? LCS[i - 1][k] : LCS[i][k - 1]);
			}
		}
	}

	cout << LCS[senSize1][senSize2] << endl;

	/* find subsequence */
	int count = 0; // I will find a LCS as many as LCS length

	int row = senSize1;
	int col = senSize2;

	string answerS;

	while (count != LCS[senSize1][senSize2]) {
		// case of adding answer array
		if (LCS[row - 1][col - 1] == LCS[row][col] - 1 &&
			LCS[row - 1][col] == LCS[row][col] - 1 &&
			LCS[row][col - 1] == LCS[row][col] - 1) {
			//answer.push_back(sentence1[row - 1]);
			answerS += sentence1[row - 1];
			row--;
			col--;
			count++;
		}
		else if (LCS[row - 1][col] == LCS[row][col]) {
			row--;
		}
		else {
			col--;
		}
	}
	
	for (int i = answerS.size() - 1; i > -1; i--) {
		cout << answerS[i];
	}
	cout << endl;
}