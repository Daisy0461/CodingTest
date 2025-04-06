#include <bits/stdc++.h>

using namespace std;

int testCase;
int n, fileSize;
int files[510];
int sum[510];
int dp[510][510];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> testCase;

	while (testCase--)
	{
		//배열 초기화
		fill(&files[0], &files[0] + 510, 0);
		fill(&sum[0], &sum[0] + 510, 0);
		//fill(&dp[0][0], &dp[0][0] + 510 * 510, 0);

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> files[i];
			//지속 합-> sum[i]는 i까지의 모든 file의 크기 합. 이후에 사용한다.
			sum[i] = sum[i - 1] + files[i];		
		}

		for (int indexCount = 1; indexCount < n; indexCount++) {

			//start + indexCount지점까지 -> start부터 indexCount개까지의 합
			for (int start = 1; indexCount + start <= n; start++) {
				int end = start + indexCount;

				//미리 구할 범위의 dp를 INT_MAX로 해서 최소값을 찾는다.
				dp[start][end] = INT_MAX;

				for (int mid = start; mid < end; mid++) {
					//dp의 의미가 start지점부터 index지점까지의 합의 최소를 구하는 것이다.
					/*
					* dp[start][index] = min(기존의 dp[start][index],
					* dp[start][mid] + dp[mid+1][end]를 통해 mid로 중간을 잘라서 양쪽 값에서 최소를 구한다.
					* 그렇다면 왜 mid로 구하는가? -> 우린 start부터 end까지의 조합이 어떤 값이 가장 작은지 모른다.
					* 
					* 그럼 이미 비교당할 dp의 조합은 어떻게 구하는가?
					* 이전 for문을 돌면 start가 1부터 늘어날 것이기에 작은 start부터 최소값을찾게 된다.
					* start부터 indexCount는 1부터 늘어남으로 1~2, 2~3, 3~4처럼 작은 값부터 찾고 그 이후 1~3, 2~4이런 식으로 범위가 늘어가는 구조이다.
					* 작은 값이 구해져있으면 위에서 설명한 이유로 큰 부분의 최소값을 구할 수 있다.
					* 
					* 마지막 sum[end]-sum[start-1]는 파일이 만들어지면 해당 파일의 크기만큼 비용을 쓰게 된다.
					* 그렇기에 start-1부터 end까지의 범위의 비용을 더해야하는 의미이다.
					* 처음에 start-1이 아닌 start를 했는데 이는 자기 자신도 빼는 것이라서 start-1을 해야 정확한 범위의 값을 더한다.
					* 
					*/
					//cout << "Compare dp[start][end] : " << dp[start][end] << "  vs calculation : " << dp[start][mid] + dp[mid + 1][end] + (sum[end] - sum[start-1]) << "\n";
					dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + (sum[end] - sum[start-1]));
					//cout << "dp[" << start << "][" << end << "] is : " << dp[start][end] << "\n";
				}

				
			}
				
		}

		//cout << "\n result :";
		cout << dp[1][n] << "\n";
	}
}
