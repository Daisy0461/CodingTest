#include <bits/stdc++.h>

using namespace std;

int n; 
double num;
double maxValue = 0;
vector<double> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	double value = 1;
	for (double i : v) {
		maxValue = max(maxValue, i);		//i 하나가 가장 클 수 있으므로 작성.

		if (value * i < 1) {
			value = 1;		//지금까지 구한 값이 1보다 작다면 이미 이후에 곱하는 값은 더 작아진다. 이때 max랑 비교하면 안된다.
		}
		else {
			value = value * i;
			maxValue = max(maxValue, value);
		}
	}

	cout << fixed;
	cout.precision(3);
	cout << maxValue << '\n';

}
