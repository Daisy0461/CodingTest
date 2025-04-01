#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int arr[1010];
int dp[1010][2];           //first = index, second [0] = 현재 위치가 가장 낮은 지점일 때의 수, [1] = 현재가 가장 높은 지점일 떄의 수.

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0); cout.tie(0);

      fill(&dp[0][0], &dp[0][0] + 1010 * 2, 1);

      cin >> n;
      for (int i = 1; i <= n; i++) {
            cin >> arr[i];
      }

      //cout << "\n";
      int result = 1;
      for (int i = 1; i <= n; i++) {
            int nowNum = arr[i];
            //cout << "arr[i] : " << arr[i] << "\n";

            for (int j = i-1; j > 0; j--) {           //자신보다 이전에 나온 것들을 돈다.
                  //cout << "arr[j] : " << arr[j];
                  if (nowNum < arr[j]) {        //현재 숫자보다 큰 값을 만났다.
                        //일단 지금까지의 최대값인지 정해야한다.
                        //cout << "  in arr[i] < arr[j]\n";
                        dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                        dp[i][0] = max(dp[i][0], dp[j][0] + 1);
                  }
                  else if (nowNum > arr[j]) {
                        //cout << "  in arr[i] > arr[j]\n";
                        dp[i][1] = max(dp[i][1], dp[j][1] + 1);
                  }
                  else {
                        //cout << "  Same\n";
                  }
            }

            //cout << "i : " << i;
            result = max({ result, dp[i][0], dp[i][1] });
            //cout << "  dp[i][0] : " << dp[i][0] << "  dp[i][1] : " << dp[i][1] << "\n\n";
       }

      //cout << "result : ";
      cout << result;
}
