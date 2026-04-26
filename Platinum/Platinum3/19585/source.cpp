// 2312ms, 1000216KB

#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> matchIdx;

struct TrieNode {
	map<char, TrieNode*> children;
	bool isTerminal;
	TrieNode() : isTerminal(false) { 
	}
	~TrieNode() {
		for (auto& child : children)
			delete child.second;
	}
	void insert(const char* key) {
		if (*key == 0)
			isTerminal = true;
		else {
			auto& child = children[*key];
			if (child == nullptr)
				child = new TrieNode();
			child->insert(key + 1);
		}
	}
	void colorCheck(const char* key, int depth) {
		if (isTerminal)
			matchIdx.push_back(depth);
		auto iter = children.find(*key);
		if (iter == children.end()) return;
		iter->second->colorCheck(key + 1, depth + 1);
	}
	bool nicknameCheck(const char* key) {
		if (*key == 0)
			return isTerminal;
		auto iter = children.find(*key);
		if (iter == children.end()) return false;
		return iter->second->nicknameCheck(key + 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C, N, Q, maxLenNick = 0;
	char str[2001];
	string s;
	s.reserve(2001);
	matchIdx.reserve(1001);
	cin >> C >> N;
	TrieNode* colorTrieRoot = new TrieNode();
	TrieNode* nickNameTrieRoot = new TrieNode();
	for (int i = 0; i < C; ++i) {
		cin >> s;
		colorTrieRoot->insert(s.c_str());
	}
	for (int i = 0; i < N; ++i) {
		cin >> s;
		nickNameTrieRoot->insert(s.c_str());
		maxLenNick = maxLenNick > s.size() ? maxLenNick : s.size();
	}

	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		cin >> s;
		matchIdx.clear();
		colorTrieRoot->colorCheck(s.c_str(), 0);
		bool ans = false;
		for (auto idx : matchIdx) {
			if (idx + maxLenNick < s.size()) continue;
			if (nickNameTrieRoot->nicknameCheck(s.c_str() + idx)) {
				ans = true;
				break;
			}
		}
		cout << (ans ? "Yes\n" : "No\n");
	}
}