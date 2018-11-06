#include<cstdio>
#include<vector>
#include<memory>
using namespace std;

struct node;
vector<int> visit;
vector<shared_ptr<node>> tree;
int del;

struct node {
	int parent;
	vector<int> child;
	int terminalNum;
	int getLeafNode() {
		if (child.size() == 0)
			return terminalNum = 1;
		terminalNum = 0;
		for (auto cd : child)
			if (cd != del)
				terminalNum += tree[cd]->getLeafNode();
		return (terminalNum ? terminalNum : 1);
	}
};

int main() {
	int n, root;
	scanf("%d", &n);
	for (int i = 0; i != n; ++i)
		tree.push_back(shared_ptr<node>(new node()));
	for (int i = 0; i != n; ++i) {
		int p;
		scanf("%d", &p);
		tree[i]->parent = p;
		if (p == -1) {
			root = i;
			continue;
		}
		tree[p]->child.push_back(i);
	}
	scanf("%d", &del);
	if (root == del) printf("0");
	else printf("%d", tree[root]->getLeafNode());
}