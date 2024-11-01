#include <bits/stdc++.h>

using namespace std;

int n;		// 1<= n <= 200000 과제의 개수
int result = 0;
priority_queue<pair<int, int>> pq;
priority_queue<int> pq2;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	int d, c;
	for (int i = 0; i < n; i++) {
		cin >> d >> c;
		pq.push({ d, c });			//데드라인이 큰것부터 한다. -> 데드라인이 크면 날짜가 줄어들어도 해결을 한다면 컵라면을 얻을 수 있기 때문이다.
	}

	int maxDate = pq.top().first;
	while (maxDate) {		//maxDate가 0일때는 하면 안된다. -> 데드라인은 자연수이니까
		//cout << "maxDate : " << maxDate << "\n";
		while (pq.size() && pq.top().first == maxDate) {			//pq가 비어있지 않고 데드라인이 현재 maxDate와 같을때
			pq2.push(pq.top().second);
			pq.pop();
		}

		if (pq2.size()) {			//pq2에 뭔가가 있다면
			result += pq2.top();
			//cout << "Now Result : " << result << "\n";
			pq2.pop();
		}

		maxDate--;
	}

	cout << result;
	//cout << "result : " << result << "\n";

}