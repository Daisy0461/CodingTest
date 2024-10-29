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

		if (s.top().first > temp) {			//지금 들어온게 더 작다. 그 말은 이미 stack에 있는 것들은 temp보다 작은 것은 없다.
			s.push({ temp, count });
			result++;
		}
		else if (s.top().first < temp) {		//지금 들어온게 더 크다.
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