#include<cstdio>
int main() {
	char cur[9], start[9];
	scanf("%s%s", cur, start);
	int curNum = ((cur[0] - '0') * 10 + (cur[1] - '0')) * 3600 + ((cur[3] - '0') * 10 + (cur[4] - '0')) * 60 + ((cur[6] - '0') * 10 + cur[7] - '0');
	int startNum = ((start[0] - '0') * 10 + (start[1] - '0')) * 3600 + ((start[3] - '0') * 10 + (start[4] - '0')) * 60 + ((start[6] - '0') * 10 + start[7] - '0');
	int remain = curNum > startNum ? 86400 + startNum - curNum : startNum - curNum;
	printf("%02d:", remain / 3600);
	remain %= 3600;
	printf("%02d:", remain / 60);
	remain %= 60;
	printf("%02d", remain);
}