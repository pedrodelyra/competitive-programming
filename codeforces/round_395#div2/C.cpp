#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX = 1e5 + 5;

vector<int> tree[MAX], c(MAX);
bool possible, visited[MAX];

void dfs(int u, int color) {
        visited[u] = true;
        for(auto& v : tree[u]) {
                if(not visited[v]) {
                        dfs(v);
                }
        }
        if(c[u] != color) possible = false;
}

int main() {
        int n;
        scanf("%d", &n);
        vector<ii> edges;
        for(int i = 1; i < n; ++i) {
                int u, v;
                scanf("%d %d", &u, &v);
                tree[u].push_back(v);
                tree[v].push_back(u);
                edges.push_back(ii(u, v));
        }
        for(int i = 1; i <= n; ++i) {
                scanf("%d", &c[i]);
        }
        int ans = 1;
        for(auto& edge : edges) {
                int u = edge.first, v = edge.second;
                if(c[u] != c[v]) {
                        vector<int> roots {u, v};
                        for(auto& root : roots) {
                                possible = visited[root] = true;
                                for(auto& x : tree[root]) {
                                        dfs(x, c[x]);
                                }
                                if(possible) {
                                        ans = root;
                                        break;
                                }
                                memset(visited, false, sizeof visited);
                        }
                }
        }
        printf(possible ? "YES\n%d\n" : "NO\n", ans);
        return 0;
}
