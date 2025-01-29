#include <bits/stdc++.h>

using namespace std;

int n, result = -987654321;
int arr_input[21][21];		//처음 들어오는 Input

deque<int> dq;

void play(int playCount, int inputArray[21][21])
{
	if (playCount == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				result = max(inputArray[i][j], result);
			}
		}
		return;
	}

	for (int k = 0; k < 4; k++) {
		int tempArray[21][21];
		fill(&tempArray[0][0], &tempArray[0][0] + 21 * 21, 0);
		for (int i = 0; i < n; i++) {
			dq.push_back(0);
			for (int j = 0; j < n; j++) {
				//if (inputArray[i][j] == 0) continue;
				int back = dq.back();
				if (inputArray[i][j] == back) {
					dq.pop_back();
					dq.push_back(back * 2);
				  dq.push_back(0);
				}
				else {
					dq.push_back(inputArray[i][j]);
				}
			}
			//가로 한 줄이 끝났다.
			int pushIndex = 0;
			while (dq.size()) {
				if (dq.front() == 0) {		//0은 무시한다.
					dq.pop_front();
				}
				else {
					tempArray[i][pushIndex] = dq.front();
					dq.pop_front();
					pushIndex++;
				}
			}
		}
		//arr_temp가 2024게임의 왼쪽으로 shift한 모양이 된다.
		play(playCount + 1, tempArray);

		int arr_rotate[21][21];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr_rotate[i][j] = inputArray[n-j-1][i];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				inputArray[i][j] = arr_rotate[i][j];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	//초기 상태 입력
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			arr_input[i][j] = temp;
		}
	}

	play(0, arr_input);

	cout << result;
}
