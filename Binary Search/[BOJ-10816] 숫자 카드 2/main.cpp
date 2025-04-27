#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> cards;
vector<int> nums;

int lowerBound(int target)
{
	int left, right, mid;
	left = 0;
	right = N - 1;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (cards[mid] <= target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return left;
}

int upperBound(int target)
{
	int left, right, mid;
	left = 0;
	right = N - 1;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (cards[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return right;
}

int main()
{
	// 입력
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		cards.push_back(input);
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int input;
		cin >> input;
		nums.push_back(input);
	}


	// 정렬
	sort(cards.begin(), cards.end());

	for (int i = 0; i < nums.size(); i++)
	{
		int num = nums[i];
		cout << lowerBound(num) - upperBound(num) - 1 << " ";
	}

	return 0;
}