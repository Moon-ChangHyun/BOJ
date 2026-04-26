// 880ms, 193504KB

#include<iostream>
#include<set>

using namespace std;

bool nums[4'000'001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;
	set<int> st;

	for (int i = 0; i < M; ++i) {
		int x;
		cin >> x;
		nums[x] = true;
	}

	auto hint = st.cbegin();
	for (int i = 1; i <= N; ++i) {
		if (nums[i]) {
			st.emplace_hint(hint, i);
			hint = st.cend();
		}
	}

	for (int i = 0; i < K; ++i) {
		int x;
		cin >> x;
		auto target = st.upper_bound(x);
		cout << *target << '\n';
		st.erase(target);
	}
}