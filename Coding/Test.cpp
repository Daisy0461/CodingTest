#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll result = 0;
stack<pair<ll, ll>> s;		//s.

int main()
{
	cin >> n; 

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		int count = 1;
		if (s.empty()) {
			s.push({ temp, count });
			continue;
		}

		if (s.top().first > temp) {			//���� ���°� �� �۴�. �� ���� �̹� stack�� �ִ� �͵��� temp���� ���� ���� ����.
			s.push({ temp, count });
			result++;
		}
		else if (s.top().first < temp) {		//���� ���°� �� ũ��.
			while (!s.empty() && s.top().first < temp) {
				result += s.top().second;
				s.pop();
			}
			s.push({ temp, count });
		}
		else if (s.top().first == temp) {
			result += s.top().second;
			count = s.top().second + 1;
			s.pop();

			if (!s.empty()) {
				result += s.top().second;
			}

			s.push({ temp, count });
		}
	}

	cout << result;
}