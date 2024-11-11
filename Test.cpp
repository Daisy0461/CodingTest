#include <bits/stdc++.h>

using namespace std;

int n, k;
int INF = 987654321;
int result = 0;
int arr[101], visited[101];
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < k; i++){
		cin >> arr[i];
	}

	for (int i = 0; i < k; i++) {
		if (!visited[arr[i]] ) {
			if (v.size() == n) {			
				//콘센트에 자리가 없고 현재 콘센트에 꽂혀있지 않은 것이라면
				int last_Index = 0; int findNum;
				for (int a : v) {		//v는 현재 콘센트에 꽂혀있는 것을 의미한다. 가장 뒤에 사용할 것을 찾아야한다.
					int tempIndex = 987654321;
					for (int j = i + 1; j < k; j++) {
						if (arr[j] == a) {			//이후에 사용하는 가전제품 중 v에 있는 a와동일한 가전제품을 찾았다면
							tempIndex = j;
							break;
						}
					}

					if (last_Index < tempIndex) {			//지금까지 나왔던 값들 보다 현재의 가전제품이 제일 뒤에 사용한다.
						findNum = a;
						last_Index = tempIndex;
					}
				}

				visited[findNum] = 0;
				v.erase(find(v.begin(), v.end(), findNum));
				result++;
			}
			v.push_back(arr[i]);
			visited[arr[i]] = 1;
		}	
	}

	cout << result;

}
