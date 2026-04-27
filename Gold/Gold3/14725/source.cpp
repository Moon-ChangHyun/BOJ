// 0ms, 2156KB

#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

struct node {
	string name;
	int depth;
	mutable set<node> child;
	node(const string& inName, int inDepth) : name(inName), depth(inDepth) {	
	}
	friend bool operator< (const node& lhs, const node& rhs) {
		return lhs.name < rhs.name;
	}
	friend bool operator== (const node& lhs, const node& rhs) {
		return lhs.name == rhs.name;
	}
	void print() const {
		for (int i = 0; i < depth; ++i) {
			cout << "--";
		}
		cout << name << "\n";
		for (auto& c : child) {
			c.print();
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	node root(""s, -1);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int M;
		const node* cur = &root;
		cin >> M;
		for (int j = 0; j < M; ++j) {
			string str;
			cin >> str;
			auto result = cur->child.insert(node{ str, cur->depth + 1 });
			cur = &*result.first;
		}
	}
	for (auto& c : root.child) {
		c.print();
	}
}