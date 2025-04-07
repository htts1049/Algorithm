#include <iostream>

using namespace std;

int N, M;

int visited[9];
int result[9];

void dfs(int depth)
{
	// M개 출력 시 종료
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << result[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			result[depth] = i;

			dfs(depth + 1);

			visited[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M;

	dfs(0);

	return 0;
}