#include <bits/stdc++.h>

using namespace std;

int toms[4];
int visited[5];
int n;		//회전 횟수

void turn(int t, int dir) {		//toms[t]번째 톱니가 돌아가고 dir 방향으로 돌아간다.
	//체크해야하는 비트 자리는 1 왼쪽(위), 5 오른쪽(아래)
	visited[t] = 1;			//다시 도는 걸 방지하기 위해서
	/*cout << "in t : " << t << "  dir : ";
	if (dir == 1) {
		cout << "시계\n";
	}
	else {
		cout << "반시계\n";
	}*/
	if (t+1 < 4 && !visited[t + 1]) {		//t+1이 범위 안이다. 그리고 t번째의 톱니의 오른쪽과 t+1번째의 톱니의 비트가 동일하다. -> t와 t의 오른쪽이 같다.
		//무조건 다르게 나오네 앞은 100000고 뒤는 10이니까 당연히 다르게 나오지 수정해야함.
		int t1 = toms[t] & (1 << 5);
		int t2 = toms[t + 1] & (1 << 1);
		t1 = t1 >> 4;

		//cout << "t+1 -> " << "t's 5번 bit : " << t1/2 << "   t2's 1번 bit : " << t2/2 << "\n";

		if (t1 != t2) {
			turn(t + 1, dir * -1);
		}
	}

	if (t - 1 >= 0 && !visited[t - 1]) {		//t-1이 범위 안이다. 그리고 t번째의 톱니 왼쪽과 t-1번째의 오른쪽의 비트가 동일하다.
		int t1 = toms[t] & (1 << 1);
		int t2 = toms[t - 1] & (1 << 5);
		t2 = t2 >> 4;

		//cout << "t-1 -> " << "t's 1번 bit : " << t1/2 << "   t2's 5번 bit : " << t2/2 << "\n";

		if ( t1 != t2) {
			turn(t - 1, dir * -1);
		}
	}

	bool isOn;
	if (dir == 1) {		//시계방향
		isOn = (toms[t] & (1 << 0));		//0번째 비트가 켜져있으면 true 아니면 false가 들어간다.
		toms[t] = toms[t] >> 1;
		if (isOn) {
			toms[t] = toms[t] + (1 << 7);		//7번째 비트를 킨다.
		}
	}
	else {				//반시계방향
		isOn = (toms[t] & (1 << 7));		//toms의 7번쨰 비트가 true인지 false인지 확인
		toms[t] = toms[t] << 1;
		if (isOn) {
			toms[t] = toms[t] - (1<<8) + 1;		//8번째 비트를 끄고 첫 비트를 킨다.
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	char temp;
	for (int i = 0; i < 4; i++) {			//이진수로 저장
		int tempNum = 0;
		for (int k = 0; k < 8; k++) {
			cin >> temp;
			if (temp == '1') {
				tempNum = tempNum + (1 << (7-k));
			}
		}
		toms[i] = tempNum;
	}

	cin >> n;

	int st, dir;
	for (int i = 0; i < n; i++) {
		cin >> st >> dir;
		fill(&visited[0], &visited[0] + 5, 0);
		turn(st - 1, dir);

		//아래는 출력
		/*cout <<  i << "'s toms\n";
		for (int j : toms) {
			for (int k = 0; k < 8; k++) {
				if (j & (1 << 7 - k)) {
					cout << 1;
				}
				else {
					cout << 0;
				}
			}
			cout << "\n";
		}
		cout << "\n";*/
	}

	int result = 0;
	for (int i = 0; i < 4; i++) {
		if (toms[i] & (1 << 7)) {
			result = result + (1 << i);
		}
	}

	cout <<  result;
}