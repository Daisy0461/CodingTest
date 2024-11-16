#include <bits/stdc++.h>

using namespace std;

int minResult = 987654321;
int n;
vector<vector<int>> v(21);
vector<int> oneTeam, zeroTeam;


int main()
{ 
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
 
	int half = n / 2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			v[i].push_back(temp);
		}
	}

	for (int i = 1; i < (1 << n); i++) {
		int sumOneTeam = 0, sumZeroTeam = 0;
		oneTeam.clear(); zeroTeam.clear();		//팀 초기화

		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) { //i라는 숫자의 j번째 비트가 켜져있다.
				oneTeam.push_back(j);
			}
			else {
				zeroTeam.push_back(j);
			}
		}

		//cout << "here i :" << i << "\n";

		//cout << "One Team \n";
		//for (int j : oneTeam) {
		//	cout << j << " ";
		//}
		//cout << "\nZero Team \n";
		//for (int j : zeroTeam) {
		//	cout << j << " ";
		//}
		//cout << "\n";


		if (oneTeam.size() == half) {		//팀 수가 맞춰졌다.
			//cout << "one Team \n";
			for (int j = 0; j < oneTeam.size(); j++) {
				for (int t = 0; t < oneTeam.size(); t++) {
					//cout << "oneTeam[j] :" << oneTeam[j] << " oneTeam[t] : " << oneTeam[t] << "\n";
					sumOneTeam += v[oneTeam[j]][oneTeam[t]];
					//cout << "now sumOne : " << sumOneTeam << "\n";
				}
			}

			//cout << "zero Team \n";
			for (int j = 0; j < zeroTeam.size(); j++) {
				for (int t = 0; t < zeroTeam.size(); t++) {
					//cout << "j :" << j << " t : " << t << "\n";
					sumZeroTeam += v[zeroTeam[j]][zeroTeam[t]];
					//cout << "now sumZero : " << sumZeroTeam << "\n";
				}
			}

			minResult = min(minResult, abs(sumZeroTeam - sumOneTeam));
		}

		if (minResult == 0) {
			break;
		}
	}

	cout << minResult;
}
