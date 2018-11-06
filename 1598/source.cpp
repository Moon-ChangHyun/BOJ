#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int ay = (a - 1) / 4;
	int ax = (a - 1) % 4;
	int by = (b - 1) / 4;
	int bx = (b - 1) % 4;
	printf("%d", (int)(abs(ay - by) + abs(ax - bx)));
}