#include <bits/stdc++.h>

using namespace std;

int n, l, result = 0;		//l�� ������ ���� ����, ������ ���̴� �׻� 1
vector<vector<int>> v(101);
vector<vector<int>> vr(101);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> l;

	int height;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> height;
			v[i].push_back(height);
			vr[j].push_back(height);
		}
	}

	//cout << "Reverse Print\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j : vr[i]) {
	//		cout << j << " ";
	//	}
	//	cout << "\n";
	//}

	for (int i = 0; i < n; i++) {
		int sameCount = 0;
		int beforeHeight = 0;		//0�̸� ó���̴�. L�� 1���� �����̱⿡
		int j = 0;
		//cout << "i : " << i;
		for (j = 0; j < n; j++) {
			int currentHeight = v[i][j];

			if (beforeHeight == 0) {		//ó�� �־��ֱ�
				sameCount++;
				beforeHeight = currentHeight;
				continue;
			}

			if (beforeHeight == v[i][j]) {		//���� ���̿� ���ٸ�

				sameCount++;
			}
			else {		//beforeHeight != j
				int subResult = beforeHeight - currentHeight;
				if (abs(subResult) > 1) break;	//���̰� 1���� ũ�� �̹� ���� �� ����.
					

				if (subResult == -1) {		//�� ���� ���̰� �������� 1 ����.
					if (sameCount < l) break;	//sameCount�� ������ ���κ��� ������ ���� �� ����.
					sameCount = 1;
					beforeHeight = currentHeight;
				}
				else if (subResult == 1) {		//���� ���̰� �������� 1����.
					if (j + l - 1 >= n) {	//n���� ũ�� �����´�. �Ѿ��.
						j = n + 1;
						continue;
					}

					bool can = true;
					for (int k = 1; k <= l - 1; k++) {
						if (v[i][j + k] == currentHeight) {
							continue;
						}
						else {
							can = false;
						}
					}

					if (!can) break;

					j = j + l - 1;
					sameCount = 0;			//�ʱ�� ������.
					beforeHeight = currentHeight;
				}
			}
		}

		if (j == n) {
			//cout << " is result ++ \n";
			result++;
		}
		else {
			//cout << "\n";
		}
	}

	//cout << "Reverse \n";
	for (int i = 0; i < n; i++) {
		//cout << "i : " << i;
		int sameCount = 0;
		int beforeHeight = 0;		//0�̸� ó���̴�. L�� 1���� �����̱⿡
		int j = 0;
		for (j = 0; j < n; j++) {
			int currentHeight = vr[i][j];

			if (beforeHeight == 0) {		//ó�� �־��ֱ�
				sameCount++;
				beforeHeight = currentHeight;
				continue;
			}

			if (beforeHeight == vr[i][j]) {		//���� ���̿� ���ٸ�
				sameCount++;
			}
			else {		//beforeHeight != j
				int subResult = beforeHeight - currentHeight;
				if (abs(subResult) > 1) break;	//���̰� 1���� ũ�� �̹� ���� �� ����.


				if (subResult == -1) {		//�� ���� ���̰� �������� 1 ����.
					if (sameCount < l) break;	//sameCount�� ������ ���κ��� ������ ���� �� ����.
					sameCount = 1;
					beforeHeight = currentHeight;
				}
				else if (subResult == 1) {		//���� ���̰� �������� 1����.
					if (j + l - 1 >= n) break;		//n���� ũ�� �����´�. �Ѿ��.

					bool can = true;
					for (int k = 1; k <= l - 1; k++) {
						if (vr[i][j + k] == currentHeight) {
							continue;
						}
						else {
							can = false;
						}
					}

					if (!can) break;

					j = j + l - 1;
					sameCount = 0;			//�ʱ�� ������.
					beforeHeight = currentHeight;
				}
			}
		}

		if (j == n) {
			//cout << " is result ++ \n";
			result++;
		}
		else {
			//cout << "\n";
		}
	}

	cout << result;


}