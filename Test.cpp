#include <bits/stdc++.h>

using namespace std;

int n, result = -1;
int nums[1001];
int prevIndex[1001];
int numStacks[1001];
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	fill(&prevIndex[0], &prevIndex[0] + 1001, -1);
	fill(&numStacks[0], &numStacks[0] + 1001, 0);	

	int highestIndex = 0;
	for (int i = 0; i < n; i++) {
		int prevIndexNum = i;
		for (int j = 0; j < i; j++) {
			if (nums[j] < nums[i] && numStacks[i] < numStacks[j]) {		//현재 i보다 왼쪽에 있는 수가 더 작다. && 그 왼쪽에 있는 수의 Stack이 현재 수의 Stack보다 크다.
				numStacks[i] = numStacks[j];		//현재 숫자가 이전 숫자의 높이까지는 왔다. -> 계속 오른쪽으로 나아갈 수록 더 높은 Stack이 있으니 그걸로 갱신한다.
				prevIndexNum = j;		//현재 숫자보다 바로 직전에 높았던 숫자는 nums[j]에 있는 숫자이다.
			}
		}

		prevIndex[i] = prevIndexNum;		//현재 숫자 이전에 가장 높았던 숫자의 Index를 저장. 
		numStacks[i] = numStacks[i] + 1;

		if (result < numStacks[i]) {		//현재 숫자가 이전까지의 Stacks보다 높다.
			highestIndex = i;
			result = numStacks[i];
			cout << "hightest Index : " << i << "\n";
		}
	}

	int findNumIndex = highestIndex;
	while (findNumIndex != prevIndex[findNumIndex]) {
		v.push_back(nums[findNumIndex]);				//findNumIndex가 가리키는 숫자를 넣는다.
		findNumIndex= prevIndex[findNumIndex];		//findNumIndex를 현재 숫자의 바로 이전 높았던 숫자를 가르키게 한다.
	}
	v.push_back(nums[findNumIndex]);		//마지막 추가
	reverse(v.begin(), v.end());

	cout << "result \n";
	for (int i : v) {
		cout << i << " ";
	}
}
