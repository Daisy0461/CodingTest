#include <bits/stdc++.h>

using namespace std;

int n;			//�����ϴ� ȸ���� ��
int result = 0;
vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	int s, e;		//ȸ���� ���۽ð�.		�����̰��� -���� ���� 100,000
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		v.push_back({ e, s });
	}

	sort(v.begin(), v.end());

	int e1 = v[0].first;				//v[0]�� end�� ���� ���� ��ġ�̴�.	
	result++;
	for (int i = 1; i < n; i++) {
		if (v[i].second >= e1) {			//���� ����� ���۽ð��� ������ ������ �ð����� ũ�ų� ����. 
			e1 = v[i].first;					//������ �ð��� ���� ������ �����߱� ������ ���� �̰� ���� �������� ���� ����̴�.
			result++;
		}
	}

	cout << result;
}