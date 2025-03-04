#include <bits/stdc++.h>

using namespace std;

//연속된 세 개의 계단을 밟아선 안된다.
//계단은 한개 또는 두개씩 오를 수 있다.

int n;
int stairs[310];
int dp[310][2];		//stairs 최대값, 0 = 이전걸 밟지 않음. 1 = 이전걸 밟았다.

int go(int num, int before)
{
	int& ret = dp[num][before];		//num이라는 stairs에서 이전의 밟았는지 아닌지
	if (ret != 0) return ret;		//이미 값이 존재한다면 그냥 return;

	if (before == 0) {		//이전걸 밟지 않았다.
		return dp[num][before] = max(go(num - 2, 0), go(num - 2, 1)) + stairs[num];		//before이 0이면 num-1의 계단은 밟지 않았다는 의미이다. 즉, num-2에서 최대값을 들고온다. 그리고 현재 값 +
	}
	else {
		return dp[num][before] = go(num - 1, 0) + stairs[num];		//이전 계단을 밟았다면 당연히 두칸 전은 밟지 않아야한다.
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> stairs[i];
	}

	dp[0][0] = stairs[0];
	dp[0][1] = stairs[0];
	dp[1][0] = stairs[1];
	dp[1][1] = stairs[0] + stairs[1];

	//for (int i = 2; i < n; i++) {
	//	dp[i][0] = max(dp[i-2][0], dp[i - 2][1]) + stairs[i];		//두칸 전 값을 들고 온다.
	//	dp[i][1] = dp[i - 1][0] + stairs[i];

	//	//cout << i << "에서 이전을 밟지 않았을 때 값 : " << dp[i][0] << "  \n" << i << "에서 이전을 밟았을 때 : " << dp[i][1] << "\n";
	//}

	cout << max(go(n - 1, 0), go(n - 1, 1));
}
