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

	//pay�� date ������ �־�����.
	int p, d;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;			//pay�� ū������ �����ϰ� day�� ������Ѵ�.
		pq.push({ d, p });		//d�� ū������ ���ĵȴ�.
	}

	//day�� ���� ������ �־���� �� ������.
	//pay��  ū������ �����ϰ� �ڿ� �ص� �Ǵ� ��(date�� ū ��)�� pq�� ������ �� �ȿ� �ص� �Ǵϱ� �׷� ������ �����غ���.

	int highDate = 0;
	if (!pq.empty()) {
		highDate = pq.top().first;
	}
	for (int i = highDate; i > 0; i--) {
		while (!pq.empty() && pq.top().first == i) {
			pq2.push(pq.top().second);			//pay�� ū ������ ���ĵȴ�.
			pq.pop();
		}

		if (!pq2.empty()) {
			result += pq2.top();
			pq2.pop();
		}
	}

	cout << result;

}