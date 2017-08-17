#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e4 + 5, oo = 1e9;

vector<int> tree[MAX_N], dist(MAX_N);

int bfs(int source) {
        queue<int> q;
        fill(begin(dist), end(dist), oo);
        dist[source] = 0, q.push(source);
        int furthest = source;
        while(not q.empty()) {
                int u = q.front(); q.pop();
                for(auto& v : tree[u]) {
                        if(dist[v] == oo) {
                                dist[v] = dist[u] + 1;
                                q.push(v);
                        }
                }
                furthest = u;
        }
        return furthest;
}

int main() {
        int n;
        while(cin >> n, ~n) {
                for(int u = 2; u <= n; ++u) {
                        int v;
                        cin >> v;
                        tree[u].push_back(v);
                        tree[v].push_back(u);
                }
                cout << (dist[bfs(bfs(1))] + 1) / 2 << endl;
                for(int u = 1; u <= n; ++u)
                        tree[u].clear();
        }
        return 0;
}
