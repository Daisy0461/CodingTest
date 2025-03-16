#include <bits/stdc++.h>

using namespace std;

int n, m, result = 0;
int arr[510][510];
pair <int, bool> visited[510][510];		//방문 여부, 성공여부
int dy[] = { -1, 0 ,1, 0 };
int dx[] = { 0, 1, 0, -1 };		//위, 오른, 아래, 왼

bool dfs(int y, int x) 
{
	if (y == n - 1 && x == m - 1) {		//왼쪽 하단에 도착했다.
		visited[y][x].second = true;
		result += 1;
		return true;
	}

	bool bIsGo = false;

	int nowH = arr[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;		//범위 밖이면 continue;
		if (nowH < arr[ny][nx]) continue;			//다음 칸이 더 높다면 갈 수 없으니 continue;
		if (visited[ny][nx].second == true) {		//이미 왼쪽 끝으로 갈 수 있는 길이 있는 곳이라면
			result += 1;								//result를 하나 넣어준다
			visited[y][x].second = true;
			cout << "ny : " << ny << "  nx : " << nx << " is already true\n";
			bIsGo = true;
			continue;
		}

		if (visited[ny][nx].first) {
			continue;		//이미 성공한 곳이 아닌데 방문했던 곳이라면 가지 마라
		}

		visited[ny][nx].first = 1;
		bIsGo = true;
		if (!visited[y][x].second) {		//아직 y, x에서 길을 못찾았을 때만 dfs를 돌린다. -> 
			visited[y][x].second = dfs(ny, nx);
		}
	}

	//4방향 중 아무것도 못갔다.
	if (!bIsGo) {
		return false;
	}
}

void Init()
{
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			visited[i][j] = { 0, false };
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	Init();
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}


	dfs(0, 0);

	cout << "Print bools \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j].second << " ";
		}
		cout << "\n";
	}

	cout << "\nResult \n";
	cout << result;
}
