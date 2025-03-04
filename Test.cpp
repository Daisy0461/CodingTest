#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;
int dp[1000010];

int go(int num)
{
	//cout << "now num : " << num << "\n";
	if (num == 1) return 0;
	if (dp[num] != 0) return dp[num];

	int di3 = 1e9, di2 = 1e9;
	if (num % 3 == 0) {
		di3 = go(num / 3) + 1;
	}
	if(num % 2 == 0){
		di2  =  go(num / 2) + 1;
	}
	int sub = go(num - 1) + 1;

	int tempMin = min(di3, di2);
	tempMin = min(tempMin, sub);

	return dp[num] = tempMin;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	fill(&dp[0], &dp[0] + 1000010, 0);

	cout << go(n);
}
