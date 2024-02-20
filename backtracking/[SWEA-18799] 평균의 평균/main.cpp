#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int n;
int arr[8];
vector<int> path;
vector<double> averages;	// float을 사용할 경우 정답과 오차가 10^(-9) 보다 큼


void backtracking(int depth) {

	// n개의 서로 다른 정수를 모두 고르면 종료
	if (depth == n) {

		double sum = 0;
		for (int i = 0; i < path.size(); i++) {
			sum += path[i];
		}

		// 공집합 제외
		if (path.size() > 0) {
			averages.push_back(sum / path.size());
		}

		return;
	}


	path.push_back(arr[depth]);
	backtracking(depth + 1);
	path.pop_back();

	backtracking(depth + 1);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		// n개 정수 입력
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		// 각 부분집합의 평균 구하기
		backtracking(0);

		// 평균의 평균 구하기
		double answer = 0;
		for (int i = 0; i < averages.size(); i++) {

			answer += averages[i];
		}

		answer /= averages.size();

		// 초기화
		path.clear();
		averages.clear();

		cout.precision(20);		// 소수점 20자리로 출력하기
		cout << "#" << test_case << " " << answer << '\n';

	}
	return 0;
}