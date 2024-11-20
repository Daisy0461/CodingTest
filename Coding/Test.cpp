#include <bits/stdc++.h>

using namespace std;

//�����ϰ� ���� �ٸ��� ȸ�������� �ݴ�������� ȸ���Ѵ�.
//rotate <- / rrotate ->

int t, k;		//��Ϲ����� 1������ ������ �Ű�����. k�� ȸ���Ѵ�.
int result = 0;
vector<vector<int>> toms(1005);
int visited[1005];

void turn(int tomNum, int dir)
{
	//cout << tomNum << "is turning\n";
	visited[tomNum] = 1;

	if (tomNum + 1 < t && !visited[tomNum + 1]) {		//tomNum + 1�� ������ ����� �����鼭 �湮���� ���� ��϶��
		//���� ��Ͽ� �������� ��Ͽ� ���ؾ��Ѵ�.
		if (toms[tomNum][2] != toms[tomNum + 1][6]) {		//���� ����� �����ʰ� ������ ����� �ަU�� �������� ������ ������.
			turn(tomNum + 1, dir * -1);
		}
	}

	if (tomNum - 1 >= 0 && !visited[tomNum - 1]) {		//tomNum - 1�� ������ ����� �����鼭 �湮���� �ʴ� ��϶��
		if (toms[tomNum][6] != toms[tomNum - 1][2]) {		//���� ����� �����ʰ� ������ ����� �ަU�� �������� ������ ������.
			turn(tomNum - 1, dir * -1);
		}
	}

	//���� ��� ������
	if (dir == 1) {		//�ð� ���� rrot
		rotate(toms[tomNum].rbegin(), toms[tomNum].rbegin() + 1, toms[tomNum].rend());
	}
	else {
		rotate(toms[tomNum].begin(), toms[tomNum].begin() + 1, toms[tomNum].end());
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;

	char tempTom;
	//12�ð� [i][7]�� ����. �ð�������� 1�� �پ��� �Է��̴�.
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> tempTom;
			toms[i].push_back(tempTom - '0');
		}
	}

	cin >> k;

	int tom, dir;
	for (int i = 0; i < k; i++) {
		fill(&visited[0], &visited[0] + 1005, 0);

		cin >> tom >> dir;		//��� ��ϸ� ������ ������ 
		turn(tom - 1, dir);

		/*cout << k << "turn result\n";
		for (int i = 0; i < t; i++) {
			for (int j : toms[i]) {
				cout << j;
			}
			cout << "\n";
		}*/
	}

	for (int i = 0; i < t; i++) {
		result += toms[i][0];
	}

	cout << result;

}