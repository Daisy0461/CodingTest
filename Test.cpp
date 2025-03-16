#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[501][501];
int dp[501][501];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int dfs(int y, int x)
{
	if (y == n - 1 && x == m- 1) return 1;
	if (dp[y][x] != -1) return dp[y][x];

	int& temp = dp[y][x];
	temp = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (arr[y][x] <= arr[ny][nx]) continue;

		temp += dfs(ny, nx);
	}

	return temp;
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
