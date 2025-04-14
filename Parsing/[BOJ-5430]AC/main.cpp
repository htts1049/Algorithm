#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T;
int n;

int isReverse;
bool isError;
string cmds;
string str;
vector<int> nums;

void getNums()
{
	for (int i = 0; i < str.size(); i++)
	{
		// 특수 문자 무시
		if (str[i] == '[' || str[i] == ']' || str[i] == ',')
		{
			continue;
		}

		// 숫자로 변환
		int num = 0;
		while (i < str.size() && str[i] >= '0' && str[i] <= '9')
		{
			num *= 10;
			num += str[i] - '0';
			i++;
		}

		// 숫자 저장
		nums.push_back(num);
	}
}

int main()
{
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		nums.clear();

		cin >> cmds >> n >> str;
		getNums();

		isReverse = 0;
		isError = false;

		int left = 0;
		int right = nums.size();

		// 명령 수행
		for (int i = 0; i < cmds.length(); i++)
		{
			// R 이면 뒤집기
			if (cmds[i] == 'R')
			{
				isReverse = (isReverse + 1) % 2;
			}
			// D 면 첫번째 문자 빼기
			else
			{
				// Empty 체크
				if (left >= right)
				{
					isError = true;
				}
				else
				{
					// 정방향이면 front 빼기
					if (isReverse == 0)
					{
						left++;
					}
					// 역방향이면 rear 빼기
					else
					{
						right--;
					}
				}
			}
		}


		// 출력
		if (isError)
		{
			cout << "error" << '\n';
		}
		else
		{
			cout << '[';

			if (!isReverse)
			{
				for (int i = left; i < right; i++)
				{
					cout << nums[i];

					if (i < right - 1)
					{
						cout << ',';
					}
				}
			}
			else
			{
				for (int i = right - 1; i >= left; i--)
				{
					cout << nums[i];

					if (i > left)
					{
						cout << ',';
					}
				}
			}

			cout << ']' << '\n';
		}
	}

	return 0;
}