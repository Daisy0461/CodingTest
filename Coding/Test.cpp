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

      int point = 0;  // 시작 포인터
      for (int i = 0; i < n; i++) {
            while (visited[v[i]]) {  // 중복이 발생하면 point 이동
                  visited[v[point]] = 0;  // point 요소의 방문 여부를 해제
                  point++;
             }

            visited[v[i]] = 1;  // 현재 요소 방문 처리

            // i - point + 1은 point부터 i까지의 중복 없는 부분 수열의 개수
            result += (i - point + 1);
      }

      cout << result;
}

//5 1 2 3 2 1