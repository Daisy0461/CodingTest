#include <bits/stdc++.h>

using namespace std;

//1-����, 2-����, 4-������, 8-�Ʒ��� �����ִٴ� �ǹ���.
//i=0 ����, 1- ����, 2-������, 3-�Ʒ�
//������ ����?


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
		if (castle[y][x] & (1 << i)) continue;	//��Ʈ�� ���������� �����ִ�.
		//cout <<  "is not block i : " << i+1 << "\n";
		//�ȸ����ִٸ�
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
			if (i + 1 < n) {		//i+1�� ���� �ȿ� �־�� �񱳰� �����ϴ�.
				if (visited[i][j] != visited[i + 1][j]) {	//ij�� i+j�� ���� �ѹ��� �ٸ���.
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
	//			if (castle[i][j] & (1 << k)) {		//���� k�� ���� �ִ�.
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