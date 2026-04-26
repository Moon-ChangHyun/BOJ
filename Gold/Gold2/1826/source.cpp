// 4ms, 1404KB

#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N, L, P, prev = 0, cnt = 0;
	scanf("%d", &N);
	vector<pair<int, int>> stops(N);
	for (int i = 0; i != N; ++i) {
		scanf("%d%d", &stops[i].first, &stops[i].second);
	}
	sort(stops.begin(), stops.end());
	scanf("%d%d", &L, &P);
	auto it = lower_bound(stops.begin(), stops.end(), pair<int, int>{ L, 0 });
	stops.erase(it, stops.end());
	stops.push_back({ L, 0 });
	priority_queue<int> fuels;
	for (auto& stop : stops) {
		int dist = stop.first - prev;
		if (P < dist) {
			while (!fuels.empty()) {
				P += fuels.top();
				fuels.pop();
				++cnt;
				if (P >= dist)
					break;
			}
			if (P < dist) {
				printf("-1");
				return 0;
			}
		}
		P -= dist;
		prev = stop.first;
		fuels.push(stop.second);
	}
	printf("%d", cnt);
}