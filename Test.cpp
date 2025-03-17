#include <bits/stdc++.h>

using namespace std;

int n, num;
int result = 0;
int dp[1500010];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	int day, pay;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cin >> day >> pay;

		cur = max(cur, dp[i]);			//이전에 있던 dp값들과 현재 dp값 중 가장 높은 값을 cur에 넣는다.

		if (i + day > n) continue;

		dp[i + day] = max(dp[i + day], cur + pay);			//원래 i+day에 있던 dp와 기존dp 중 가장 높은 값 + pay와 비교한다.
		result = max(result, dp[i + day]);
	}

	cout << result;
}

