#include <iostream>
#include <algorithm>

using namespace std;

int N, M, X;
int arr[100000];
int answer[100000];

int isInclude(int target)
{
	int left = 0;
	int right = N - 1;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (arr[mid] == target)
		{
			return 1;
		}
		else if (arr[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return 0;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> X;
		answer[i] = isInclude(X);
	}

	for (int i = 0; i < M; i++)
	{
		cout << answer[i] << '\n';
	}

	return 0;
}