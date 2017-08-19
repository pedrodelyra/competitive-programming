#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 8192;

vector<int> scc(MAX_N);

void dfs(int u, vector<int> (&graph)[MAX_N], int scc_id, stack<int>* s = nullptr) {
        scc[u] = scc_id;
        for(auto& v : graph[u]) {
                if(not scc[v]) {
                        dfs(v, graph, scc_id, s);
                }
        }
        if(s) s->push(u);
}

int main() {
        int n, m;
        while(cin >> n >> m, n) {
                vector<int> original[MAX_N], reversed[MAX_N];
                for(int i = 1; i <= m; ++i) {
                        int u, v;
                        cin >> u >> v;
                        original[u].push_back(v);
                        reversed[v].push_back(u);
                }
                stack<int> s; fill(begin(scc), end(scc), 0);
                for(int u = 1; u <= n; ++u) {
                        if(not scc[u]) {
                                dfs(u, original, 1, &s);
                        }
                }
                fill(begin(scc), end(scc), 0);
                int scc_counter = 0;
                while(not s.empty()) {
                        int u = s.top(); s.pop();
                        if(not scc[u]) {
                                dfs(u, reversed, ++scc_counter);
                        }
                }
                bitset<MAX_N> sink; sink.set();
                for(int u = 1; u <= n; ++u) {
                        for(auto& v : original[u]) {
                                if(scc[u] != scc[v]) {
                                        sink[scc[u]] = false;
                                }
                        }
                }
                bool print_space = false;
                for(int u = 1; u <= n; ++u) {
                        if(sink[scc[u]]) {
                                cout << (print_space ? " " : (print_space = true, "")) << u;
                        }
                }
                cout << endl;
        }
        return 0;
}
