#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;

int main()
{
	cin >> n;

	int arriveTime, checkTime;
	for (int i = 0; i < n; i++) {
		cin >> arriveTime >> checkTime;

		v.push_back({ arriveTime, checkTime });
	}

	sort(v.begin(), v.end());

	int et = v[0].first + v[0].second;

	for (int i = 1; i < n; i++) {
		if (v[i].first >et) {		//���� ����� �����ð��� ����  �����ð����� ũ��.
			et = v[i].first + v[i].second;
		}
		else {
			et += v[i].second;
		}
	}

	cout << et;
}