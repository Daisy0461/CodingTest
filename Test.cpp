#include <bits/stdc++.h>

using namespace std;

int n, num, len = 0;
int arr[1004];
pair<int, int > p[1004];
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		auto lowerPos = lower_bound(arr, arr + len, num);
		int pos = (int)(lower_bound(arr, arr + len, num) - arr);
		if (*lowerPos == 0) len++;
		*lowerPos = num;
		p[i].first = num;
		p[i].second = pos;		//해당 num이 arr배열에서 몇번쨰 index에 추가되었는지를 확인한다.  - 2번에 있던 것에서 갱신되면 2가 들어가는 형식이다.
	}

	cout << len << '\n';
	for (int i = n - 1; i >= 0; i--) {
		if (p[i].second == len - 1) {
			len -= 1;
			v.push_back(p[i].first);
		}
	}
	reverse(v.begin(), v.end());


	for (int i : v) {
		cout << i << " ";
	}
}
