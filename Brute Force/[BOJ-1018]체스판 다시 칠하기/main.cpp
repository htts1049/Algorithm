#include <iostream>

using namespace std;

int M, N;
int answer;
char map[51][51];

char start_W[8][9] =
{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
char start_B[8][9] =
{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int func_W(int y, int x)
{
	int ret = 0;
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[y + i][x + j] == start_W[i][j])
			{
				ret++;
			}
		}
	}

	return ret;
}

int func_B(int y, int x)
{
	int ret = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[y + i][x + j] == start_B[i][j])
			{
				ret++;
			}
		}
	}

	return ret;
}


int main()
{
	answer = 0x7fffffff;

	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int sy = 0; sy < M; sy++)
	{

		for (int sx = 0; sx < N; sx++)
		{

			// map 안에 존재하면
			if (sy + 7 < M && sx + 7 < N)
			{

				// 8x8 순회하며 확인
				int cnt;
				for (int y = 0; y < 8; y++)
				{
					for (int x = 0; x < 8; x++)
					{
						cnt = func_W(sy, sx);
						if (cnt < answer)
						{
							answer = cnt;
						}

						cnt = func_B(sy, sx);
						if (cnt < answer)
						{
							answer = cnt;
						}
					}
				}
			}
		}
	}

	cout << answer;

	return 0;
}