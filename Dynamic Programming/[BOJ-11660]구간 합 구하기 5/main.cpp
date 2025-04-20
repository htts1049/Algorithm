#include <iostream>

using namespace std;

int N, M;

int map[1025][1025];
int sum[1025][1025];

int rowcol[100000][4];

int main()
{
	// 입력
	cin >> N >> M;

	for (int x = 1; x <= N; x++)
	{
		for (int y = 1; y <= N; y++)
		{
			cin >> map[x][y];
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> rowcol[i][0] >> rowcol[i][1] >> rowcol[i][2] >> rowcol[i][3];
	}


	// (1, 1) 에서 (x, y) 까지의 합을 담은 배열 구하기
	for (int x = 1; x <= N; x++)
	{
		for (int y = 1; y <= N; y++)
		{
			sum[x][y] = map[x][y] + sum[x][y - 1] + sum[x - 1][y] - sum[x - 1][y - 1];
		}
	}

	// 주어진 (x1, y1), (x2, y2) 사이의 부분합 구하기
	for (int i = 0; i < M; i++)
	{
		int x1 = rowcol[i][0];
		int y1 = rowcol[i][1];
		int x2 = rowcol[i][2];
		int y2 = rowcol[i][3];

		int answer = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];

		cout << answer << '\n';
	}

	return 0;
}