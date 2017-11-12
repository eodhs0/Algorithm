#include <iostream>
#include <cstdlib>

using namespace std;

int N, count;
int chess[15];
int promising(int line)
{
	for (int i = 0; i < line; i++)
	{
		if (chess[i] == chess[line] || abs(chess[line] - chess[i]) == line - i)
			return 0;
	}
	return 1;
}

void nQueen(int line)
{
	if (line == N - 1)
	{
		::count++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		chess[line + 1] = i;
		if (promising(line + 1))
		{
			nQueen(line + 1);
		}
	}
}

int main()
{
	cin >> N;
	nQueen(-1);
	cout << ::count << endl;
}

