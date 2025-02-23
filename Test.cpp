#include <bits/stdc++.h>

using namespace std;

int num;
long long f[1005];

long long fibo(int n)
{
	if (n <= 1) return 1;

	long long& ret = f[n];
	if (ret != -1) return ret;

	return ret = fibo(n - 1) + fibo(n - 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fill(&f[0], &f[0] + 1005, -1);

	cin >> num;

	long long result = fibo(num);
	cout << result;
}
