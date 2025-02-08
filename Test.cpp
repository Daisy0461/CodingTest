#include <bits/stdc++.h>
 
using namespace std;

int n, m;		//m번만 돈을뺀다.
int result = 100000 * 10000 + 100;
vector<int> v;

bool check(int num)
{
	int a = 0; int takeMoney = 1;
	for (int i : v) {
		a += i;
		if (i > num) return false;		//이미 하루가 num보다 크다. -> 금액이 맞지 않다.

		if (a > num) {		//총합 한 값이 하루의 금액보다 크다.
			a = i;
			takeMoney += 1;
		}
	}

	return takeMoney <= m;		//m번만 돈을 빼는데 이 함수 내에서 한 TakeMoney가 더 작거나 같다.
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int temp;
	int sum = 0;				//모든 금액 총합
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
		sum += temp;
	}

	int left = 1, right = sum, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (check(mid)) {
			result = min(result, mid);
			right = mid - 1;
		}
		else {		//금액을 더 크게 만든다.
			left = mid + 1;
		}
	}

	cout << result;
}
