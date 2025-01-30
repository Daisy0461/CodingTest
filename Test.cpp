#include <bits/stdc++.h>

using namespace std;

int n, m;
int result = 987654321;
int room[10][10];
int dy[] = { -1, 0 ,1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> cctvPos;

vector<pair<int, int>>  watch(int cctvIndex, int dir)
{
	vector<pair<int, int>> changed;
	int ny = cctvPos[cctvIndex].first;		//첫 위치를 ny, nx에 저장
	int nx = cctvPos[cctvIndex].second;
	int cctvNum = room[ny][nx];		//어떤 종류의 CCTV인지 저장.

	//cout << "CCTV Y : " << ny << "  X :" << nx << "\n";			//위치는 잘 나오는데 왜 해당 arr에 들어 있는 값이 0이지?
	//cout << "cctv Num : " << cctvNum << "\n";

	if (cctvNum == 1) {
		ny = cctvPos[cctvIndex].first;		//위치를 CCTV위치로 초기화
		nx = cctvPos[cctvIndex].second;
		while (true) {
			ny = ny + dy[dir];
			nx = nx + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
			if (room[ny][nx] == 6) break;

			if (room[ny][nx] == 0) {			//이렇게 하지 않으면 CCTV가 0으로 바뀔 수가 있다.
				changed.push_back({ ny, nx });		//이 위치는 0에서 본 것으로 바뀐 위치이다.
				room[ny][nx] = 7;
			}
		}
	}
	else if (cctvNum == 2) {
		for (int i = 0; i <= 2; i += 2) {
			ny = cctvPos[cctvIndex].first;		//위치를 CCTV위치로 초기화
			nx = cctvPos[cctvIndex].second;
			while (true) {
				ny = ny + dy[(i + dir) % 4];
				nx = nx + dx[(i + dir) % 4];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
				if (room[ny][nx] == 6) break;

				if (room[ny][nx] == 0) {			//이렇게 하지 않으면 CCTV가 0으로 바뀔 수가 있다.
					changed.push_back({ ny, nx });		//이 위치는 0에서 본 것으로 바뀐 위치이다.
					room[ny][nx] = 7;
				}
			}
		}
	}
	else if (cctvNum == 3) {
		for (int i = 0; i < 2; i++) {
			ny = cctvPos[cctvIndex].first;		//위치를 CCTV위치로 초기화
			nx = cctvPos[cctvIndex].second;
			while (true) {
				ny = ny + dy[(i + dir) % 4];
				nx = nx + dx[(i + dir) % 4];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
				if (room[ny][nx] == 6) break;

				if (room[ny][nx] == 0) {			//이렇게 하지 않으면 CCTV가 0으로 바뀔 수가 있다.
					changed.push_back({ ny, nx });		//이 위치는 0에서 본 것으로 바뀐 위치이다.
					room[ny][nx] = 7;
				}
			}
		}
	}
	else if (cctvNum == 4) {
		for (int i = 0; i < 3; i++) {
			ny = cctvPos[cctvIndex].first;		//위치를 CCTV위치로 초기화
			nx = cctvPos[cctvIndex].second;
			while (true) {
				ny = ny + dy[(i + dir) % 4];
				nx = nx + dx[(i + dir) % 4];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
				if (room[ny][nx] == 6) break;

				if (room[ny][nx] == 0) {			//이렇게 하지 않으면 CCTV가 0으로 바뀔 수가 있다.
					changed.push_back({ ny, nx });		//이 위치는 0에서 본 것으로 바뀐 위치이다.
					room[ny][nx] = 7;
				}
			}
		}
	}
	else if (cctvNum == 5) {
		for (int i = 0; i < 4; i++) {
			ny = cctvPos[cctvIndex].first;		//위치를 CCTV위치로 초기화
			nx = cctvPos[cctvIndex].second;

			while (true) {
				ny = ny + dy[(i + dir) % 4];
				nx = nx + dx[(i + dir) % 4];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
				if (room[ny][nx] == 6) break;

				if (room[ny][nx] == 0) {			//이렇게 하지 않으면 CCTV가 0으로 바뀔 수가 있다.
					changed.push_back({ ny, nx });		//이 위치는 0에서 본 것으로 바뀐 위치이다.
					room[ny][nx] = 7;
				}
			}
		}
	}

	return changed;
}

void check(int checkCount)
{
	if (checkCount == cctvPos.size()) {
		int tempMiss = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (room[i][j] == 0) {
					tempMiss += 1;
				}
			}
		}
		//
		//cout << "\nTempMiss : " << tempMiss << "\n";
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		cout << room[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
		result = min(result, tempMiss);
		return;
	}

	for (int k = 0; k < 4; k++) {
		vector < pair<int, int>> changedPos = watch(checkCount, k);		//각 CCTV에 대해서 4방향 다 check함.
		check(checkCount + 1);			//다음 CCTV로 넘어가서 확인함.

		//cout << "Chnaged Pos : " << changedPos.size() << "\n";
		for (auto i : changedPos) {
			room[i.first][i.second] = 0;		//다시 보지 못한 것으로 원복
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			room[i][j] = temp;
			if (temp != 6 && temp != 0) {
				cctvPos.push_back({ i,j });
			}
		}
	}

	check(0);

	//cout << "result : ";
	cout << result;
}
