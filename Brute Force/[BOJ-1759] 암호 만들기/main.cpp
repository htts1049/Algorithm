#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, C;
int cnt_aeiou;
int cnt_else;
vector<char> characters;
vector<char> path;
bool visited[15];

bool isAEIOU(char ch)
{
	switch (ch)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	}

	return false;
}

void dfs(int depth, int index)
{	
	// L개 알파벳 고름
	if (depth == L)
	{

		// 모음 1개 이상, 자음 2개 이상
		if (cnt_aeiou >= 1 && cnt_else >= 2)
		{
			for (int i = 0; i < path.size(); i++)
			{
				cout << path[i];
			}
			cout << '\n';
		}
		return;
	}

	// 현재 고른 알파벳보다 순서가 낮은 알파벳은 고르지 않음
	for (int i = index; i < C; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			path.push_back(characters[i]);

			// 모음, 자음 개수 세기
			if (isAEIOU(characters[i]))
			{
				cnt_aeiou++;
			}
			else
			{
				cnt_else++;
			}


			dfs(depth + 1, i);


			visited[i] = 0;
			path.pop_back();

			if (isAEIOU(characters[i]))
			{
				cnt_aeiou--;
			}
			else
			{
				cnt_else--;
			}
		}
	}
}

int main()
{
	// 입력
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		char input;
		cin >> input;
		characters.push_back(input);
	}

	// 정렬
	sort(characters.begin(), characters.end());
	
	// 완전 탐색
	dfs(0, 0);

	return 0;
}