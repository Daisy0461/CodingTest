#include <bits/stdc++.h>

using namespace std;

int n, result = 0;
priority_queue<pair<int, int>> pq;		//date, pay
priority_queue<int> pq2;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	//pay와 date 순으로 주어진다.
	int p, d;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;			//pay가 큰순으로 정리하고 day에 맞춰야한다.
		pq.push({ d, p });		//d가 큰순으로 정렬된다.
	}

	//day가 작은 순으로 넣어야할 것 같은데.
	//pay가  큰순으로 정렬하고 뒤에 해도 되는 것(date가 큰 것)을 pq에 넣으면 그 안에 해도 되니까 그런 식으로 진행해보자.

	int highDate = 0;
	if (!pq.empty()) {
		highDate = pq.top().first;
	}
	for (int i = highDate; i > 0; i--) {
		while (!pq.empty() && pq.top().first == i) {
			pq2.push(pq.top().second);			//pay가 큰 순으로 정렬된다.
			pq.pop();
		}

		if (!pq2.empty()) {
			result += pq2.top();
			pq2.pop();
		}
	}

	cout << result;

}