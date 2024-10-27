#include <bits/stdc++.h>

using namespace std;

//1-왼쪽, 2-위쪽, 4-오른쪽, 8-아래가 막혀있다는 의미임.
//i=0 왼쪽, 1- 위쪽, 2-오른쪽, 3-아래
//문제는 옆방?


int n, m;
int roomCount = 0, maxRoom = 0, maxSumRoom = 0, room=0;
int visited[51][51];
vector<vector<int>> castle(51);
vector<int> rooms;
int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };

void dfs(int y, int x) {
	room++;
	visited[y][x] = roomCount;

	//cout << "Start y : " << y << "  x: " << x  <<  "  castle Num : "<< castle[y][x] << "\n";
	for (int i = 0; i < 4; i++) {
		if (castle[y][x] & (1 << i)) continue;	//비트가 켜져있으면 막혀있다.
		//cout <<  "is not block i : " << i+1 << "\n";
		//안막혀있다면
		int ny = y + dy[i];
		int nx = x + dx[i];
		

		if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
		if (visited[ny][nx]) continue;
		//cout << "ny : " << ny << "  nx: " << nx << "\n";
		dfs(ny, nx);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int temp;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			castle[i].push_back(temp);
		}
	}

	rooms.push_back(0);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;
			room = 0;
			roomCount++;
			dfs(i, j);
			//cout << "End Room \n";
			rooms.push_back(room);
			maxRoom = max(maxRoom, room);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 1 < n) {		//i+1이 범위 안에 있어야 비교가 가능하다.
				if (visited[i][j] != visited[i + 1][j]) {	//ij와 i+j의 방의 넘버가 다르다.
					maxSumRoom = max(maxSumRoom,
						rooms[visited[i + 1][j]] + rooms[visited[i][j]]);
				}
			}

			if (j + 1 < m) {
				if (visited[i][j + 1] != visited[i][j]) {
					maxSumRoom = max(maxSumRoom,
						rooms[visited[i][j]] + rooms[visited[i][j + 1]]);
				}
			}
		}
	}

	//for (int i = 0; i < m; i++) {
	//	for (int j = 0; j < n; j++) {
	//		for (int k = 0; k < 4; k++) {
	//			if (castle[i][j] & (1 << k)) {		//방의 k쪽 벽이 있다.
	//				int ny = i + dy[i];
	//				int nx = j + dx[j];

	//				if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;

	//				if (visited[i][j] != visited[ny][nx]) {
	//					maxSumRoom = max(maxSumRoom, rooms[visited[i][j]] + rooms[visited[ny][nx]]);
	//				}
	//			}
	//		}
	//	}
	//}

	cout << roomCount << "\n" << maxRoom << "\n" << maxSumRoom;

}