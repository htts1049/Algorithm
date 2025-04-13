#include <iostream>

using namespace std;

int N;
char map_normal[100][100];
char map_abnormal[100][100];
int visited[100][100];
int answer_normal;
int answer_abnormal;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool isRanged(int y, int x)
{
	return y >= 0 && y < N && x >= 0 && x < N;
}

void initVisited()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			visited[y][x] = 0;
		}
	}
}

void dfsNormal(int currY, int currX, char color)
{

	for (int dir = 0; dir < 4; dir++)
	{
		int nextY = currY + dy[dir];
		int nextX = currX + dx[dir];

		// 1. 다음 위치가 맵 범위 안
		// 2. 다음 위치가 미방문 노드
		// 3. 다음 위치가 현재 노드와 색이 같음
		if (isRanged(nextY, nextX) && visited[nextY][nextX] == 0 && map_normal[nextY][nextX] == color)
		{
			visited[nextY][nextX] = 1;
			dfsNormal(nextY, nextX, color);
		}
	}
}

void dfsAbnormal(int currY, int currX, char color)
{

	for (int dir = 0; dir < 4; dir++)
	{
		int nextY = currY + dy[dir];
		int nextX = currX + dx[dir];

		// 1. 다음 위치가 맵 범위 안
		// 2. 다음 위치가 미방문 노드
		// 3. 다음 위치가 현재 노드와 색이 같음
		if (isRanged(nextY, nextX) && visited[nextY][nextX] == 0 && map_abnormal[nextY][nextX] == color)
		{
			visited[nextY][nextX] = 1;
			dfsAbnormal(nextY, nextX, color);
		}
	}
}

int main()
{
	// 입력
	cin >> N;
	for (int y = 0; y < N; y++)
	{	
		for (int x = 0; x < N; x++)
		{
			cin >> map_normal[y][x];
			map_abnormal[y][x] = map_normal[y][x];
			
			if (map_abnormal[y][x] == 'G')
			{
				map_abnormal[y][x] = 'R';
			}
		}
	}

	// 적록색약이 아닌 사람이 본 구역 개수
	initVisited();
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (visited[y][x] == 0)
			{
				visited[y][x] = 1;
				answer_normal++;
				dfsNormal(y, x, map_normal[y][x]);
			}
		}
	}

	// 적록색약인 사람이 본 구역 개수
	initVisited();
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (visited[y][x] == 0)
			{
				visited[y][x] = 1;
				answer_abnormal++;
				dfsAbnormal(y, x, map_abnormal[y][x]);
			}
		}
	}

	cout << answer_normal << " " << answer_abnormal;

	return 0;
}