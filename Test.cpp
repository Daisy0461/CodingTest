#include <bits/stdc++.h>

using namespace std;

int n;

//현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.
// = arr로 봤을 땐 i or i+1 이다.
int arr[510][510];
int dp[510][510];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];

	for (int i = 1; i <= n-1; i++) {		//층을 나타낸다. (위에서 부터)
		for (int j = 1; j <= i; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + arr[i + 1][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + arr[i + 1][j + 1]);
		}
	}


	int result = -1e9;
	for (int i = 1; i <= n; i++) {
		result = max(result, dp[n][i]);
	}

	cout << result;

}
