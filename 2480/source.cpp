#include<cstdio>
#include<algorithm>
#include<array>
using namespace std;
int main() {
	array<int, 3> a;
	for (int i = 0; i != 3; ++i) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	if (a[0] == a[2]) printf("%d", 10000 + a[0] * 1000);
	else  if (a[0] == a[1] || a[1] == a[2]) printf("%d", 1000 + a[1] * 100);
	else printf("%d", a[2] * 100);
}