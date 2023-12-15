#include <iostream>
#include <vector>

/*---- 백준. 오큰수 ----*/
/*
	오큰수 : 자신보다 값이 크고 오른쪽에 있는 수 중에서 가장 왼쪽에 있는 수

	배열을 뒤에서 부터 순회하면서 스택안의 자신보다 작은 값을 모두 pop한다.
	이렇게 되면 자신보다 오른쪽에 있는 수 중 큰 값만이 스택에 남아있다.
	따라서 스택의 top값은 오른쪽에 있는 자신보다 큰 수 중에서 위치가 가장 가까운 값이 된다.
	마지막으로 자신을 스택에 push하면 나중의 값들도 오큰수를 구할 수 있다.
*/

using namespace std;

int n, x;
vector<int> arr;
vector<int> stk;
vector<int> answer;

int main() {

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(x);
	}

	for (int i = n - 1; i >= 0; i--) {

		// stk의 top이 arr[i]보다 작으면 모두 pop
		while (!stk.empty() && stk.back() <= arr[i]) {
			stk.pop_back();
		}

		// stk이 비어있으면 오른쪽에 자신보다 큰 수가 없는 것
		if (stk.empty()) {
			answer.push_back(-1);
		}
		else {
			answer.push_back(stk.back());
		}

		stk.push_back(arr[i]);
	}

	// 출력
	while (!answer.empty()) {
		cout << answer.back() << " ";
		answer.pop_back();
	}

	return 0;
}