// 2704ms, 31788KB

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Edge {
    int target, capacity, flow;
    Edge* reverse;
    int residualCapacity() const
    {
        return capacity - flow;
    }
    void push()
    {
        --flow;
        ++reverse->flow;
    }
};

vector<vector<Edge*>> adj;

void addEdge(int u, int v, int cap)
{
    Edge* uv = new Edge(), * vu = new Edge();
    uv->target = v;
    uv->capacity = cap;
    uv->flow = 0;
    uv->reverse = vu;
    vu->target = u;
    vu->capacity = 0;
    vu->flow = 0;
    vu->reverse = uv;
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    int src = n + m + 1, sink = n + m + 2;
    adj.resize(sink + 1);
    addEdge(src, 0, k);
    for (int i = n + 1; i <= n + m; ++i)
        addEdge(i, sink, 1);
    for (int i = 1; i <= n; ++i) {
        addEdge(0, i, k);
        addEdge(src, i, 1);
        int wn;
        cin >> wn;
        for (int w = 0; w != wn; ++w) {
            int x;
            cin >> x;
            addEdge(i, n + x, 1);
        }
    }
    int total = 0;
    while (true) {
        vector<Edge*> parentEdge(sink + 1, nullptr);
        queue<int> q;
        q.push(src);
        while (!q.empty() && !parentEdge[sink]) {
            int here = q.front(); q.pop();
            for (auto e : adj[here])
            {
                int there = e->target;
                if (e->residualCapacity() > 0 && !parentEdge[there]) {
                    q.push(there);
                    parentEdge[there] = e->reverse;
                }
            }
        }
        if (!parentEdge[sink])
            break;
        for (auto e = parentEdge[sink]; ;) {
            e->push();
            if (e->target == src)
                break;
            e = parentEdge[e->target];
        }
        ++total;
    }
    cout << total;
}