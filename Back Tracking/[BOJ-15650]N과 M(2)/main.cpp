#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool visited[9];
vector<int> result;

void printResult()
{
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << '\n';
}

void backtracking(int depth, int start)
{
	if (depth == M)
	{
		printResult();
		return;
	}

	for (int i = start; i <= N; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			result.push_back(i);

			backtracking(depth + 1, i);
			
			visited[i] = false;
			result.pop_back();
		}
	}
}

int main()
{
	cin >> N >> M;

	backtracking(0, 1);

	return 0;
}