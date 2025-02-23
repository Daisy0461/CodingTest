#include <bits/stdc++.h>

using namespace std;

int n, s, e;
vector<pair<int, int>> vp;
int arr[105];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;		//총 전기줄의 개수
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		vp.push_back({ s, e });
	}

	sort(vp.begin(), vp.end());

	fill(&arr[0], &arr[0] + 105, 0);

	int len = 0;
	for (int i = 0; i < vp.size(); i++) {
		int t = vp[i].second;
		auto lowerPos = lower_bound(arr, arr + len, t);
		if(*lowerPos == 0) len++;
		*lowerPos = t;
	}

	cout << n - len;
}
