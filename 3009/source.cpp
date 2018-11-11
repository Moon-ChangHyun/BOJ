#include<cstdio>
#include<set>
using namespace std;
int main() {
	set<int> xp, yp;
	int retX, retY;
	for (int i = 0; i != 3; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		auto pair = xp.insert(x);
		if (!pair.second)
			xp.erase(pair.first);
		pair = yp.insert(y);
		if (!pair.second)
			yp.erase(pair.first);
	}
	printf("%d %d", *xp.begin(), *yp.begin());
}