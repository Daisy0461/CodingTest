#include <bits/stdc++.h>

using namespace std;

int n, minResult = 987654321;		//�α���
int tempIndex, tempSum;
int visited[20];
vector<int> pops;
vector<vector<int>> links(20);
vector<int> Sums;

void FindLinks(int vilage, int bit)
{
	visited[vilage] = 1;
	tempSum += pops[vilage];

	for (int i : links[vilage]) {
		if (visited[i]) continue;

		if ((tempIndex & (1 << (i - 1))) == bit) {		//���� bit�� �����ϴٸ�
			FindLinks(i, bit);
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	pops.push_back(0);		//������ 1���� �����ؼ� ó���� push_back��.
	int pop = 0;
	for (int i = 1; i <= n; i++) {				//1���������� �α����� �Է¹޴´�.
		cin >> pop;
		pops.push_back(pop);
	}
	int in;
	int link;
	for (int i = 1; i <= n; i++) {
		cin >> in;
		for (int j = 0; j < in; j++) {
			cin >> link;
			links[i].push_back(link);			//i������ link�� ���� ������ ����Ǿ��ִ�.
		}
	}

	for (int i = 1; i < (1 << n) - 1; i++) {
		cout << "i : " << i << "   ";
		fill(&visited[0], &visited[0] + 20, 0);
		Sums.clear();
		tempIndex = i;
		tempSum = 0;

		for (int j = 0; j < n; j++) {		//��Ʈ üũ�� 0�������Ѵ���
			if (visited[j + 1]) continue;		//j+1������ ��ȴٸ� 

			if (i & (1 << j)) {
				FindLinks(j + 1, 1);
				Sums.push_back(tempSum);
			}
			else {
				FindLinks(j + 1, 0);
				Sums.push_back(tempSum);
			}
		}

		if (Sums.size() == 2) {
			cout << "minResult : " << abs(Sums[0] - Sums[1]);
			minResult = min(minResult, abs(Sums[0] - Sums[1]));
		}
		cout << "\n";
	}

	cout << minResult;
}