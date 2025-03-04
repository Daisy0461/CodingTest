#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;
int dp[1000010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	fill(&dp[0], &dp[0] + 1000010, 0);

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		int di3 = 1e9, di2 = 1e9, sub = 1e9;

		if (i % 3 == 0) {
			di3 = dp[i / 3] + 1;
		}
		if (i % 2 == 0) {
			di2 = dp[i / 2] + 1;
		}

		sub = dp[i - 1] + 1;

		int t = min(di3, di2);
		t = min(t, sub);
		dp[i] = t;
	}

	cout << dp[n];
}
