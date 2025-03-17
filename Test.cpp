#include <bits/stdc++.h>

using namespace std;

int n;		//1<=n <= 1000
int result = 0;
int arr[1010];
int dp[1010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j] && dp[i] <= dp[j]) {		//현재 숫자보다 j가 크면서 쌓인게 더 크다면
				dp[i] = dp[j] + 1;
			}
		}

		result = max(result, dp[i]);
	}
	
	cout << result;
}
