#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int sudoku[9][9] = { 0 };
	int num[10] = { 0 };

	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 9; k++) {
			cin >> sudoku[i][k];
		}
	}

	int finishFlag = 0;

	for(int q = 0; q < 1000; q++) {
		for (int i = 0; i < 9; i++) {
			for (int k = 0; k < 9; k++) {

				int count = 0; // how many 0 is there?
				int saveZeroNum = 0; // where is 0?

				if (sudoku[i][k] == 0) {
					// row
					for (int p = 0; p < 9; p++) {
						if (sudoku[i][p] == 0) {
							count++;
							saveZeroNum = p;
						}
						else {
							num[sudoku[i][p]] += 1;
						}
					}
					if (count == 1) {
						for (int t = 1; t < 10; t++) {
							if (num[t] == 0) {
								sudoku[i][k] = t;
								break;
							}
						}
						// num array reset
						for (int r = 0; r < 10; r++) {
							num[r] = 0;
						}
						count = 0;
						break;
					}
					count = 0;

					// column
					for (int p = 0; p < 9; p++) {
						if (sudoku[p][k] == 0) {
							count++;
							saveZeroNum = p;
						}
						else {
							num[sudoku[p][k]] += 1;
						}
					}
					if (count == 1) {
						for (int t = 1; t < 10; t++) {
							if (num[t] == 0) {
								sudoku[i][k] = t;
								break;
							}
						}
						// num array reset
						for (int r = 0; r < 10; r++) {
							num[r] = 0;
						}
						count = 0;
						break;
					}
					count = 0;

					// 3 * 3 square 
					if (i < 3 && k < 3) {
						for (int r1 = 0; r1 < 3; r1++) {
							for (int r2 = 0; r2 < 3; r2++) {
								if (sudoku[r1][r2] == 0) {
									count++;
								}
								else {
									num[sudoku[r1][r2]] += 1;
								}
							}
						}
						if (count == 1) {
							for (int r3 = 1; r3 < 10; r3++) {
								if (num[r3] == 0) {
									sudoku[i][k] = r3;
									break;
								}
							}
							// num array reset
							for (int r = 0; r < 10; r++) {
								num[r] = 0;
							}
							count = 0;
							break;
						}
					}
					else if (i < 6 && k < 6) {
						for (int r1 = 3; r1 < 6; r1++) {
							for (int r2 = 3; r2 < 6; r2++) {
								if (sudoku[r1][r2] == 0) {
									count++;
								}
								else {
									num[sudoku[r1][r2]] += 1;
								}
							}
						}
						if (count == 1) {
							for (int r3 = 1; r3 < 10; r3++) {
								if (num[r3] == 0) {
									sudoku[i][k] = r3;
									break;
								}
							}
							// num array reset
							for (int r = 0; r < 10; r++) {
								num[r] = 0;
							}
							count = 0;
							break;
						}
					}
					else { // i < 9 && k < 9
						for (int r1 = 6; r1 < 9; r1++) {
							for (int r2 = 6; r2 < 9; r2++) {
								if (sudoku[r1][r2] == 0) {
									count++;
								}
								else {
									num[sudoku[r1][r2]] += 1;
								}
							}
						}
						if (count == 1) {
							for (int r3 = 1; r3 < 10; r3++) {
								if (num[r3]  == 0) {
									sudoku[i][k] = r3;
									break;
								}
							}
							// num array reset
							for (int r = 0; r < 10; r++) {
								num[r] = 0;
							}
							count = 0;
							break;
						}
					}
				}
				else {
					finishFlag += 1;
				}
			}
		}
		if (finishFlag == 81) {
			break;
		}
		else {
			finishFlag = 0;
		}
	} // end of while loop

	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 9; k++) {
			cout << sudoku[i][k] << " ";
		}
		cout << endl;
	}
}