// 24ms, 10108KB

#include<iostream>
#include<vector>
#include<limits>
using namespace std;

class RMQ {
private:
	static const int intMax = numeric_limits<int>::max();
	int n;
	vector<int> rangeMin;
	int init(const vector<int>& arr, int left, int right, int node) {
		if (left == right) {
			rangeMin[node] = arr[left];
			return rangeMin[node];
		}
		int mid = (left + right) >> 1;
		int leftMin = init(arr, left, mid, node << 1);
		int rightMin = init(arr, mid + 1, right, (node << 1) + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}
	int _query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || left > nodeRight)
			return intMax;
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];
		int mid = (nodeLeft + nodeRight) >> 1;
		int leftMin = _query(left, right, node << 1, nodeLeft, mid);
		int rightMin = _query(left, right, (node << 1) + 1, mid + 1, nodeRight);
		return min(leftMin, rightMin);
	}
public:
	RMQ(const vector<int>& arr) {
		n = arr.size();
		rangeMin.resize(n * 4);
		init(arr, 0, n - 1, 1);
	}
	int query(int left, int right) {
		return _query(left, right, 1, 0, n - 1);
	}
};

constexpr int MAX_N = 40000;
int nextSerial = 1;
vector<vector<pair<int, int>>> adj;
int noToSerial[MAX_N + 1], serialToNo[MAX_N + 1];
int firstLocInTrip[MAX_N + 1], rootLength[MAX_N + 1];

void dfs(int here, int distance, vector<int>& trip)
{
	noToSerial[here] = nextSerial;
	serialToNo[nextSerial] = here;
	rootLength[here] = distance;
	firstLocInTrip[here] = trip.size();
	trip.push_back(nextSerial++);
	for (auto& child : adj[here])
	{
		if (noToSerial[child.first] > 0) continue;
		dfs(child.first, distance + child.second, trip);
		trip.push_back(noToSerial[here]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N;
	adj.resize(N + 1);
	for (int i = 1; i < N; ++i) {
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].emplace_back(v, d);
		adj[v].emplace_back(u, d);
	}
	vector<int> trip;
	trip.reserve(2 * N - 1);
	dfs(1, 0, trip);
	RMQ rmq(trip);

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		int lu = firstLocInTrip[u], lv = firstLocInTrip[v];
		if (lu > lv) swap(lu, lv);
		int lca = serialToNo[rmq.query(lu, lv)];
		cout << rootLength[u] + rootLength[v] - 2 * rootLength[lca] << '\n';
	}
}