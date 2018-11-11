#include<cstdio>

int H, W, remain;
int map[100][100];

int findDFS(int y, int x) {
	if (y < 0 || x < 0 || y >= H || x >= W || map[y][x] == -1)
		return 0;
	if (map[y][x] == 1) {
		map[y][x] = -1;
		return 1;
	}
	map[y][x] = -1;
	int ret = 0;
	ret += findDFS(y - 1, x);
	ret += findDFS(y, x - 1);
	ret += findDFS(y + 1, x);
	ret += findDFS(y, x + 1);
	return ret;
}

int main() {

	int time = 0;
	scanf("%d%d", &H, &W);
	for (int i = 0; i != H; ++i)
		for (int j = 0; j != W; ++j) {
			scanf("%d", &map[i][j]);
			remain += (map[i][j] == 1);
		}
	while (remain) {
		++time;
		int found = findDFS(0, 0);
		if (found == remain) break;
		remain -= found;
		for (int i = 0; i != H; ++i)
			for (int j = 0; j != W; ++j)
				if (map[i][j] == -1)
					map[i][j] = 0;
	}
	printf("%d\n%d", time, remain);
}