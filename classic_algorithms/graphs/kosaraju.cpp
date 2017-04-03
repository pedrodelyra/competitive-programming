#include <bits/stdc++.h>

using namespace std;

// Kosaraju algorithm: Detect strongly connected components of a directed graph.

vector<int> original[1024], reversed[1024], scc(1024, 0);
bool visited[1024];

void dfs(int u, stack<int>& s) {
        visited[u] = true;
        for(auto& v : original[u]) {
                if(not visited[v]) {
                        dfs(v, s);
                }
        }
        s.push(u);
}

void dfs(int u, int k) {
        scc[u] = k;
        for(auto& v : reversed[u]) {
                if(not scc[v]) {
                        dfs(v, k);
                }
        }
}

int main() {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= m; ++i) {
                int u, v;
                cin >> u >> v;
                original[u].push_back(v);
                reversed[v].push_back(u);
        }
        stack<int> s;
        for(int u = 1; u <= n; ++u) {
                if(not visited[u]) {
                        dfs(u, s);
                }
        }
        int k = 0;
        while(not s.empty()) {
                int u = s.top(); s.pop();
                if(scc[u] == 0) {
                        dfs(u, ++k);
                }
        }
        return 0;
}
