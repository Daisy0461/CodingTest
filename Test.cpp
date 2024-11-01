#include <bits/stdc++.h>

using namespace std;

int n;		// 1<= n <= 200000 ������ ����
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
		pq.push({ d, c });			//��������� ū�ͺ��� �Ѵ�. -> ��������� ũ�� ��¥�� �پ�� �ذ��� �Ѵٸ� �Ŷ���� ���� �� �ֱ� �����̴�.
	}

	int maxDate = pq.top().first;
	while (maxDate) {		//maxDate�� 0�϶��� �ϸ� �ȵȴ�. -> ��������� �ڿ����̴ϱ�
		//cout << "maxDate : " << maxDate << "\n";
		while (pq.size() && pq.top().first == maxDate) {			//pq�� ������� �ʰ� ��������� ���� maxDate�� ������
			pq2.push(pq.top().second);
			pq.pop();
		}

		if (pq2.size()) {			//pq2�� ������ �ִٸ�
			result += pq2.top();
			//cout << "Now Result : " << result << "\n";
			pq2.pop();
		}

		maxDate--;
	}

	cout << result;
	//cout << "result : " << result << "\n";

}