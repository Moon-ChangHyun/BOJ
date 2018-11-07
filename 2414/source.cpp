#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
char map[51][51];
vector<pair<int, pair<int, int>>> aNode, bNode;
vector<vector<int>> adj;
vector<bool> aVisit;
vector<int> bMatch;

bool dfs(int a) {
	if (aVisit[a]) return false;
	aVisit[a] = true;
	for (auto next : adj[a]) {
		if (bMatch[next] == -1 || dfs(bMatch[next])) {
			bMatch[next] = a;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			scanf(" %c", &map[i][j]);
	for (int i = 1; i <= N; ++i) {
		bool con = false;
		int start = 0;
		for (int j = 1; j <= M; ++j) {
			if (con) {
				if (map[i][j] == '.') {
					aNode.push_back({ i, {start, j} });
					con = false;
				}
			}
			else {
				if (map[i][j] == '*') {
					con = true;
					start = j;
				}
			}
		}
		if (con)
			aNode.push_back({ i, {start, M + 1} });
	}
	for (int j = 1; j <= M; ++j) {
		bool con = false;
		int start = 0;
		for (int i = 1; i <= N; ++i) {
			if (con) {
				if (map[i][j] == '.') {
					bNode.push_back({ j, {start, i} });
					con = false;
				}
			}
			else {
				if (map[i][j] == '*') {
					con = true;
					start = i;
				}
			}
		}
		if (con)
			bNode.push_back({ j, {start, N + 1} });
	}
	adj.resize(aNode.size());
	aVisit.resize(aNode.size());
	bMatch.resize(bNode.size(), -1);
	for (int a = 0; a != aNode.size(); ++a) {
		int row = aNode[a].first;
		int colStart = aNode[a].second.first;
		int colEnd = aNode[a].second.second;
		for (int b = 0; b != bNode.size(); ++b) {
			int col = bNode[b].first;
			int rowStart = bNode[b].second.first;
			int rowEnd = bNode[b].second.second;
			if (colStart <= col && col < colEnd && rowStart <= row && row < rowEnd)
				adj[a].push_back(b);
		}
	}
	int ret = 0;
	for (int a = 0; a != aNode.size(); ++a) {
		fill(aVisit.begin(), aVisit.end(), false);
		if (dfs(a)) ++ret;
	}
	printf("%d", ret);
}