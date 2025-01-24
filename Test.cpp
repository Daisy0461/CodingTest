#include <bits/stdc++.h>

using namespace std;

int dc;
int result = 0;
int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0 ,-1, 0 };
int points[105][105];
vector<int> pastDir;

void dragonCurve(int y, int x, int dir, int g)
{
	points[y][x] = 1; 
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	pastDir.push_back(dir);
	points[ny][nx] = 1; 

	while (g) {
		g -= 1;
		int pd = pastDir.size() - 1;
		for (int i = pd; i >= 0; i--) {		//뒤에서부터 앞으로
			int nd = (pastDir[i] + 1) % 4;
			ny = ny + dy[nd];
			nx = nx + dx[nd];
			pastDir.push_back(nd);
			points[ny][nx] = 1;
		}
	}

}

void FindSquere()
{
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (points[i][j] && points[i + 1][j] && points[i][j + 1] && points[i + 1][j + 1]) {
				result++;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> dc;
	int sx, sy, sd, g;
	for (int i=0; i < dc; i++) {
		pastDir.clear();
		cin >> sx >> sy >> sd >> g;
		dragonCurve(sy, sx, sd, g);
	}

	FindSquere();

	cout << result;

}
