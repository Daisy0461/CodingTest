#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[501][501];
int dp[501][501];
int dy[] = { -1, 0, 1, 0 }; 
int dx[] = { 0, 1, 0, -1 };

int dfs(int y, int x)
{
	if (y == n - 1 && x == m - 1) {
		return 1;
	}
	if (dp[y][x] != -1) return dp[y][x];		//이미 값이 존재한다면 그냥 return
	
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (arr[y][x] <= arr[ny][nx]) continue;		//현재 칸이 더 작지 않다면 continue한다.

		dp[y][x] += dfs(ny, nx);		//즉, 4방향 중 가능한 ny, nx로  dfs를 돌리며 값을 더한다.
	}

	return dp[y][x];		//4방향으로 돌려서 얻은 값을 return한다.
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	fill(&dp[0][0], &dp[0][0] + 501 * 501, -1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	cout << dfs(0, 0);
}

