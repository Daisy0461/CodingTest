//1987

#include <bits/stdc++.h>

using namespace std;

int r, c, result = 0;
int alphaArray[25][25];
int visitedAlpha[50];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0 , -1, 0 };

void dfs(int y, int x, int count)
{
	visitedAlpha[alphaArray[y][x]] = 1;		//���� ���� ���ĺ��� �湮ó���Ѵ�.

	bool haveNext = false;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;		//���� ���̸� continue;
		if (visitedAlpha[alphaArray[ny][nx]]) continue;		//�̹� �湮�� ���̶�� continue;

		haveNext = true;		//�������� ���ư� ĭ�� ���� �����ִ�.
		dfs(ny, nx, count + 1);
	}

	if (!haveNext) {							//���� ĭ���� �� ���ư��� ���ؼ� max�� ���Ѵ�.
		result = max(count, result);
	}

	visitedAlpha[alphaArray[y][x]] = 0;		//�ٸ� ������ �� ��쿡 ���� ĭ�� �ش��ϴ� alpha�� ���� �� �����Ƿ� 0���� �ٽ� ������ش�.
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> r >> c;
	
	char temp;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> temp;
			alphaArray[i][j] = temp - 'A';
		}
	}

	dfs(0, 0, 1);

	cout << result;
}