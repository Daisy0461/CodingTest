#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;		//n = ��ǰ ��, k = ���� ��
ll result = 0;
vector < pair < ll, ll >> stufs;
vector<int> bags;
priority_queue <ll> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	ll m, v;
	for (int i = 0; i < n; i++) {
		cin >> m >> v;					//���� ,����
		stufs.push_back({ m, v });
	}

	int c;
	for (int i = 0; i < k; i++) {
		cin >> c;
		bags.push_back(c);
	}

	sort(stufs.begin(), stufs.end());			//���԰� ���� ������ ���ĵȴ�.
	sort(bags.begin(), bags.end());				//���� �� �ִ� ���԰� ���� ������ ���浵 ���ĵȴ�

	int stufsIndex = 0;
	for (int i = 0; i < k; i++) {			//���� �� �ִ� ���԰� ���� ������ ���������� ���鼭 �˻��Ѵ�.
		while (stufsIndex < n && bags[i] >= stufs[stufsIndex].first) {	//������ ����� �����鼭 bag[i]�� stufs[stufsIndex]�� ���Ը� ���� �� ���� �� ��� ������.
			pq.push(stufs[stufsIndex].second);		//��ġ�� �ִ� ���̱� ������ ���ݸ� pq�� ���Ѵ�. -> pq�� �ϴ� ���� : top�� ���� ��ҰŴϱ�.
			stufsIndex++;
		}
		//���� ���濡 ���� �� �ִ� ���� �� pq�� �־���.
		//���Ŀ� ������ ���� ���溸�� �� ���ſ� ���� ���� �� �����Ƿ� pq�� �����Ѵ�. �ֳĸ� �̹� �� ���� ���濡�� ���� �� �ֱ� �����̴�.
		
		if (pq.size()) {
			result += pq.top();
			pq.pop();
		}
	}

	cout << result;


}