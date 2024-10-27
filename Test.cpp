#include <bits/stdc++.h>

using namespace std;

//상태가 2가지라고 생각할 수도 있겠다.
//0은 세로로 잘리는 상태, 1은 가로로 잘리는 상태.

int n, m;		//n과 m의 최댓값은 4이다.
vector<vector<char>> v;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	char c;
	for (int i = 0; i < n; i++) {			//v에 입력된 값 넣기
		for (int j = 0; j < m; j++) {
			cin >> c;
			v[i].push_back(c);
		}
	}

	for (int i = 0; i < (n * m); i++) {

	}
}