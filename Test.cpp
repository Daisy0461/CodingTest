#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, x;		//n개의 수열이 주어진다. 수열의 수는 서로 다르다.
vector<int> v;
ll result =0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	//v는 무조건 size()-1 해도 음수는 아니다.

	sort(v.begin(), v.end());

	cin >> x;

	int s = 0, e = v.size() - 1;
	while (s < e) {
		int sum = v[s] + v[e];
		if (sum == x) {
			result++;
			s++;
			e--;
		}
		else if(sum > x) {		//합이 크다, 즉 숫자를 줄인다.
			e--;
		}
		else if (sum < x) {
			s++;
		}
	}

	cout << result;
}
