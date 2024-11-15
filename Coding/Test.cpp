#include <bits/stdc++.h>

using namespace std;

int n; int maxResult = 0;
deque<int> dq;
int arr[21][21];

void playGame(int playCount, int inputArray[21][21]) {

	//cout << "play Count : " << playCount << "\n";
	if (playCount == 5) {
		int  tempMax = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (inputArray[i][j] > tempMax) {
					tempMax = inputArray[i][j];
				}
			}
		}

		maxResult = max(maxResult, tempMax);

		return;
	}

	for (int h = 0; h < 4; h++) {

		int tempArray[21][21];
		fill(&tempArray[0][0], &tempArray[0][0] + 21 * 21, 0);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (inputArray[i][j] == 0) continue;		//�������� ������ 2,0,2�� ��쿡 ������ �����. 
				if (!dq.size() || dq.back() != inputArray[i][j]) {
					dq.push_back(inputArray[i][j]);
				}
				else if (dq.back() == inputArray[i][j]) {
					int temp = dq.back();
					dq.pop_back();
					dq.push_back(temp * 2);
					dq.push_back(0);			//�̰��� �ϴ� ������ ���� temp�� 2���� 4�� ��������µ� �� ���� ���ڰ� 4��� �������� ������ �� ���� �����ϱ� ���ؼ��̴�. 
				}
			}

			int arrayIndex = 0;
			while (dq.size()) {
				if (dq.front() == 0) {
					dq.pop_front();
					continue;
				}
				tempArray[i][arrayIndex] = dq.front();
				dq.pop_front();
				arrayIndex++;
			 }

		}

		playGame(playCount + 1, tempArray);

		int turnArray[21][21];
		for (int i = 0; i < n; i++)	{
			for (int j = 0; j < n; j++) {
				turnArray[j][n - 1 - i] = inputArray[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				inputArray[i][j] = turnArray[i][j];
			}
		}

	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	//�ʱ� arr�Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	playGame(0, arr);

	cout << maxResult;
	
}