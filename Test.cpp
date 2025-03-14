#include <bits/stdc++.h>

using namespace std;

int n, num, len = 0;
int nums[1005];
pair<int, int>	tempMax;		// 지금까지의 최대 stack, 
int dp[1005];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;

		for (int j = 0; j <= i; j++) {
			if (nums[i] < nums[j] && dp[i] <= dp[j]) {		//현재 숫자가 이전의 숫자보다 작다. & 
				dp[i] = dp[j] + 1;
			}
		}
	}

	int result = 1;
	for (int i = 0; i < n; i++) {
		result = max(dp[i], result);
	}

	cout << result;
}