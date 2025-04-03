#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int dp[1010][1010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s1 >> s2;

	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) {			//s1 i-1번째 문자와 s2의 j-1번째의 문자가 동일하다.
				//이전에 있던 문자열의 길이 -> 현재 문자열(i)비교 전(i-1)에 이전 번째 dp(가장 긴 문자열)의 +1을 한다.
				//왜냐면 지금 문자열이 똑같으니까 길이가 +1 되는 것이다.
				dp[i][j] = dp[i - 1][j - 1] + 1;	
			}
			else {
				//여긴 이전에 문자열 길이에서 최장 길이를 찾아서 넣어야한다.
				//i-1,j => 이전 문자열을 비교할 때의 문자열 최장 길이.
				//i, j-1 => 현재 문자열을 비교할 때 문자열 최장 길이. -> 더 길게 만들 수 있는 경우가 있을 수 있음.
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[s1.length()][s2.length()];
}
