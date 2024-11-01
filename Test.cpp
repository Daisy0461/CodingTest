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
            result.push_back(ch);               //s�� �ִ� ��Ҹ� ������� deque�� �ִ´�.

            if (result.size() >= tntSize) {
                  bool match = true;
                  for (int i = 0; i < tntSize; ++i) {                   //���� ���ڿ� ũ�⸸ŭ ������.
                        if (result[result.size() - tntSize + i] != tnt[i]) {        //result[result�� ��ü ������ - ���� ���ڿ� + i] != tnt[i] -> ��, ��߹��ڿ��� ������� ���ϴ� ���̴�. ������ erase�� ������ ���.
                              match = false;
                              break;
                        }
                  }

                  if (match) {            //�������ڿ��� �����ϴٸ�
                        for (int i = 0; i < tntSize; ++i) {
                              result.pop_back();            //�ش� ������ŭ deque���� ����.
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