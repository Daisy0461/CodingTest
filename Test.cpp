#include <bits/stdc++.h>

using namespace std;

int n, k, result = 0;
int visited[101];
vector<int> v;
vector<int> cv;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	int temp;
	for (int i = 0; i < k; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 0; i < k; i++) {
		if (!visited[v[i]]) {		//v[i]가 현재 콘센트에 없다.
			if (cv.size() == n) {	//현재 콘센트가 꽉 찼다.
				int last_Index = 0; int pos;
				for (int t : cv) {
					int tempIndex = 987654321;
					for (int j = i + 1; j < k; j++) {
						if (v[j] == t) {		//이후에 사용할 리스트(v)에서 현재 꽂혀있는 t와 동일한 것을 찾았다.
							tempIndex = j;		//그 가전제품은 j번째에서 다시 사용한다. 이 사용하는 것은 이후에도 존재할 수 있으나 제일 가까이서 사용하는 것을 찾는다.
							break;
						}
					}

					if (last_Index < tempIndex) {			//지금 찾은 index값이 지금까지 찾았던 Index보다 값이 크다. 즉, 더 이후에 사용한다.
						last_Index = tempIndex;
						pos = t;
					}
				}

				visited[pos] = 0;
				result++;
				cv.erase(find(cv.begin(), cv.end(), pos));
			}

			visited[v[i]] = 1;
			cv.push_back(v[i]);
		}
	}

	cout << result;
}
