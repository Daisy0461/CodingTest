#include <bits/stdc++.h>

using namespace std;

//동일하게 극이 다르면 회전방향의 반대방향으로 회전한다.
//rotate <- / rrotate ->

int t, k;		//톱니바퀴는 1번부터 순서가 매겨진다. k번 회전한다.
int result = 0;
vector<vector<int>> toms(1005);
int visited[1005];

void turn(int tomNum, int dir)
{
	//cout << tomNum << "is turning\n";
	visited[tomNum] = 1;

	if (tomNum + 1 < t && !visited[tomNum + 1]) {		//tomNum + 1이 범위를 벗어나지 않으면서 방문하지 않은 톱니라면
		//현재 톱니와 오른쪽의 톱니와 비교해야한다.
		if (toms[tomNum][2] != toms[tomNum + 1][6]) {		//현재 톱니의 오른쪽과 오른쪽 톱니의 왼쪾이 동일하지 않으면 돌린다.
			turn(tomNum + 1, dir * -1);
		}
	}

	if (tomNum - 1 >= 0 && !visited[tomNum - 1]) {		//tomNum - 1이 범위를 벗어나지 않으면서 방문하지 않는 톱니라면
		if (toms[tomNum][6] != toms[tomNum - 1][2]) {		//현재 톱니의 오른쪽과 오른쪽 톱니의 왼쪾이 동일하지 않으면 돌린다.
			turn(tomNum - 1, dir * -1);
		}
	}

	//현재 톱니 돌리기
	if (dir == 1) {		//시계 방향 rrot
		rotate(toms[tomNum].rbegin(), toms[tomNum].rbegin() + 1, toms[tomNum].rend());
	}
	else {
		rotate(toms[tomNum].begin(), toms[tomNum].begin() + 1, toms[tomNum].end());
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;

	char tempTom;
	//12시가 [i][7]에 들어간다. 시계방향으로 1씩 줄어드는 입력이다.
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> tempTom;
			toms[i].push_back(tempTom - '0');
		}
	}

	cin >> k;

	int tom, dir;
	for (int i = 0; i < k; i++) {
		fill(&visited[0], &visited[0] + 1005, 0);

		cin >> tom >> dir;		//어느 톱니를 돌리는 것인지 
		turn(tom - 1, dir);

		/*cout << k << "turn result\n";
		for (int i = 0; i < t; i++) {
			for (int j : toms[i]) {
				cout << j;
			}
			cout << "\n";
		}*/
	}

	for (int i = 0; i < t; i++) {
		result += toms[i][0];
	}

	cout << result;

}