// 388ms, 14668KB

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

struct disjointSet {
    vector<int> parent;
    vector<int> rank;
    disjointSet(int inSize) : parent(inSize + 1), rank(inSize + 1, 0) {
        for (int i = 0; i <= inSize; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        if (rank[u] < rank[v]) {
            u ^= v;
            v ^= u;
            u ^= v;
        }
        parent[v] = u;
        if (rank[u] == rank[v])
            ++rank[u];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;

        vector<int> comp;
        comp.reserve(n * 2);
        vector<int> iVec(n), jVec(n), eVec(n);

        for (int k = 0; k < n; ++k) {
            cin >> iVec[k] >> jVec[k] >> eVec[k];
            comp.push_back(iVec[k]);
            comp.push_back(jVec[k]);
        }
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        unordered_map<int, int> trans;
        for (int i = 0; i < comp.size(); ++i)
            trans[comp[i]] = i;

        disjointSet ds(comp.size() + 1);
        for (int k = 0; k < n; ++k) {
            if (!eVec[k])
                continue;
            int u = trans[iVec[k]];
            int v = trans[jVec[k]];
            ds.merge(u, v);
        }
        bool ret = true;
        for (int k = 0; k < n; ++k) {
            if (eVec[k])
                continue;
            int u = trans[iVec[k]];
            int v = trans[jVec[k]];
            if (ds.find(u) == ds.find(v)) {
                ret = false;
                break;
            }
        }
        cout << (ret ? "YES" : "NO") << '\n';
    }
}