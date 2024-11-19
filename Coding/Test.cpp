#include <bits/stdc++.h>

using namespace std;

int toms[4];
int visited[5];
int n;		//ȸ�� Ƚ��

void turn(int t, int dir) {		//toms[t]��° ��ϰ� ���ư��� dir �������� ���ư���.
	//üũ�ؾ��ϴ� ��Ʈ �ڸ��� 1 ����(��), 5 ������(�Ʒ�)
	visited[t] = 1;			//�ٽ� ���� �� �����ϱ� ���ؼ�
	/*cout << "in t : " << t << "  dir : ";
	if (dir == 1) {
		cout << "�ð�\n";
	}
	else {
		cout << "�ݽð�\n";
	}*/
	if (t+1 < 4 && !visited[t + 1]) {		//t+1�� ���� ���̴�. �׸��� t��°�� ����� �����ʰ� t+1��°�� ����� ��Ʈ�� �����ϴ�. -> t�� t�� �������� ����.
		//������ �ٸ��� ������ ���� 100000�� �ڴ� 10�̴ϱ� �翬�� �ٸ��� ������ �����ؾ���.
		int t1 = toms[t] & (1 << 5);
		int t2 = toms[t + 1] & (1 << 1);
		t1 = t1 >> 4;

		//cout << "t+1 -> " << "t's 5�� bit : " << t1/2 << "   t2's 1�� bit : " << t2/2 << "\n";

		if (t1 != t2) {
			turn(t + 1, dir * -1);
		}
	}

	if (t - 1 >= 0 && !visited[t - 1]) {		//t-1�� ���� ���̴�. �׸��� t��°�� ��� ���ʰ� t-1��°�� �������� ��Ʈ�� �����ϴ�.
		int t1 = toms[t] & (1 << 1);
		int t2 = toms[t - 1] & (1 << 5);
		t2 = t2 >> 4;

		//cout << "t-1 -> " << "t's 1�� bit : " << t1/2 << "   t2's 5�� bit : " << t2/2 << "\n";

		if ( t1 != t2) {
			turn(t - 1, dir * -1);
		}
	}

	bool isOn;
	if (dir == 1) {		//�ð����
		isOn = (toms[t] & (1 << 0));		//0��° ��Ʈ�� ���������� true �ƴϸ� false�� ����.
		toms[t] = toms[t] >> 1;
		if (isOn) {
			toms[t] = toms[t] + (1 << 7);		//7��° ��Ʈ�� Ų��.
		}
	}
	else {				//�ݽð����
		isOn = (toms[t] & (1 << 7));		//toms�� 7���� ��Ʈ�� true���� false���� Ȯ��
		toms[t] = toms[t] << 1;
		if (isOn) {
			toms[t] = toms[t] - (1<<8) + 1;		//8��° ��Ʈ�� ���� ù ��Ʈ�� Ų��.
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	char temp;
	for (int i = 0; i < 4; i++) {			//�������� ����
		int tempNum = 0;
		for (int k = 0; k < 8; k++) {
			cin >> temp;
			if (temp == '1') {
				tempNum = tempNum + (1 << (7-k));
			}
		}
		toms[i] = tempNum;
	}

	cin >> n;

	int st, dir;
	for (int i = 0; i < n; i++) {
		cin >> st >> dir;
		fill(&visited[0], &visited[0] + 5, 0);
		turn(st - 1, dir);

		//�Ʒ��� ���
		/*cout <<  i << "'s toms\n";
		for (int j : toms) {
			for (int k = 0; k < 8; k++) {
				if (j & (1 << 7 - k)) {
					cout << 1;
				}
				else {
					cout << 0;
				}
			}
			cout << "\n";
		}
		cout << "\n";*/
	}

	int result = 0;
	for (int i = 0; i < 4; i++) {
		if (toms[i] & (1 << 7)) {
			result = result + (1 << i);
		}
	}

	cout <<  result;
}