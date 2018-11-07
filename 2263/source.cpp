#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> inorder, postorder;

void printPreOrder(int iob, int ioe, int pob, int poe) {
	const int N = ioe - iob;
	if (!N) return;
	const int root = postorder[poe - 1];
	const int L = find(inorder.begin() + iob, inorder.begin() + ioe, root) - (inorder.begin() + iob);
	printf("%d ", root);
	printPreOrder(iob, iob + L, pob, pob + L);
	printPreOrder(iob + L + 1, iob + N, pob + L, pob + N - 1);
}

int main() {
	int n;
	scanf("%d", &n);
	inorder.resize(n);
	postorder.resize(n);
	for (int i = 0; i != n; ++i) scanf("%d", &inorder[i]);
	for (int i = 0; i != n; ++i) scanf("%d", &postorder[i]);
	printPreOrder(0, n, 0, n);
}