#include <iostream>

using namespace std;

int T;
int N;
int count[41][2];

int main()
{
	cin >> T;
	for(int tc =0; tc < T; tc++)
	{
		cin >> N;

		// 초기화
		for(int i=0; i<=N; i++)
		{
			count[i][0] = 0;
			count[i][1] = 0;
		}
		count[0][0] = 1;
		count[0][1] = 0;
		count[1][0] = 0;
		count[1][1] = 1;
		
		// 출력된 0과 1의 개수 계산
		for(int i=2; i<=N; i++)
		{
			count[i][0] += count[i-1][0];
			count[i][0] += count[i-2][0];

			count[i][1] += count[i-1][1];
			count[i][1] += count[i-2][1];
		}
		
		cout << count[N][0] << " " << count[N][1] << endl;
	}

	return 0;
}