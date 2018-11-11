#include<cstdio>
#include<string>
using namespace std;
int main() {
	string arr[7] = { "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday" };
	int daySum[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int D, M;
	scanf("%d%d", &D, &M);
	int day = daySum[M - 1] + D;
	printf("%s", arr[day % 7].data());
}