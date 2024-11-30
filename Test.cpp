#include <bits/stdc++.h>

using namespace std;

//순서
//1. 낚시왕 이동
//2.낚시왕의 열의 상어 중에서 땅과 가장 가까운 상어를 잡는다. -> 간단하게 해당 열에서 y값이 가장 작은 것이다.
//3. 상어 이동

int r, c, s;
int sr, sc, ss, sd, sz;		//sr, sc = 위치, ss는 상어의 속도, sd는 상어의 방향, sz는 상어의 사이즈 -> 사이즈는 같은 칸 상어가 여러 마리 존재할 때 큰 애가 다 먹는다. 같은 크기의 상어는 없다.
//dd 1 = 위, 2 = 아래, 3 = 오른, 4 = 왼 끝 부분에 닿으면 뒤돌아서 감 -> 방향이 바뀜.
int sizeResult = 0;		//잡은 상어의 크기 합 출력

vector<pair<int, int>> sharkPos;
vector<pair<int, int>> moveSucceedShark;
tuple<int, int, int> init = make_tuple(0, 0, 0);		//속도(이동 크기), 방향, 사이즈
tuple<int, int, int> arr[105][105];
tuple<int, int, int> sharkMove_arr[105][105];

void printArr()
{
	cout << "Arr\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << get<2>(arr[i][j]);
		}
		cout << "\n";
	}
}

void printSharkMove()
{
	cout << "SharkMove Arr\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << get<2>(sharkMove_arr[i][j]);
		}
		cout << "\n";
	}
}

void CatchShark(int x) {
	//cout << "x : " << x;
	for (int i = 0; i < r; i++) {
		if (get<2>(arr[i][x]) != 0) {
			//cout <<"  catchSize : " << get<2>(arr[i][x]) << '\n';
			sizeResult += get<2>(arr[i][x]);
			arr[i][x] = init;
			return;
		}
	}
	//cout << "  not Catch\n";
}
void SharkMove()		//이게 뭔가 잘못된듯...
{
	for (int i = 0; i < sharkPos.size(); i++) {
		auto nowShark = arr[sharkPos[i].first][sharkPos[i].second];		//지금 상어에 대한 정보를 넣음.
		int nowSpeed = get<0>(nowShark);
		int nowDir = get<1>(nowShark);
		int nowSize = get<2>(nowShark);
		if (nowSize == 0) continue;
		int ny = sharkPos[i].first, nx = sharkPos[i].second;
		//cout << "now Shark : " << nowSize << "   now y : " << ny << "  x: " << nx;

		if ((nowDir == 1 || nowDir == 2) && nowSpeed != 0) {		//1 = 위로 간다 2 = 아래로 간다.
			int cycleCount  = nowSpeed / (2* (r-1));		//왕복해서 제자리로 돌아온다.
			int moveCount = nowSpeed - (cycleCount * (2 * (r - 1)));
			//cout << "  moveCount : " << moveCount << "\n";
			while (moveCount) {
				if (nowDir == 1) {
					ny -= 1;
					if (ny < 0) {
						ny = 1;
						nowDir = 2;
					}
				}
				else {
					ny += 1;
					if (ny > (r - 1)) {
						ny = r - 2;
						nowDir = 1;
					}
				}
				moveCount -= 1;
			}
		}
		else if ((nowDir == 3 || nowDir == 4) && nowSpeed != 0) {		//3 = 오른쪽, 4 = 왼쪽
			int cycleCount = nowSpeed / (2 * (c - 1));		//이것도 왕복해서 제자리로 돌아온다. -> 즉 전체 nowSpeed에서  
			int moveCount = nowSpeed - (cycleCount * (2 * (c - 1)));
			//cout << "  moveCount : " << moveCount << "\n";

			while (moveCount) {
				if (nowDir == 3) {
					nx += 1;
					if (nx > (c - 1)) {
						nx = c - 2;
						nowDir = 4;
					}
				}
				else {
					nx -= 1;
					if (nx < 0) {
						nx = 1;
						nowDir = 3;
					}
				}
				moveCount -= 1;
			}

		}

		//상어가 겹치는지 확인해야한다.
		if (sharkMove_arr[ny][nx] != init) {
			int arrSharkSize = get<2>(sharkMove_arr[ny][nx]);
			if (arrSharkSize < nowSize) {		//지금 상어가 원래 있던 상어보다 크다.
				sharkMove_arr[ny][nx] = { nowSpeed, nowDir, nowSize };		//지금 상어로 대체 -> nowDir이 바뀌니까 이렇게 넣음.
			}
		}
		else {		//겹치지 않는다.
			sharkMove_arr[ny][nx] = { nowSpeed, nowDir, nowSize };
		}

		//cout << "AfterMove   Pos y : " << ny << "  x : " << nx << "\n";
	}
}
void arrSetting()
{
	fill(&arr[0][0], &arr[0][0] + 105 * 105, init);
	sharkPos.clear();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sharkMove_arr[i][j] != init) {
				sharkPos.push_back({ i, j });		//이동을 마진 shark가 i, j에 있다.
				arr[i][j] = sharkMove_arr[i][j];
			}
		}
	}
	fill(&sharkMove_arr[0][0], &sharkMove_arr[0][0] + 105 * 105, init);

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	
	fill(&arr[0][0], &arr[0][0] + 105 * 105, init);
	fill(&sharkMove_arr[0][0], &sharkMove_arr[0][0] + 105 * 105, init);

	cin >> r >> c >> s;

	if (s == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < s; i++) {
		cin >> sr >> sc >> ss >> sd >> sz;
		tuple<int, int, int> shark = { ss, sd, sz };
		arr[sr-1][sc-1] = shark;		//1, 1부터 시작해서 -1씩 해줬다.
		sharkPos.push_back({ sr - 1, sc - 1 });
	}

	for (int i = 0; i < c; i++) {
		//낚시장 출력
		//printArr();
		//낚시왕 이동 & 낚시
		CatchShark(i);
		//상어 이동
		SharkMove();
		//printSharkMove();
		//그 후 arr에 집어넣고 sharMove_arr 초기화.
		arrSetting();
	}

	cout << sizeResult;
}
