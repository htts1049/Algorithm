#include <iostream>

using namespace std;

int N, M;
int flag;
int map[300][300];
int cnt[300][300];
int visited[300][300];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int answer = 0;

bool isRange(int y, int x)
{
	return y >= 0 && y < N && x >= 0 && x < M;
}

void initVisited()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			visited[y][x] = 0;
		}
	}
}

void melt()
{
	// 각 점마다 동서남북이 0인 개수를 저장
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cnt[y][x] = 0;

			if (map[y][x] > 0)
			{

				for (int dir = 0; dir < 4; dir++)
				{
					int nextY = y + dy[dir];
					int nextX = x + dx[dir];

					if (isRange(nextY, nextX) && map[nextY][nextX] == 0)
					{
						cnt[y][x]++;
					}
				}
			}
		}
	}

	// 동서남북 중 0인 개수만큼 빼기
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (cnt[y][x] > 0)
			{
				map[y][x] -= cnt[y][x];

				if (map[y][x] < 0)
				{
					map[y][x] = 0;
				}
			}
		}
	}
}


void dfs(int y, int x)
{

	for (int dir = 0; dir < 4; dir++)
	{
		int nextY = y + dy[dir];
		int nextX = x + dx[dir];

		// 범위 체크, 미방문 체크
		// 다음 노드가 빙산이 아니어야 함
		if (isRange(nextY, nextX) && visited[nextY][nextX] == 0 && map[nextY][nextX] > 0)
		{
			visited[nextY][nextX] = 1;
			dfs(nextY, nextX);
		}
	}
}

int isSplited()
{
	int zero = 0;
	int group = 0;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{

			if (map[y][x] == 0)
			{
				zero++;
			}

			if (visited[y][x] == 0 && map[y][x] > 0)
			{
				visited[y][x] = 1;
				group++;
				dfs(y, x);
			}
		}
	}

	// 빙산이 다 녹은 경우
	if (zero == N * M)
	{
		return 1;
	}

	// 빙산이 분리된 경우
	else if (group > 1)
	{
		return 2;
	}

	return 0;
}

int main()
{
	// 입력
	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> map[y][x];
		}
	}

	// 빙산이 다 녹거나, 나뉠때 까지 시간 증가
	while (true)
	{

		if (( flag = isSplited()) > 0)
		{
			break;
		}
		else
		{
			answer++;
			melt();
		}

		initVisited();
	}

	// 빙산이 다 녹을 때까지 분리되지 않으면 0 출력
	if (flag == 1)
	{
		cout << 0;
	}

	// 빙산이 나뉜 시간 출력
	else if(flag == 2)
	{
		cout << answer;
	}
	
	return 0;
}