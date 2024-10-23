#include <bits/stdc++.h>

using namespace std;

int n, l, result = 0;		//l은 경사로의 가로 길이, 경사로의 높이는 항상 1
vector<vector<int>> v(101);
vector<vector<int>> vr(101);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> l;

	int height;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> height;
			v[i].push_back(height);
			vr[j].push_back(height);
		}
	}

	//cout << "Reverse Print\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j : vr[i]) {
	//		cout << j << " ";
	//	}
	//	cout << "\n";
	//}

	for (int i = 0; i < n; i++) {
		int sameCount = 0;
		int beforeHeight = 0;		//0이면 처음이다. L이 1부터 시작이기에
		int j = 0;
		//cout << "i : " << i;
		for (j = 0; j < n; j++) {
			int currentHeight = v[i][j];

			if (beforeHeight == 0) {		//처음 넣어주기
				sameCount++;
				beforeHeight = currentHeight;
				continue;
			}

			if (beforeHeight == v[i][j]) {		//현재 높이와 같다면

				sameCount++;
			}
			else {		//beforeHeight != j
				int subResult = beforeHeight - currentHeight;
				if (abs(subResult) > 1) break;	//차이가 1보다 크면 이미 경사로 못 놓음.
					

				if (subResult == -1) {		//즉 지금 높이가 이전보다 1 높다.
					if (sameCount < l) break;	//sameCount가 경사로의 가로보다 작으면 경사로 못 놓음.
					sameCount = 1;
					beforeHeight = currentHeight;
				}
				else if (subResult == 1) {		//지금 높이가 이전보다 1낮다.
					if (j + l - 1 >= n) {	//n보다 크면 못놓는다. 넘어간다.
						j = n + 1;
						continue;
					}

					bool can = true;
					for (int k = 1; k <= l - 1; k++) {
						if (v[i][j + k] == currentHeight) {
							continue;
						}
						else {
							can = false;
						}
					}

					if (!can) break;

					j = j + l - 1;
					sameCount = 0;			//초기로 돌린다.
					beforeHeight = currentHeight;
				}
			}
		}

		if (j == n) {
			//cout << " is result ++ \n";
			result++;
		}
		else {
			//cout << "\n";
		}
	}

	//cout << "Reverse \n";
	for (int i = 0; i < n; i++) {
		//cout << "i : " << i;
		int sameCount = 0;
		int beforeHeight = 0;		//0이면 처음이다. L이 1부터 시작이기에
		int j = 0;
		for (j = 0; j < n; j++) {
			int currentHeight = vr[i][j];

			if (beforeHeight == 0) {		//처음 넣어주기
				sameCount++;
				beforeHeight = currentHeight;
				continue;
			}

			if (beforeHeight == vr[i][j]) {		//현재 높이와 같다면
				sameCount++;
			}
			else {		//beforeHeight != j
				int subResult = beforeHeight - currentHeight;
				if (abs(subResult) > 1) break;	//차이가 1보다 크면 이미 경사로 못 놓음.


				if (subResult == -1) {		//즉 지금 높이가 이전보다 1 높다.
					if (sameCount < l) break;	//sameCount가 경사로의 가로보다 작으면 경사로 못 놓음.
					sameCount = 1;
					beforeHeight = currentHeight;
				}
				else if (subResult == 1) {		//지금 높이가 이전보다 1낮다.
					if (j + l - 1 >= n) break;		//n보다 크면 못놓는다. 넘어간다.

					bool can = true;
					for (int k = 1; k <= l - 1; k++) {
						if (vr[i][j + k] == currentHeight) {
							continue;
						}
						else {
							can = false;
						}
					}

					if (!can) break;

					j = j + l - 1;
					sameCount = 0;			//초기로 돌린다.
					beforeHeight = currentHeight;
				}
			}
		}

		if (j == n) {
			//cout << " is result ++ \n";
			result++;
		}
		else {
			//cout << "\n";
		}
	}

	cout << result;


}