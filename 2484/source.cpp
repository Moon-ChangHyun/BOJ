#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int N, ret = 0, dice[4];
	for (scanf("%d", &N); ~--N; ) {
		for (int i = 0; i != 4; ++i)
			scanf("%d", dice + i);
		sort(dice, dice + 4);
		if (dice[0] == dice[3])
			ret = max(ret, 50000 + dice[0] * 5000);
		else if (dice[0] == dice[2] || dice[1] == dice[3])
			ret = max(ret, 10000 + dice[1] * 1000);
		else if (dice[0] == dice[1] && dice[2] == dice[3])
			ret = max(ret, 2000 + 500 * (dice[1] + dice[2]));
		else if (dice[0] == dice[1] || dice[1] == dice[2])
			ret = max(ret, 1000 + 100 * dice[1]);
		else if (dice[2] == dice[3])
			ret = max(ret, 1000 + 100 * dice[2]);
		else
			ret = max(ret, 100 * dice[3]);
	}
	printf("%d", ret);
}