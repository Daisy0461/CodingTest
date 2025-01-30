#include <bits/stdc++.h>

using namespace std;

int n, m, turnCount;						//n = 원판의 개수, m = 각 원판에 적힌 수의 개수, t = 회전횟수
vector<deque<int>> circles(55);
int dy[] = { -1, 0, 1, 0 };		//위 오 아 왼
int dx[] = { 0, 1, 0, -1 };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> turnCount;

	//원판에 숫자 적기
	int temp;
	for (int i = 1; i <= n; i++) {			//a배수의 원판을 돌려야해서 i는 1부터 시작하는게 낫다는 생각.
		for (int j = 0; j < m; j++) {
			cin >> temp;
			circles[i].push_back(temp);
		}
	}

	int a, dir, c;			//a배수의 원판을 다 돌린다. dir방향 0 : 배열을 <-방향 / 1 : 배열을 -> 방향으로 민다.  c = 몇 칸을 미는가?

	for (int g = 0; g < turnCount; g++) {
		cin >> a >> dir >> c;
		//a배수의 원판을 돌리는 작업.
		for (int k = a; k <= n; k += a) {		//a의 배수 원판을 다 돌려야하니까 이렇게 작성하면 a=2라면 2와 4의 원판을 돌리게 된다.
			int t;
			if (dir == 0) {		//뒤에 있는 것이  앞으로 온다.
				for (int j = 0; j < c; j++) {		//c칸만큼 옮기는 과정
					t = circles[k].back();			//뒷 숫자를 t에 저장하고 back을 없앤 뒤 front에 저장.
					circles[k].pop_back();
					circles[k].push_front(t);
				}
			}
			else {				//앞에 있는 것이 뒤로 간다.
				for (int j = 0; j < c; j++) {
					t = circles[k].front();
					circles[k].pop_front();
					circles[k].push_back(t);
				}
			}
		}
		//dq에 있는 것을 vector로 옮김.
		vector<vector<int>> tempCircle(55);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				int pushNum = circles[i].front();
				circles[i].pop_front();
				tempCircle[i].push_back(pushNum);
			}
		}

		//cout << "\nTruned circle\n";		//돌린 원판 출력
		//for (int i = 1; i <= n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		cout << tempCircle[i][j] << " ";
		//	}
		//	cout << "\n";
		//}

		int removeCircle[55][55];
		fill(&removeCircle[0][0], &removeCircle[0][0] + 55 * 55, 0);
		bool bIsFindSame = false;
		float sum = 0;
		int devideCount = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (tempCircle[i][j] == 0) continue;		//0이면 이미 삭제된 것이기에 필요 없다.
				sum += tempCircle[i][j];
				devideCount += 1;

				for (int d = 0; d < 4; d++) {		//4방향에 대해서 찾는다.
					int ny = i + dy[d];
					int nx = (j + dx[d]) % m;

					if (ny <= 0 || nx < 0 || ny >= n + 1 || nx >= m) continue;		//범위를 벗어나면 다시 돌려라. -> 여기가 문제임 m에 대해선 다르게 해야함.
					if (tempCircle[i][j] == tempCircle[ny][nx]) {		//4방향을 돌리다가 같은 것을 만났다.
						removeCircle[i][j] = 1;		//removeCircle을 1로 활성화한다.
						removeCircle[ny][nx] = 1;
						bIsFindSame = true;
					}
				}
			}
		}

		if (!bIsFindSame) {		//같은 것이 아무것도 없었다면
			//cout << "\n Cann't Find Same \n";
			float avg = sum / devideCount;
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < m; j++) {
					if (tempCircle[i][j] == 0) continue;		//0은 무시
					if (tempCircle[i][j] < avg) tempCircle[i][j] += 1;				//평균보다 크면 -1 작으면 +1
					else if (tempCircle[i][j] > avg) tempCircle[i][j] -= 1;
				}
			}
		}
		else {		//같은 것이 있었다.
			//cout << "\nremove Circle \n";
			//for (int i = 1; i <= n; i++) {
			//	for (int j = 0; j < m; j++) {
			//		cout << removeCircle[i][j] << " ";
			//	}
			//	cout << "\n";
			//}
			//cout << "\n";

			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < m; j++) {
					if (removeCircle[i][j] == 1) {
						tempCircle[i][j] = 0;
					}
				}
			}
		}

		//if (bIsFindSame) cout << "After remove Cirlce\n";		//삭제 후 원판 출력
		//else cout << "After add Circle\n";
		//for (int i = 1; i <= n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		cout << tempCircle[i][j] << " ";
		//	}
		//	cout << "\n";
		//}

		//dq push
		for (int i = 0; i < circles.size(); i++) {
			circles[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				circles[i].push_back(tempCircle[i][j]);
			}
		}

		//cout << "End dq Push\n\n";
	}

	//원판에 있는 모든 숫자 더해야함.
	int result=0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int tempNum = circles[i].front();
			circles[i].pop_front();
			result += tempNum;
		}
	}

	//cout << "\nresult : ";
	cout << result;
}
