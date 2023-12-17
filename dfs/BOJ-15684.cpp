#include <iostream>
#include <queue>

/*---- 백준. 사다리 조작 ----*/
/*
	선을 놓을 수 있는 곳은 최대 10 x 30 = 300가지로, 3개 선을 고르는 경우는 최악의 경우 약 450만 가지로 생각할 수 있다.
	선을 골랐을 때 모든 선이 출발지와 도착지가 같은지 확인하려면 최대 10 x 30 = 300번의 연산이 필요하므로 450만 x 300은 시간복잡도를 초과한다.
	따라서 골랐던 가로선을 다시 고르지 않도록 가지를 쳐내야 한다.
	또한 가로선의 최소 값을 구해야 하므로 2개 선을 골랐을때 3개 선을 찾아보는 등의 경우가 없도록 가지를 쳐내야 한다.
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

	// 가로선을 모두 놓았을 때 확인
	if (depth == limit) {

		// 모든 선이 사다리를 타며 이동했을 때, 출발선과 도착선이 같은지 확인
		if (check()) {
			answer = depth;
		}
		return;
	}

	for (int i = currH; i <= h; i++) {
		for (int j = currN; j < n; j++) {

			// 가로선을 놓을 수 있으면 선을 놓고 다음 차례로
			if (!visited[i][j - 1] && !visited[i][j] && !visited[i][j + 1]) {

				visited[i][j] = true;
				dfs(depth + 1, limit, i, j);
				visited[i][j] = false;
			}
		}

		// 점선이 바뀔 때마다 1번 선으로 돌아온다.
		currN = 1;
	}
}

int main() {

	// 입력
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;	
		visited[a][b] = true;
	}
	
	// 가로선을 3개까지 놓아 본다.
	for (int i = 0; i <= 3; i++) {

		if (i < answer) {
			dfs(0, i, 1, 1);
		}
	}

	// 출력
	if(answer != 0x7fffffff) cout << answer;
	else cout << -1;
	
	return 0;
}