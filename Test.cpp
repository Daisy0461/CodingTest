#include <bits/stdc++.h>

using namespace std;

int n;
int lis[1000010],len = 0, num;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//fill(&lis[0], &lis[0] + 1000010, 1e9 + 1);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		auto lowerPos = lower_bound(lis, lis + len, num);
		if (!*lowerPos) len++;
		*lowerPos = num;
		cout << *lowerPos << "\n";
		for (int j = 0; j < n; j++) {
			cout << lis[j] << " ";
		}
		cout << "\n";
	}

	int index = 0;
	while (lis[index]) {
		cout << lis[index] << " ";
		index += 1;
	}
	cout << len;
}
