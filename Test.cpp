#include <bits/stdc++.h>

using namespace std;

int a, b;	
vector<int> va, vb;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> a >> b;
	int temp;
	for (int i = 0; i < a; i++) {
		cin >> temp;
		va.push_back(temp);
	}
	for (int i = 0; i < b; i++) {
		cin >> temp;
		vb.push_back(temp);
	}

	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());

	int Same = 0;
	int aIndex = 0, bIndex = 0;
	while (aIndex != va.size() && bIndex != vb.size()) {
		if (va[aIndex] == vb[bIndex]) {
			Same += 1;
			aIndex += 1; bIndex += 1;
		}
		else if (va[aIndex] > vb[bIndex]) {		//a가 더 크다.
			bIndex += 1;
		}
		else if (va[aIndex] < vb[bIndex]) {
			aIndex += 1;
		}
	 }

	cout << va.size() + vb.size() - Same * 2;
}
