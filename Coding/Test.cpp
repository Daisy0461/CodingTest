#include<bits/stdc++.h>

using namespace std;

const int dy[] = { 0,1,0,-1 };
const int dx[] = { 1,0,-1,0 };
int n, m, k, a[104][104], temp[104][104], visited[104][104], sy, sx, ey, ex, r, c, s, direction, result = 99999999;
vector<pair<int, int>> v;
vector<int> v_idx;
vector<tuple<int, int, int>> rotateV;

void directionChange(int y, int x, int first)
{
      if (!first && y == sy && x == sx)    direction++;
      if (!first && y == sy && x == ex)    direction++;
      if (!first && y == ey && x == ex)    direction++;
      if (!first && y == ey && x == sx)    direction++;

      int ny = y + dy[direction];
      int nx = x + dx[direction];
      if (visited[ny][nx]) return;
      visited[ny][nx] = 1;
      v.push_back({ ny,nx });
      directionChange(ny, nx, 0);
}

void rotateAll(int y, int x, int cnt)
{
      for (int i = 1; i <= cnt; i++)
      {
            sy = y - 1 * i;
            sx = x - 1 * i;
            ey = y + 1 * i;
            ex = x + 1 * i;
            v.clear();
            direction = 0;
            memset(visited, 0, sizeof(visited));
            visited[sy][sx] = 1;
            v.push_back({ sy,sx }); // 돌려야 할 것 뽑아내기
            directionChange(sy, sx, 1);

            vector<int> v2;
            for (pair<int, int> c : v)
            {
                  v2.push_back(temp[c.first][c.second]);
            }
            rotate(v2.rbegin(), v2.rbegin() + 1, v2.rend());
            for (int i = 0; i < v.size(); i++)
            {
                  temp[v[i].first][v[i].second] = v2[i];
            }
      }
}

int min_rowSum()
{
      for (int i : v_idx)
      {
            rotateAll(get<0>(rotateV[i]), get<1>(rotateV[i]), get<2>(rotateV[i]));
      }
      int tempResult = 99999999;
      for (int i = 0; i < n; i++)
      {
            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                  cnt += temp[i][j];
            }
            tempResult = min(tempResult, cnt);
      }
      return tempResult;
}

int main()
{
      cin >> n >> m >> k;

      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < m; j++)
            {
                  cin >> a[i][j];
            }
      }

      for (int i = 0; i < k; i++)
      {
            cin >> r >> c >> s;
            r--; // 0부터 시작하려고 뺌
            c--;
            rotateV.push_back({ r,c,s });
            v_idx.push_back(i);
      }
      do
      {
            memcpy(temp, a, sizeof(temp));
            result = min(result, min_rowSum());

      } while (next_permutation(v_idx.begin(), v_idx.end()));

      cout << result;

      return 0;
}
