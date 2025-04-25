#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp
{
	bool operator() (int left, int right)
	{
		if (abs(left) > abs(right))
		{
			return true;
		}
		else if (abs(left) == abs(right))
		{
			if (left > right)
			{
				return true;
			}
		}

		return false;
	}
};

int N;
priority_queue<int, vector<int>, cmp> pq;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int cmd;
		cin >> cmd;
		
		// 0 입력 시 pop
		if (cmd == 0)
		{
			// 비어있는지 확인
			if (!pq.empty())
			{
				int top = pq.top();
				pq.pop();
				cout << top << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}

		// 그 외 값 입력 시 push
		else
		{
			pq.push(cmd);
		}
	}

	return 0;
}