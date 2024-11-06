#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//���ӵ� �Ҽ��� ������ n�� ������.
int n;
int result = 0;
vector<int> v;

bool check(int num)
{
	if (num == 2 || num == 3) {
		return true;
	}

	if (num % 2 == 0) {		//num�� ¦����� 
		return false;			//�Ҽ��� �ƴϴ�.
	}

	bool flag = true;
	for (int i = 3; i * i <= num; i = i + 2) {		
		if (num % i == 0) {
			flag = false;
			break;
		}
	}

	return flag;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	if (n == 1) {
		cout << 0;
		return 0;
	}
	else if (n == 2) {
		cout << 1;
		return 0;
	}

	for (int i = 2; i < n; i++) {
		if (check(i)) {		//i�� �Ҽ��̴�.
			v.push_back(i);		//sort ���ʿ�.
		}
	}

	/*for (int i : v) {
		cout << i << " ";
	}*/

	if (check(n)) {
		result++;
	}

	int s = 0;
	while (v[s] <= n/2) {
		int sum = 0;
		for (int i = s; i < n; i++) {
			sum += v[i];
			if (sum == n) {
				result++;
				s++;
				break;
			}
			else if (sum > n) {
				s++;
				break;
			}
		}
	 }

	cout << result;
}