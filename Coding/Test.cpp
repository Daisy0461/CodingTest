#include <bits/stdc++.h>

using namespace std;

int n;	//ÇÐ»ý ¼ö
priority_queue<float, vector<float>, greater<float>> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	float score;
	for (int i = 0; i < n; i++) {
		cin >> score;
		pq.push(score);
	}

	for (int i = 0; i < 5; i++) {
		cout << pq.top() << "\n";
		pq.pop();
	}
}