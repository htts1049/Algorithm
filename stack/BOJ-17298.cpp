#include <iostream>
#include <vector>

/*---- ����. ��ū�� ----*/
/*
	��ū�� : �ڽź��� ���� ũ�� �����ʿ� �ִ� �� �߿��� ���� ���ʿ� �ִ� ��

	�迭�� �ڿ��� ���� ��ȸ�ϸ鼭 ���þ��� �ڽź��� ���� ���� ��� pop�Ѵ�.
	�̷��� �Ǹ� �ڽź��� �����ʿ� �ִ� �� �� ū ������ ���ÿ� �����ִ�.
	���� ������ top���� �����ʿ� �ִ� �ڽź��� ū �� �߿��� ��ġ�� ���� ����� ���� �ȴ�.
	���������� �ڽ��� ���ÿ� push�ϸ� ������ ���鵵 ��ū���� ���� �� �ִ�.
*/

using namespace std;

int n, x;
vector<int> arr;
vector<int> stk;
vector<int> answer;

int main() {

	// �Է�
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(x);
	}

	for (int i = n - 1; i >= 0; i--) {

		// stk�� top�� arr[i]���� ������ ��� pop
		while (!stk.empty() && stk.back() <= arr[i]) {
			stk.pop_back();
		}

		// stk�� ��������� �����ʿ� �ڽź��� ū ���� ���� ��
		if (stk.empty()) {
			answer.push_back(-1);
		}
		else {
			answer.push_back(stk.back());
		}

		stk.push_back(arr[i]);
	}

	// ���
	while (!answer.empty()) {
		cout << answer.back() << " ";
		answer.pop_back();
	}

	return 0;
}