#include <iostream>
#include <queue>

/*---- ����. ��ٸ� ���� ----*/
/*
	���� ���� �� �ִ� ���� �ִ� 10 x 30 = 300������, 3�� ���� ������ ���� �־��� ��� �� 450�� ������ ������ �� �ִ�.
	���� ����� �� ��� ���� ������� �������� ������ Ȯ���Ϸ��� �ִ� 10 x 30 = 300���� ������ �ʿ��ϹǷ� 450�� x 300�� �ð����⵵�� �ʰ��Ѵ�.
	���� ����� ���μ��� �ٽ� ������ �ʵ��� ������ �ĳ��� �Ѵ�.
	���� ���μ��� �ּ� ���� ���ؾ� �ϹǷ� 2�� ���� ������� 3�� ���� ã�ƺ��� ���� ��찡 ������ ������ �ĳ��� �Ѵ�.
*/

using namespace std;

int n, m, h, a, b, limit;
bool visited[31][11];
int answer = 0x7fffffff;

bool check() {

	for (int col = 1; col <= n; col++) {

		int pos = col;

		for (int row = 1; row <= h; row++) {

			if (visited[row][pos - 1]) pos--;
			else if (visited[row][pos]) pos++;
		}

		if (pos != col) {
			return false;
		}
	}
	
	return true;
}

void dfs(int depth, int limit, int currH, int currN) {

	// ���μ��� ��� ������ �� Ȯ��
	if (depth == limit) {

		// ��� ���� ��ٸ��� Ÿ�� �̵����� ��, ��߼��� �������� ������ Ȯ��
		if (check()) {
			answer = depth;
		}
		return;
	}

	for (int i = currH; i <= h; i++) {
		for (int j = currN; j < n; j++) {

			// ���μ��� ���� �� ������ ���� ���� ���� ���ʷ�
			if (!visited[i][j - 1] && !visited[i][j] && !visited[i][j + 1]) {

				visited[i][j] = true;
				dfs(depth + 1, limit, i, j);
				visited[i][j] = false;
			}
		}

		// ������ �ٲ� ������ 1�� ������ ���ƿ´�.
		currN = 1;
	}
}

int main() {

	// �Է�
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;	
		visited[a][b] = true;
	}
	
	// ���μ��� 3������ ���� ����.
	for (int i = 0; i <= 3; i++) {

		if (i < answer) {
			dfs(0, i, 1, 1);
		}
	}

	// ���
	if(answer != 0x7fffffff) cout << answer;
	else cout << -1;
	
	return 0;
}