#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
vector<int> nums;
int upResult = 0;
int prev_arr[1000010];
int upCounts[1000010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	fill(&prev_arr[0], &prev_arr[0] + 1000010, -1);
	fill(&upCounts[0], &upCounts[0] + 1000010, 1);

	int index = 0;
	for (int i = 0; i < n; i++) {			//현재 num = i
		for (int j = 0; j < i; j++) {			//이전 num = j
			if (v[i] > v[j] && upCounts[i] <= upCounts[j]) {		//현재 숫자가 이전에 있던 숫자보다 크다.
				upCounts[i] = upCounts[j] + 1;		//이전(j) 보다 +1한다.
				prev_arr[i] = j;		//현재 num의 이전 높던 값은 j이다.

				if (upResult < upCounts[i]) {
					upResult = upCounts[i];
					index = i;		//마지막 요소를 위해서 저장한다.
				}
			}
		}
	}

	vector<int> results;
	while (index != -1) {
		//cout << "push Num : " << v[index] << "\n";
		results.push_back(v[index]);
		index = prev_arr[index];
	}

	reverse(results.begin(), results.end());

	//cout << "results \n";
	cout << upResult << '\n';
	for (int i = 0; i < results.size(); i++) {
		cout << results[i] << " ";
	}
}
