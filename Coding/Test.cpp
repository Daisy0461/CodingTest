#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int visited[100001];
vector<int> v;
ll result=0;

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0); cout.tie(0);

      cin >> n;

      int temp;
      for (int i = 0; i < n; i++) {
            cin >> temp;
            v.push_back(temp);
      }

      int point = 0;  // ���� ������
      for (int i = 0; i < n; i++) {
            while (visited[v[i]]) {  // �ߺ��� �߻��ϸ� point �̵�
                  visited[v[point]] = 0;  // point ����� �湮 ���θ� ����
                  point++;
             }

            visited[v[i]] = 1;  // ���� ��� �湮 ó��

            // i - point + 1�� point���� i������ �ߺ� ���� �κ� ������ ����
            result += (i - point + 1);
      }

      cout << result;
}

//5 1 2 3 2 1