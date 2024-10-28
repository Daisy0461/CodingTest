#include <bits/stdc++.h>

using namespace std;

//0�� ���� 1�� ����

int n, m;
int num;
int maxResult = 0;
vector<vector<int>> v(5);
vector<vector<int>> bits(5, vector<int>(5, 0));  // �ʱ�ȭ�� ũ�� ����
int visited[5][5];

void goGa(int y, int x)
{
	visited[y][x] = 1;

	num += v[y][x];
	if (x + 1 >= m) return;
	if (visited[y][x + 1]) return;

	if (bits[y][x + 1] == 1) {
		num *= 10;
		goGa(y, x + 1);
	}
}

void goSe(int y, int x)
{
	visited[y][x] = 1;

	num += v[y][x];
	//cout << "v : " << v[y][x] << "  ";
	//cout << "num " << num << "\n";
	if (y + 1 >= n) return;
	if (visited[y + 1][x]) return;

	if (bits[y + 1][x] == 0) {
		num *= 10;
		goSe(y + 1, x);
	}
}

int main()
{
	cin >> n >> m;

	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			int num = c - '0';
			v[i].push_back(num);
		}
	}

	for (int t = 0; t < (1 << (n * m)); t++) {  // ��� ����� ���� ���� �ݺ�
		//cout << "t :" << t << "\n";

		// bits�� �ʱ�ȭ�� �� �ε����� ����Ͽ� ���� ����
		bits.assign(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (t & (1 << (i * m + j))) {  // m ��� n+1�� ����ϸ� �߸��� ��Ʈ ��ġ ����
					bits[i][j] = 1;
				}
				else {
					bits[i][j] = 0;
				}
			}
		}

		fill(&visited[0][0], &visited[0][0] + 5 * 5, 0);

		int tempSum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j]) continue;

				num = 0;
				//cout << "i : " << i << " j : " << j << "   bits result : " << bits[i][j] << "\n";
				if (bits[i][j] == 1) {
					goGa(i, j);
				}
				else {
					goSe(i, j);
				}
				//cout << "num : " << num << "\n";
				tempSum += num;
			}
		}

		maxResult = max(maxResult, tempSum);
	}

	cout << maxResult;
}
