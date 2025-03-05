#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;		//2xn 크기의 타일이 주어진다. 1<= n < = 1000
ll dp[1010];

ll go(int num)
{
	if (num == 1) return 1;
	if (num == 2) return 2;

	ll & ret = dp[num];
	if (ret != 0) return ret;

	return ret = (go(num - 1) + go(num - 2) ) % 10007;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	//dp[1] = 1;
	//dp[2] = 2;

	//for (int i = 3; i <= n; i++) {
	//	dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	//}

	cout << go(n);
}
