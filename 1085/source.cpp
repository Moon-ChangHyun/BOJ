#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int x, y, w, h;
	scanf("%d%d%d%d", &x, &y, &w, &h);
	printf("%d", min(min(y, h - y), min(x, w - x)));
}