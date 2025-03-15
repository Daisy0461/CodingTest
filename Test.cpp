#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;		//1<=n<=1500000
pair<int, int> p[1500010];		//걸리는 날짜, 받는 돈
int dp[1500010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	int result = 0;
	int cur = 0;
	int day, cost;
	for (int i = 0; i < n; i++) {
		cin >> day >> cost;
		
		cur = max(cur, dp[i]);		//이전의 dp[i]의 값들과 현재 dp[i]의 값과 비교한다.

		if (i + day < n) {
			dp[i + day] = max(dp[i + day], cur + cost);			//이전에 언젠가 dp에 넣었던 값 vs 이전 dp들 중 최대값 + 받을 돈이냐
			result = max(result, dp[i + day]);
		}
	}
	cout << result;
}
