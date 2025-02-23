#include <bits/stdc++.h>

using namespace std;

int s, m, num;
int maxCount = 0;
int dp[105][2][35];		//총 떨어지는 시간, 나무 개수, 남은 이동횟수
vector<int> t;

int go(int index, int tree, int move) 
{
	if (move < 0) return -1e9;
	if (index == s) return 0;		//사과가 다 떨어졌다.

	int& ret = dp[index][tree][move];
	if (ret != -1) return ret;		//초기값이 아니면 해당 값을 return한다.

	return ret = max(go(index + 1, tree, move),			//다음 사과가 떨어지는 case로 간다. 이때 tree를 옮기지 않는다. 그럼 move count도 깎이지 않는다.
		go(index + 1, tree^1, move - 1)) +					//다음 사과가 떨어지는 case로 간다. 이때 tree를 옮기며 move count도 1을 뺀다.
		(t[index] == tree ? 1 : 0);							//지금 tree에서 사과가 떨어지면 현재 가르키는 dp에 1을 추가하고 아니면 추가하지 않는다.
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s >> m;
	for (int i = 0; i < s; i++) {
		cin >> num;
		t.push_back(num - 1);
	}

	fill(&dp[0][0][0], &dp[0][0][0] + 105 * 2 * 35, -1);

	int result = max(go(0, 0, m), go(0, 1, m));
	cout << result;
}
