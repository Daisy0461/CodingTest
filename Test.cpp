#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[100010];		//해당 무게가 남았을 때 최대 Value
vector<pair<int, int>> stufs;		//무게, 가치

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	int w, v;
	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		stufs.push_back({ w, v });
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		int nowWegiht = stufs[i].first;
		int nowValue = stufs[i].second;
		int nowLeftWegiht = k - nowWegiht;
		if (nowLeftWegiht < 0) continue;		//이 하나의 물건의 무게가 감당안된다.

		//내가 총 감당 가능한 무게에서 뺀 값을 dp에 넣는다. 이미 있는 값이 크면 따로 넣지 않는다.
		for (int j = nowWegiht; j < k; j++) {
			// 어떤 물건을 넣었을 때 현재 물건을 넣을 수 있는 만큼의 무게가 남아있다. &&
			//원래 j에서 nowWeight를 더한 만큼 남아있는 물건 무게에 다른 물건이 있을 수 있으니
			//무엇이 더 가치있는지 체크한다.
			if (dp[j] != 0 && dp[j - nowWegiht] < dp[j] + nowValue) {
				//cout << "now Weight : " << nowWegiht << "   in \n";
				//cout << "dp + result =" << dp[j] + nowValue << "\n";
				dp[j - nowWegiht] = dp[j] + nowValue;
			}
		}

		//이 코드가 위에있지 말고 아래이 있어야한다.
		//그 이후는 현재 무게가 k/2 이하일 때 해당 값이 2번 계산되기 때문이다.
		if (dp[nowLeftWegiht] < nowValue) {
			//nowLeftWeight에서 현재까지의 최대값은 nowValue이다.
			dp[nowLeftWegiht] = nowValue;
		}
	}

	for (int i = 0; i < k + 1; i++) {
		result = max(result, dp[i]);
	}
	cout << result;
}
