#include <bits/stdc++.h>

using namespace std;

bool bIsFindResult = false;
int bodingNum;
int usedNum[10];
vector<int> result;
vector<bool> vIsFindBigger;

void FindResult(int num, int index)
{
	usedNum[num] = 1;
	if (index == bodingNum && bIsFindResult == false) {
		//cout << "Find Result \n";
		for (int i : result) {
			cout << i;
		}
		cout << "\n";

		bIsFindResult = true;
		return;
	}

	if (bIsFindResult) return;

	if (vIsFindBigger[index]) {		//지금 num보다 더 큰 값을 찾는다.
		for (int i = num + 1; i < 10; i++) {
			if (usedNum[i]) continue;

			result.push_back(i);
			FindResult(i, index + 1);
			result.pop_back();
		}
	}
	else {
		for (int i = num - 1; i >= 0; i--) {
			if (usedNum[i]) continue;

			result.push_back(i);
			FindResult(i, index + 1);
			result.pop_back();
		}
	}

	usedNum[num] = 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> bodingNum;

	char temp;
	for (int i = 0; i < bodingNum; i++) {
		cin >> temp;
		if (temp == '<') {
			vIsFindBigger.push_back(true);
		}
		else if (temp == '>') {
			vIsFindBigger.push_back(false);
		}
	}

	for (int i = 9; i >= 0; i--) {
		result.push_back(i);
		FindResult(i, 0);
		result.pop_back();

		if (bIsFindResult) break;
	}

	result.clear();
	bIsFindResult = false;
	fill(&usedNum[0], &usedNum[0] + 10, 0);

	for (int i = 0; i < 10; i++) {
		result.push_back(i);
		FindResult(i, 0);
		result.pop_back();

		if (bIsFindResult) break;
	}
}