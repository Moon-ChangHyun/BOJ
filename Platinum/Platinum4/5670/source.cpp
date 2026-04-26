// 600ms, 75536KB

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int sum;

struct TrieNode {
	TrieNode* children[26];
	char subTreeCnt;
	bool isTerminal;
	TrieNode() : isTerminal(false), subTreeCnt(0) { 
		for (int i = 0; i < 26; ++i)
			children[i] = nullptr;
	}
	~TrieNode() {
		for (int i = 0; i < 26; ++i)
			if (children[i] != nullptr)
				delete children[i];
	}
	void insert(const char* key) {
		if (*key == 0)
			isTerminal = true;
		else {
			int idx = *key - 'a';
			if (children[idx] == nullptr) {
				children[idx] = new TrieNode();
				++subTreeCnt;
			}
			children[idx]->insert(key + 1);
		}
	}
	void accumCnt(int cnt) {
		if (isTerminal)
			sum += cnt;
		if (subTreeCnt == 0) return;
		if (isTerminal || subTreeCnt > 1)
			++cnt;
		for (int i = 0; i < 26; ++i) {
			if (children[i] == nullptr) continue;
			children[i]->accumCnt(cnt);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cout << setprecision(2) << fixed;
	while (cin >> N) {
		TrieNode* root = new TrieNode();
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			root->insert(s.c_str());
		}
		sum = 0;
		for (int i = 0; i < 26; ++i) {
			if (root->children[i] != nullptr)
				root->children[i]->accumCnt(1);
		}
		double ans = (double)sum / N;
		
		cout << ans << '\n';
		delete root;
	}
}