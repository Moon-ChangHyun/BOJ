#include<cstdio>
#include<vector>
using namespace std;
int main() {
	int S1, S2, S3, ret = 0;
	scanf("%d%d%d", &S1, &S2, &S3);
	vector<int> cnt(S1 + S2 + S3 + 1, 0);
	for (int i = 1; i <= S1; ++i)
		for (int j = 1; j <= S2; ++j)
			for (int k = 1; k <= S3; ++k)
				++cnt[i + j + k];
	for (int i = 3; i != cnt.size(); ++i)
		if (cnt[ret] < cnt[i]) ret = i;
	printf("%d", ret);
}