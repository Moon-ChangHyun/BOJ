#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
	int rows, cols;
	scanf("%d%d", &rows, &cols);
	vector<vector<bool>> map(rows, vector<bool>(cols));
	for (int i = 0; i != rows; ++i) {
		for (int j = 0; j != cols; ++j) {
			char c;
			scanf(" %c", &c);
			map[i][j] = (c == 'L');
		}
	}
	int ret = 0;
	int size = rows * cols;
	for (int node = 0; node < size; ++node) {
		vector<int> dist(size, -1);
		queue<int> q;
		q.push(node);
		dist[node] = 0;
		while (!q.empty()) {
			int num = q.front(); q.pop();
			ret = max(ret, dist[num]);
			int y = num / cols;
			int x = num % cols;
			if (map[y][x]) {
				if (y && map[y - 1][x] && dist[num - cols] == -1) {
					q.push(num - cols);
					dist[num - cols] = dist[num] + 1;
				}
				if (x && map[y][x - 1] && dist[num - 1] == -1) {
					q.push(num - 1);
					dist[num - 1] = dist[num] + 1;
				}
				if (y < rows - 1 && map[y + 1][x] && dist[num + cols] == -1) {
					q.push(num + cols);
					dist[num + cols] = dist[num] + 1;
				}
				if (x < cols - 1 && map[y][x + 1] && dist[num + 1] == -1) {
					q.push(num + 1);
					dist[num + 1] = dist[num] + 1;
				}
			}
		}
	}
	printf("%d", ret);
}