#include <bits/stdc++.h>

using namespace std;

int n, minResult = 987654321;
int tempIndex, tempSum;
int visited[20];
vector<int> populars;
vector<int> Sums;
vector<vector<int>> Links(20);

void FindLink(int vilage, bool isOn)
{
	visited[vilage] = 1;
	tempSum += populars[vilage];

	for (int i : Links[vilage]) {
		//cout << "In i:  " << i << "\n";
		if (visited[i]) continue;

		//if((temp & (1<<i)) == 1)로 하면 안되네.. 이게 1이 아니라 2든 4든 8이든 될 수가 있어서 안됐구나

		if (isOn && (tempIndex & (1 << i))) {
			//cout << "On Find Link Vilage : " << i << "\n";
			FindLink(i, isOn);
		}
		else if (!isOn && !(tempIndex & (1 << i))) {
			//cout << "Off Find Link Vilage : " << i << "\n";
			FindLink(i, isOn);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	int pop;
	for (int i = 0; i < n; i++) {				//인구 수 입력
		cin >> pop;
		populars.push_back(pop);
	}

	int linkNum;
	for (int i = 0; i < n; i++) {						//link확인 & 잘들어가는 것 확인 완료
		cin >> linkNum;
		int link;
		for (int j = 0; j < linkNum; j++) {
			cin >> link;
			Links[i].push_back(link - 1);			//link - 1을 해줘야한다. 만약 link가 1이면 0번째 비트와 비교해서 계산할 것이기 때문이다.
		}
	}

	for (int i = 1; i < ((1 << n) - 1); i++) {
		fill(&visited[0], &visited[0] + 20, 0);
		Sums.clear();
		tempIndex = i; tempSum = 0;
		//cout << "i : " << tempIndex << "\n";
		
		for (int j = 0; j < n; j++) {
			if (visited[j]) continue;

			tempSum = 0;
			if ((tempIndex & (1 << j)) == 0) {		//비트가 꺼져있다면
				//cout << "Bit Off Start Vilage : " << j << "\n";
				FindLink(j, false);
				Sums.push_back(tempSum);
			}
			else {
				//cout << "Bit On Start Vilage : " << j << "\n";
				FindLink(j, true);
				Sums.push_back(tempSum);
			}
		}

		if (Sums.size() == 2) {
			int tempSumsResult = abs(Sums[0] - Sums[1]);
			//cout << "Sums[0] : " << Sums[0] << "  Sums[1] : " << Sums[1] << "\n";
			//cout << "Sum Sub Result : " << tempSumsResult;
		
			minResult = min(minResult, tempSumsResult);
		}
		else {
			//cout << "Sums Size : " << Sums.size();
		}
		//cout << "\n";
	}

	if (minResult == 987654321) {
		cout << -1;
	}else{
		cout << minResult;
	}
}