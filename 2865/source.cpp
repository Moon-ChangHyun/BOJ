#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	vector<priority_queue<double>> score;
	vector<double> passed;
	score.resize(N + 1);
	passed.reserve(N);
	for (int i = 0; i != M; ++i) {
		for (int j = 0; j != N; ++j) {
			int num;
			double sc;
			scanf("%d%lf", &num, &sc);
			score[num].push(sc);
		}
	}
	for (int i = 1; i <= N; ++i)
		passed.push_back(score[i].top());
	sort(passed.begin(), passed.end(), greater<>());
	double ret = 0;
	for (int i = 0; i != K; ++i)
		ret += passed[i];
	printf("%.1f", ret);
}