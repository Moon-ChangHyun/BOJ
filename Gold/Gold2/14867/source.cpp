// 8ms, 1232KB

#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
    if(c != 0 && c != a && d != 0 && d != b) {
        printf("-1");
        return 0;
    }
	vector<bool> dcAwithBz(a + 1), dcBwithAz(b + 1), dcAwithBf(a + 1), dcBwithAf(b + 1);
	queue<int> qA, qB, qD;
	qA.push(0);
	qB.push(0);
	qD.push(0);
	dcAwithBz[0] = dcBwithAz[0] = true;
	while(!qA.empty()) {
		int fa = qA.front();
		int fb = qB.front();
		int depth = qD.front();
		if(fa == c && fb == d) {
			printf("%d", depth);
			return 0;
		}
		qA.pop();
		qB.pop();
		qD.pop();
		if(!dcBwithAf[fb]) {
			qA.push(a);
			qB.push(fb);
			qD.push(depth + 1);
			dcBwithAf[fb] = true;
		}
		if(!dcAwithBf[fa]) {
			qA.push(fa);
			qB.push(b);
			qD.push(depth + 1);
			dcAwithBf[fa] = true;
		}
		if(!dcBwithAz[fb]) {
			qA.push(0);
			qB.push(fb);
			qD.push(depth + 1);
			dcBwithAz[fb] = true;
		}
		if(!dcAwithBz[fa]) {
			qA.push(fa);
			qB.push(0);
			qD.push(depth + 1);
			dcAwithBz[fa] = true;
		}
		if(fa + fb > a) {
			if(!dcBwithAf[fa + fb - a]) {
				qA.push(a);
				qB.push(fa + fb - a);
				qD.push(depth + 1);
				dcBwithAf[fa + fb - a] = true;
			}
		}
		else {
			if(!dcAwithBz[fa + fb]) {
				qA.push(fa + fb);
				qB.push(0);
				qD.push(depth + 1);
				dcAwithBz[fa + fb] = true;
			}
		}
		if(fa + fb > b) {
			if(!dcAwithBf[fa + fb - b]) {
				qA.push(fa + fb - b);
				qB.push(b);
				qD.push(depth + 1);
				dcAwithBf[fa + fb - b] = true;
			}
		}
		else {
			if(!dcBwithAz[fa + fb]) {
				qA.push(0);
				qB.push(fa + fb);
				qD.push(depth + 1);
				dcBwithAz[fa + fb] = true;
			}
		}
	}
	printf("-1");
}