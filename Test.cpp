#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int arr[10010];
int dp[10010];

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0); cout.tie(0);

      cin >> n;
      for (int i = 1; i <= n; i++) {
            cin >> arr[i];
      }

      dp[1] = arr[1];
      dp[2] = arr[1] + arr[2];
      for (int i = 3; i <= n; i++) {
            dp[i] = max({ dp[i - 1], dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i] });
      }

      cout << dp[n];
}
