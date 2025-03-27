#include <bits/stdc++.h>

using namespace std;

struct HomeStruct
{
	int r=0; int g=0; int b=0;
};

//주변 집(-1, + 1)의 색과 같지 않아야한다.
int n;
HomeStruct arr[1010];
int dp[1010][3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	int r, g, b;
	for (int i = 1; i <= n; i++) {
		cin >> r >> g >> b;
		arr[i].r = r;
		arr[i].g = g;
		arr[i].b = b;

		//첫 색깔을 칠했을 때의 최소값.
		dp[i][0] = min(dp[i - 1][1] + r, dp[i - 1][2] + r);
		dp[i][1] = min(dp[i - 1][0] + g, dp[i - 1][2] + g);
		dp[i][2] = min(dp[i - 1][0] + b, dp[i - 1][1] + b);
	}

	int result=1e9;
	for (int i = 0; i < 3; i++) {
		result = min(result, dp[n][i]);
	}

	cout << result;
}
