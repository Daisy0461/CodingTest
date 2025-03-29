#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//길이가 n인 계단수 ->  n=2인 경우 10,12,21,23,32,34,43,45,54,56 // 65,67,78,76,87,89,98 // 1의 경우 1,2,3,4,5,6,7,8,9 이런 느낌 ㅇㅇ

int n;
int divNum = 1e9;
int dp[110][10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j - 1 >= 0) dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % divNum;
			if (j + 1 <= 9) dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % divNum;
		}
	}

	ll result = 0;
	for (int i = 0; i <= 9; i++) {
		result = (result + dp[n][i]) % divNum;
	}

	cout << result;
}
