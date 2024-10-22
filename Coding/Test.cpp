#include <bits/stdc++.h>

using namespace std;

int n, minResult = 987654321;		//인구수
int tempIndex, tempSum;
int visited[20];
vector<int> pops;
vector<vector<int>> links(20);
vector<int> Sums;

void FindLinks(int vilage, int bit)
{
	visited[vilage] = 1;
	tempSum += pops[vilage];

	for (int i : links[vilage]) {
		if (visited[i]) continue;

		if ((tempIndex & (1 << (i - 1))) == bit) {		//현재 bit와 동일하다면
			FindLinks(i, bit);
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	pops.push_back(0);		//마을이 1부터 시작해서 처음에 push_back함.
	int pop = 0;
	for (int i = 1; i <= n; i++) {				//1번마을부터 인구수를 입력받는다.
		cin >> pop;
		pops.push_back(pop);
	}
	int in;
	int link;
	for (int i = 1; i <= n; i++) {
		cin >> in;
		for (int j = 0; j < in; j++) {
			cin >> link;
			links[i].push_back(link);			//i마을이 link로 들어온 마을과 연결되어있다.
		}
	}

	for (int i = 1; i < (1 << n) - 1; i++) {
		cout << "i : " << i << "   ";
		fill(&visited[0], &visited[0] + 20, 0);
		Sums.clear();
		tempIndex = i;
		tempSum = 0;

		for (int j = 0; j < n; j++) {		//비트 체크는 0번부터한다이
			if (visited[j + 1]) continue;		//j+1마을을 들렸다면 

			if (i & (1 << j)) {
				FindLinks(j + 1, 1);
				Sums.push_back(tempSum);
			}
			else {
				FindLinks(j + 1, 0);
				Sums.push_back(tempSum);
			}
		}

		if (Sums.size() == 2) {
			cout << "minResult : " << abs(Sums[0] - Sums[1]);
			minResult = min(minResult, abs(Sums[0] - Sums[1]));
		}
		cout << "\n";
	}

	cout << minResult;
}