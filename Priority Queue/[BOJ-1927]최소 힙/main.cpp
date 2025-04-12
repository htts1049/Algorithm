#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int input;
vector<int> output;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> input;

		// 0 입력 시, top 출력 후 pop
		if (input == 0)
		{
			if (!pq.empty())
			{
				output.push_back(pq.top());
				pq.pop();
			}
			else
			{
				output.push_back(0);
			}
		}

		// 자연수 입력 시, push
		else
		{
			pq.push(input);
		}
	}
	

	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << '\n';
	}

	return 0;
}