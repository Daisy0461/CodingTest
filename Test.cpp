#include <bits/stdc++.h>

using namespace std;

int n, k, L, result = 0;
int gameMap[105][105];
int dy[] = { 0, 1, 0 ,-1 };
int dx[] = { 1, 0, -1, 0 };
vector<pair<int, char>> t;
deque<pair<int, int>> s;

int main()
{
	cin >> n >> k;

	int tempAY, tempAX;
	for (int i = 0; i < k; i++) {
		cin >> tempAY >> tempAX;
		gameMap[tempAY][tempAX] = 1;		//사과
	}

	cin >> L;
	int time; char dir;
	for (int i = 0; i < L; i++) {
		cin >> time >> dir;
		t.push_back({ time, dir });
	}

	sort(t.begin(), t.end());

	int di = 0, ti = 0;
	int ny = 1, nx = 1;
	while (1) {
		if (s.empty()) {
			s.push_back({ ny, nx });
			gameMap[ny][nx] = 2;
			continue;
		}

		if (ti < L && t[ti].first == result) {	//turn할 시간
			//cout << "change dir\n";
			if (t[ti].second == 'D') {
				di = (di + 1) % 4;
			}
			else {
				di = (di - 1 + 4) % 4;
			}
			ti += 1;
		}

		ny += dy[di];
		nx += dx[di];
		//cout << "ny : " << ny << " nx : " << nx << "\n";
		if (ny < 1 || nx < 1 || ny >= n + 1 || nx >= n + 1) {
			result++; break;
		}
		if (gameMap[ny][nx] == 2) {
			result++; break;
		}

		if (gameMap[ny][nx] == 1) {		//다음칸이 사과라면 꼬리 줄어들지 않는다.
			s.push_back({ ny, nx });
			gameMap[ny][nx] = 2;
		}
		else {		//아무것도 없는 칸이면 꼬리 줄어들고 머리 나간다.
			gameMap[s.front().first][s.front().second] = 0;
			s.pop_front();
			s.push_back({ ny, nx });
			gameMap[ny][nx] = 2;
		}

		result += 1;
	}

	cout << result;
}
