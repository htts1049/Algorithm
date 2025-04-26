#include <iostream>
#include <queue>

using namespace std;

typedef struct _info_
{
	int y;
	int x;
	int day;
} info;

int N, M;
int map[1000][1000];
queue<info> q;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool isRange(int y, int x)
{
	return y >= 0 && y < N && x >= 0 && x < M;
}

int bfs()
{
	int flag = false;
	int ret = 0;

	while (!q.empty())
	{
		info curr = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			info next;
			next.y = curr.y + dy[dir];
			next.x = curr.x + dx[dir];
			next.day = curr.day + 1;

			if (isRange(next.y, next.x) && map[next.y][next.x] == 0)
			{
				q.push(next);
				map[next.y][next.x] = 1;

				if (ret < next.day)
				{
					ret = next.day;
				}
			}
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (map[y][x] == 0)
			{
				flag = true;
			}
		}
	}

	// 익은 토마토의 영향이 종료되었을 때, 안익은 토마토가 있으면 -1 반환
	if (flag == true)
	{
		return -1;
	}
	
	return ret;
}

int main()
{
	// 입력
	cin >> M >> N;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> map[y][x];

			if(map[y][x] == 1)
			{
				q.push({ y, x, 0 });
			}
		}
	}
	
	cout << bfs();

	return 0;
}