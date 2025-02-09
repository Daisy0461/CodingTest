#include <bits/stdc++.h>

using namespace std;

//A는 B를 먹는다. A는 자기보다 크기가 작은 B만 먹을 수 있다.
//이런 쌍이 몇가기 있는가?
int testCase, a, b;
vector<int> va, vb;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> testCase;

	for (int t = 0; t < testCase; t++) {
		cin >> a >> b;
		//a집합 b집합 입력
		int temp, result = 0;
		va.clear(); vb.clear();
		for (int i = 0; i < a; i++) {
			cin >> temp;
			va.push_back(temp);
		}
		for (int i = 0; i < b; i++) {
			cin >> temp;
			vb.push_back(temp);
		}
		sort(va.begin(), va.end(), less<>());		//작은 것 부터 하도록 함.
		sort(vb.begin(), vb.end());

		for (int i : va) {
			for (int j : vb) {
				if (i > j) {
					result++;
				}
				else break;
			}
		}
		//cout << "result : ";
		cout << result << "\n";
	}

}
