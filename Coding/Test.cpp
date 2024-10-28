#include <bits/stdc++.h>

using namespace std;

string s1, s2;
vector<int> result;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s1 >> s2;

	int s1Index = s1.size() - 1;
	int s2Index = s2.size() - 1;

	bool isUp = false;
	while (s1Index != -1 && s2Index != -1) {
		int temps1 = s1[s1Index] - '0';
		int temps2 = s2[s2Index] - '0';
		int tempSum = temps1 + temps2;
		if (isUp) {
			tempSum++;
			isUp = false;
		}
		
		if (tempSum >= 10) {
			isUp = true;
			tempSum -= 10;
		}

		result.push_back(tempSum);

		s1Index--;
		s2Index--;
	}

	bool iss1End = false;
	if (s1Index == -1) {
		iss1End = true;
	}

	if (iss1End) {
		while (s2Index != -1) {
			int temp = s2[s2Index] - '0';
			if (isUp) {
				temp++;
				isUp = false;
			}

			result.push_back(temp);
			s2Index--;
		}
	}
	else {
		while (s1Index != -1) {
			int temp = s1[s1Index] - '0';
			if (isUp) {
				temp++;
				isUp = false;
			}

			result.push_back(temp);
			s1Index--;
		}
	}

	if (isUp) {
		result.push_back(1);
	}

	for (int i = result.size()-1; i >= 0; i--) {
		cout << result[i];
	}
}