#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100][100] = { 0 };
int M, N, K = 0;

int checkX[4] = {0, 0, 1, -1};
int checkY[4] = { 1, -1, 0, 0 };

int countArray[101] = { 0 };

int dfs(int x, int y)
{
	int count = 1;
	if (x < 0 || y < 0 || y >= N || x >= M || arr[x][y] != 0)
	{
		return 0;
	}
	arr[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		count += dfs(x + checkX[i], y + checkY[i]);
	}
	return count;
}

int main()
{	
	cin >> M >> N >> K;
	int areaCount = 0;

	/* change area to 1 */
	for(int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2 = 0;

		cin >> x1 >> y1 >> x2 >> y2;

		for(int j = M-y2; j < M-y1; j++)
		{
			for(int k = x1; k < x2; k++)
			{
				arr[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int answer = dfs(i, j);
			if (answer > 0)
			{
				countArray[areaCount++] = answer;
			}		
		}
	}
	cout << areaCount << endl;
	sort(countArray, countArray + areaCount);
	for (int i = 0; i < areaCount; i++)
	{
		cout << countArray[i] << " ";
	}
	return 0;
}