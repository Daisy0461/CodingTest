#include <bits/stdc++.h>

using namespace std;

int main()
{
      ios_base::sync_with_stdio(0);
      cin.tie(0); cout.tie(0);

      string s, tnt;
      cin >> s >> tnt;

      deque<char> result;
      int tntSize = tnt.size();

      for (char ch : s) {
            result.push_back(ch);               //s에 있는 요소를 순서대로 deque에 넣는다.

            if (result.size() >= tntSize) {
                  bool match = true;
                  for (int i = 0; i < tntSize; ++i) {                   //폭발 문자열 크기만큼 돌린다.
                        if (result[result.size() - tntSize + i] != tnt[i]) {        //result[result의 전체 사이즈 - 폭발 문자열 + i] != tnt[i] -> 즉, 목발문자열의 순서대로 비교하는 것이다. 강의의 erase와 동일한 방법.
                              match = false;
                              break;
                        }
                  }

                  if (match) {            //폭발윤자열과 동일하다면
                        for (int i = 0; i < tntSize; ++i) {
                              result.pop_back();            //해당 개수만큼 deque에서 뺀다.
                        }
                  }
            }
      }

      if (result.empty()) {
            cout << "FRULA";
      }
      else {
            for (char ch : result) {
                  cout << ch;
            }
      }

      return 0;
}