#include <bits/stdc++.h>

using namespace std;

int n, len=0, num;
int arr[1005];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fill(&arr[0], &arr[0] + 1005, 0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		auto lowerPos = lower_bound(arr, arr + len, num);
		if (*lowerPos == 0) len++;
		*lowerPos = num;
	}

	cout << len;
}
