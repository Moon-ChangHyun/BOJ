// 156ms, 9408KB

#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

vector<vector<bool>> isWarp; //[y][x]
int dy[4] = { -1, 0, 1, 0 };//북동남서
int dx[4] = { 0, 1, 0, -1 };
int N;

int getNearestWarp(int node, int dir) {
	int y = node / N, x = node % N;
	while (true) {
		y += dy[dir], x += dx[dir];
		if (y < 0 || x < 0 || y >= N || x >= N)
			return -1;
		if (isWarp[y][x])
			return y * N + x;
	}
}

int main() {
	int transDelay, dstY, dstX, dstNode;
	scanf("%d%d%d%d", &N, &transDelay, &dstY, &dstX);
	--dstY, --dstX;
	dstNode = dstY * N + dstX;
	isWarp.resize(N, vector<bool>(N));
	for (int i = 0; i != N; ++i) {
		for (int j = 0; j != N; ++j) {
			char c;
			scanf(" %c", &c);
			isWarp[i][j] = (c == '#');
		}
	}
	vector<vector<int>> dist(2, vector<int>(N * N, 987654321)); //변신, 노드
	priority_queue<pair<int, pair<bool, int>>> pq; //-비용, 변신, 노드
	pq.push({ 0, { false, 0 } });
	dist[0][0] = 0;
	while (true) {
		int node = pq.top().second.second, cost = -pq.top().first;
		bool trans = pq.top().second.first;
		pq.pop();
		if (node == dstNode) break;
		if (dist[trans][node] < cost) continue;
		vector<pair<int, pair<bool, int>>> nextNodes; //비용, 변신, 노드
		if (trans) {
			for (int dir = 0; dir != 4; ++dir) {
				int next = getNearestWarp(node, dir);
				if(next != -1)
					nextNodes.push_back({ 1, { true, next } });
			}
			nextNodes.push_back({ 0, {false, node} });
		}
		else {
			for (int dir = 0; dir != 4; ++dir) {
				int y = node / N, x = node % N;
				int nY = y + dy[dir], nX = x + dx[dir];
				if (nY >= 0 && nY < N && nX >= 0 && nX < N)
					nextNodes.push_back({ 1, {false, nY * N + nX} });
			}
			nextNodes.push_back({ transDelay, {true, node} });
		}
		for (auto& next : nextNodes) {
			bool nextTrans = next.second.first;
			int nextNode = next.second.second, nextCost = cost + next.first;
			if (nextCost < dist[nextTrans][nextNode]) {
				dist[nextTrans][nextNode] = nextCost;
				pq.push({ -nextCost, {nextTrans, nextNode} });
			}
		}
	}
	printf("%d", min(dist[0][dstNode], dist[1][dstNode]));
}