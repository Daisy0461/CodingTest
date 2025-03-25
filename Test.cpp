#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> arr[510];
int dp[510][510];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int len = 1; len < n; len++) {
		for (int start = 1; start + len <= n; start++) {
			int end = len + start;
			dp[start][end] = INT_MAX;
			for (int mid = start; mid < end; mid++) {
				int cost = dp[start][mid] + dp[mid + 1][end] + (arr[start].first * arr[mid].second * arr[end].second);
				dp[start][end] = min(dp[start][end], cost);
			}
		}
	}

	cout << dp[1][n] << "\n";
}
