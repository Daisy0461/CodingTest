#include <bits/stdc++.h>

using namespace std;

int dc, result = 0;
int sx, sy, sd, g;			//시작 x, y위치, direction(1 = ->, 2 = 아래, 3 = <-, 4= 위), g = 몇번 커브하는가? g = 0일 때 direction 방향으로 한번은 간다.
int dy[] = { 0, -1, 0 ,1 };
int dx[] = { 1, 0, -1, 0 };

int sumArray[105][105];
vector<pair<int, int>> tempPoints;


void dragonCurve(int y, int x, int dir, int g)
{
	if (g < 0) {
		tempPoints.push_back({ sy, sx });
		cout << "tempPoints Size : " << tempPoints.size() << "\n";
		for (auto i : tempPoints) {
			cout << "y: " << i.first << "   x : " << i.second << "\n";
			sumArray[i.first][i.second] = 1;
		}
		return;
	}

	g -= 1;
	int ny = y, nx = x;
	if (!tempPoints.size()) {
		ny = y + dy[dir];
		nx = x + dx[dir];
		tempPoints.push_back({ ny, nx });
		dir = (dir + 1) % 4;
		dragonCurve(ny, nx, dir, g);
		return;
	}

	//최초가 아니다.
	int ts = tempPoints.size();
	for (int i = 0; i < ts; i++) {
		//dir은 이미 갱신 되어있음.
		ny = ny + dy[dir];
		nx = nx + dx[dir];
		tempPoints.push_back({ ny, nx });
		dir = (dir + 1) % 4;
	}

	dragonCurve(ny, nx, dir, g);

}

void FindSquere()
{
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			bool bIsFind = true;
			for (int d = 0; d < 4; d++) {
				if (sumArray[i + dy[d]][j + dx[d]] == 0) {
					bIsFind = false;
				}
			}

			//정사각형 찾음.
			if (bIsFind) {
				result++;
			}
		}
	}
	
}

void printPoints()
{
	cout << "\n\nFind Points \n";
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (sumArray[i][j] == 1) {
				cout << "y : " << i << "    x : " << j << "\n";
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> dc;
	
	for (int i = 0; i < dc; i++) {
		tempPoints.clear();
		cin >> sx >> sy >> sd >> g;
		dragonCurve(sy, sx, sd, g);
	}

	printPoints();
	FindSquere();

	cout << result;

}
