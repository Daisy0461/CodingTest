#include <bits/stdc++.h>

using namespace std;

int ps;		//손님이 구매하고자 하는 피자 사이즈
int pa, pb;	//a, b 피자의 총 조각 개수 3 <= pa, pb <= 1000 피자 조각의 크기는 시계방향으로 주어진다.
int result = 0;
int minB = 987654321, minBIndex = 0;		//B피자에서 가장 작은 조각의 Index이다.
vector<int> a;
vector<int> b;

void findPizza(int aIndex, int aPizzaSize)
{
	//만들어야할 사항 -> 현재 Index는 넘지 않게 해야한다.
	if (aPizzaSize == ps) {		//a Pizza만으로 원하는 크기를 만들었다.
		result++;
		return;
	}

	if (aPizzaSize < ps) {		//피자 조각이 더 필요하다.
		int findBSize = ps - aPizzaSize;
		

	}

	if (aPizzaSize > ps) {		//이미 초과한다.
		return;		
	}

}

void findFromB(int findSize)
{
	for (int i = 0; i < b.size(); i++) {		//b의 모든 index를 시작 지점으로 잡아야한다. sort는 못한다.
		if (b[i] == findSize) {				//한 조각 자체가 찾아야하는 크기면 방법의 수를 늘리고 다음 index로 가도록 한다.
			result++;		
			continue;
		}

		int sumSize = b[i];
		int nextIndex = (i + 1) % b.size();
		while (sumSize < findSize) {		//합친 사이즈가 찾아야하는 사이즈보다 작을 때 while문을 돌린다.
			sumSize += b[nextIndex];
			nextIndex = (nextIndex + 1) % b.size();

			if (nextIndex == i) {		//다음 Index가 최초의 Index라면 못 찾았다. 나가라.
				break;
			}
		}

		if (sumSize == findSize) {		//sumSize가 찾는 사이즈다.
			result++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> ps;
	cin >> pa >> pb;	

	//피자 입력
	int temp;
	for (int i = 0; i < pa; i++) {
		cin >> temp;
		a.push_back(temp);
	}
	
	for (int i = 0; i < pb; i++) {
		cin >> temp;
		if (temp < minB) {
			minB = temp;
			minBIndex = i;
		}
		b.push_back(temp);
	}

	for (int i = 0; i < a.size(); i++) {
		findPizza(i, a[i]);
	}

}
