#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> h[510];
int dp[510][510];

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);

      cin >> n;
      for (int i = 1; i <= n; i++) {
            cin >> h[i].first >> h[i].second;
      }

      // DP: dp[i][j] = i번째 행렬부터 j번째 행렬까지 곱할 때 최소 연산 횟수
      for (int length = 1; length <= n; length++) {  // 부분 문제의 길이
            for (int i = 1; i <= n - length + 1; i++) {           //시작 부분.

                  int j = i + length;                    //i부터 어디까지 곱의 최소값을 구할 것인가?
                  dp[i][j] = INT_MAX;                    //문제에 맞게 Int 최대값을 넣음.

                  for (int k = i; k < j; k++) {
                        int cost = dp[i][k] + dp[k + 1][j]
                              + h[i].first * h[k].second * h[j].second;
                        dp[i][j] = min(dp[i][j], cost);
                  }
            }
      }

      cout << dp[1][n] << "\n";
      return 0;
}
