#include <bits/stdc++.h>

using namespace std;

//���°� 2������� ������ ���� �ְڴ�.
//0�� ���η� �߸��� ����, 1�� ���η� �߸��� ����.

int n, m;		//n�� m�� �ִ��� 4�̴�.
vector<vector<char>> v;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	char c;
	for (int i = 0; i < n; i++) {			//v�� �Էµ� �� �ֱ�
		for (int j = 0; j < m; j++) {
			cin >> c;
			v[i].push_back(c);
		}
	}

	for (int i = 0; i < (n * m); i++) {

	}
}