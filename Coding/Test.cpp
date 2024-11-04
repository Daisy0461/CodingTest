#include <bits/stdc++.h>

using namespace std;

int n;			//진행하는 회의의 수
int result = 0;
vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	int s, e;		//회의의 시작시간.		시작이간은 -부터 가능 100,000
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		v.push_back({ e, s });
	}

	sort(v.begin(), v.end());

	int e1 = v[0].first;				//v[0]이 end가 가장 빠른 위치이다.	
	result++;
	for (int i = 1; i < n; i++) {
		if (v[i].second >= e1) {			//다음 요소의 시작시간이 현재의 끝나는 시간보다 크거나 같다. 
			e1 = v[i].first;					//끝나는 시간이 빠른 순으로 정렬했기 때문에 지금 이게 가장 끝나느게 빠른 요소이다.
			result++;
		}
	}

	cout << result;
}