#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;		//n = 골동품 수, k = 가방 수
ll result = 0;
vector < pair < ll, ll >> stufs;
vector<int> bags;
priority_queue <ll> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	ll m, v;
	for (int i = 0; i < n; i++) {
		cin >> m >> v;					//무게 ,가격
		stufs.push_back({ m, v });
	}

	int c;
	for (int i = 0; i < k; i++) {
		cin >> c;
		bags.push_back(c);
	}

	sort(stufs.begin(), stufs.end());			//무게가 작은 순으로 정렬된다.
	sort(bags.begin(), bags.end());				//담을 수 있는 무게가 작은 순으로 가방도 정렬된다

	int stufsIndex = 0;
	for (int i = 0; i < k; i++) {			//담을 수 있는 무게가 작은 순부터 순차적으로 돌면서 검사한다.
		while (stufsIndex < n && bags[i] >= stufs[stufsIndex].first) {	//범위를 벗어나지 않으면서 bag[i]가 stufs[stufsIndex]의 무게를 담을 수 있을 때 계속 돌린다.
			pq.push(stufs[stufsIndex].second);		//가치의 최대 합이기 때문에 가격만 pq로 더한다. -> pq로 하는 이유 : top이 가장 비쌀거니까.
			stufsIndex++;
		}
		//현재 가방에 담을 수 있는 것은 다 pq에 넣었다.
		//이후에 가방은 지금 가방보다 더 무거운 것을 담을 수 있으므로 pq는 유지한다. 왜냐면 이미 더 작은 가방에도 담을 수 있기 때문이다.
		
		if (pq.size()) {
			result += pq.top();
			pq.pop();
		}
	}

	cout << result;


}