#include <bits/stdc++.h>

using namespace std;

int n;		//총 배열 길이
int maxResult = -987654321;
bool bIsPossitive = false;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	int temp;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp > 0) bIsPossitive = true;		//최소한 하나의 양수가 들어왔다.

		if (temp > maxResult) {		//단일 값이 가장 크다면 -> 예를 들어서 모든 값이 음수
			maxResult = temp;
		}

		sum += temp;
		if (bIsPossitive && sum > maxResult) {		//최소한 하나의 양수가 있어야하는 이유 -> 밑에서 sum을 0으로 초기화하기 때문에 모든 값이 양수일 때 maxResult를 0으로 초기화하면 안된다.
			maxResult = sum;
		}

		if (sum < 0) {		//지금까지 더 한 결과가 음수이다. 즉, 이후에 그냥 더 하는 값이 더 크다.
			sum = 0;		
		}
	}

	if (bIsPossitive && sum > maxResult) {
		maxResult = sum;
	}

	cout << maxResult;
}
