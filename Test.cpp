#include <bits/stdc++.h>

using namespace std;

int n;
int result = 0;
vector<int> v;
vector<int> v2(1001);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	//수열 입력
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		int maxValue = 0;
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i] && maxValue < v2[j]) {			//앞의 수가 현재 수보다 작다 && maxValue가 현재 위치에 있는 수 보다 작다.
				maxValue = v2[j];
			}
		}
		v2[i] = maxValue + 1;		//현재 i에는 maxValue + 1을 해서 하나를 더 한 수를 넣어준다.
		cout << "i : " << i << "  v2[i] : " << v2[i] << "\n";
		result = max(result, v2[i]);
	}

	cout << result;
}
