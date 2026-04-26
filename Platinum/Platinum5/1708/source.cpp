#include<iostream>
// 36ms, 2808KB

#include<vector>
#include<stack>
#include<algorithm>

using namespace std;
using ll = long long;
using dot = pair<int, int>;

int ccw(ll ax, ll ay, ll bx, ll by, ll cx, ll cy) {
	ll result = (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
	if (result > 0) return 1;
	else if (result < 0) return -1;
	return 0;
}

ll dist(ll ax, ll ay, ll bx, ll by) {
	ll tmp1 = ax - bx, tmp2 = ay - by;
	return tmp1 * tmp1 + tmp2 * tmp2;
}

int main() {
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<dot> dots(N);
	int datumPoint = 0;
	cin >> dots[0].first >> dots[0].second;
	for (int i = 1; i < N; ++i) {
		cin >> dots[i].first >> dots[i].second;
		if (dots[datumPoint] > dots[i])
			datumPoint = i;
	}
	int crX = dots[datumPoint].first, crY = dots[datumPoint].second;
	for (int i = 0; i < N; ++i) {
		dots[i].first -= crX;
		dots[i].second -= crY;
	}
	dots[datumPoint] = dots[0];
	dots[0] = { 0,0 };
	sort(dots.begin() + 1, dots.end(), [&](const dot& a, const dot& b) {
		if (a.first == 0) {
			if (b.first == 0)
				return a.second < b.second;
			else
				return false;
		}
		if (b.first == 0)
			return true;
		ll result = (ll)b.first * a.second - (ll)a.first * b.second;
		if (result == 0)
			return dist(0, 0, a.first, a.second) < dist(0, 0, b.first, b.second);
		return result < 0;
	});

	stack<dot> st;
	st.push(dots[0]);
	st.push(dots[1]);
	for (int i = 2; i < N; ++i) {
		if (st.size() < 2) {
            cout << "err\nerr";
			break;
		}
		auto dot2 = st.top(); st.pop();
		auto dot1 = st.top();
		switch (ccw(dot1.first, dot1.second, dot2.first, dot2.second, dots[i].first, dots[i].second)) {
		case -1:
			--i;
			break;
		case 0:
			st.push(dots[i]);
			break;
		case 1:
			st.push(dot2);
			st.push(dots[i]);
		}
	}
	cout << st.size();
}