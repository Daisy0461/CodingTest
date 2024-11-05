#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;		//N개의 보석 k개의 가방
ll result = 0;
vector<int> vv;
vector<pair<int, int>> vp;
priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	int m, v;		//무게와 가격
	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		vp.push_back({ m, v });		
	}

	int c;
	for (int i = 0; i < k; i++) {
		cin >> c;
		vv.push_back(c);
	}

	sort(vp.begin(), vp.end());			//보석의 무게가  가벼운 순 그리고 가격이 싼 순
	sort(vv.begin(), vv.end());			//가방을 담을 수 있는 무게가 작은 순으로 정렬한다.

	int vpIndex = 0;
	for (auto i : vv) {
		while (vpIndex < n && i >= vp[vpIndex].first) {
			pq.push(vp[vpIndex].second);
			vpIndex++;
		}

		if (pq.size()) {
			result += pq.top();
			pq.pop();
		}
	}

	cout << result;

}