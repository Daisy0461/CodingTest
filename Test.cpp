//1987

#include <bits/stdc++.h>

using namespace std;

int r, c, result = 0;
int alphaArray[25][25];
int visitedAlpha[50];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0 , -1, 0 };

void dfs(int y, int x, int count)
{
	visitedAlpha[alphaArray[y][x]] = 1;		//지금 들어온 알파벳을 방문처라한다.

	bool haveNext = false;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;		//범위 밖이면 continue;
		if (visitedAlpha[alphaArray[ny][nx]]) continue;		//이미 방문한 것이라면 continue;

		haveNext = true;		//다음으로 나아갈 칸이 아직 남아있다.
		dfs(ny, nx, count + 1);
	}

	if (!haveNext) {							//현재 칸에서 더 나아가지 못해서 max와 비교한다.
		result = max(count, result);
	}

	visitedAlpha[alphaArray[y][x]] = 0;		//다른 곳으로 갈 경우에 현재 칸에 해당하는 alpha가 나올 수 있으므로 0으로 다시 만들어준다.
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> r >> c;
	
	char temp;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> temp;
			alphaArray[i][j] = temp - 'A';
		}
	}

	dfs(0, 0, 1);

	cout << result;
}