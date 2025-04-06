#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;

vector<int> nodes[1001];
int visited[1001];
vector<int> result;

void init()
{
	for (int i = 0; i <= N; i++)
	{
		visited[i] = false;
	}
	result.clear();
}

void printResult()
{
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
}

void dfs(int depth, int curr)
{
	// 모든 정점이 추가되면 종료
	if (depth >= N)
	{
		return;
	}

	// 현재 정점에 연결된 노드들 탐색
	for (int i = 0; i < nodes[curr].size(); i++)
	{
		int next = nodes[curr][i];

		// 미탐색 정점이면 dfs
		if (visited[next] == false)
		{
			result.push_back(next);
			visited[next] = true;
			dfs(depth + 1, next);
		}
	}
}

void bfs(int src)
{
	queue<int> que;
	
	que.push(src);
	visited[src] = true;
	result.push_back(src);

	while (!que.empty())
	{
		int curr = que.front();
		que.pop();

		for (int i = 0; i < nodes[curr].size(); i++)
		{
			int next = nodes[curr][i];

			if (visited[next] == false)
			{
				que.push(next);
				visited[next] = true;
				result.push_back(next);
			}
		}
	}

	return;
}

int main()
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int src, dst;
		cin >> src >> dst;

		nodes[src].push_back(dst);
		nodes[dst].push_back(src);
	}

	for (int i = 0; i <= N; i++)
	{
		sort(nodes[i].begin(), nodes[i].end());
	}

	init();
	result.push_back(V);
	visited[V] = true;
	dfs(1, V);
	printResult();

	init();
	bfs(V);
	printResult();

	return 0;
}