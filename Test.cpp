#include <bits/stdc++.h>

using namespace std;

int n, m;
int result = 987654321;
vector<int> v;

bool search(int num)
{
	int a = 0;
	for (int i : v) {
		a += i / num;
		if (i % num) a++;
	}

	return a <= n;			//a가 실제 사람 수 보다 작으면 true
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int left = 1, right = 0, mid;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		right = max(right, temp);		//가장 큰 값을 right에 넣는다.
	}

	while (left <= right) {
		mid = (left + right) / 2;
		cout << "mid : " << mid;
		if (search(mid)) {
			cout << "  is pass \n";
			result = min(result, mid);
			right = mid - 1;
		}
		else {
			cout << "  isn't pass \n";
			left = mid + 1;
		}
	}

	cout << result;
}
