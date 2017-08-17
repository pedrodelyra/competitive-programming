#include <bits/stdc++.h>

using namespace std;

class union_find {
private:
        vector<int> p, r;

public:
        union_find(int n) : p(n + 1, 0), r(n + 1, 0) {
                for(int u = 1; u <= n; ++u)
                        p[u] = u;
        }

        int find_set(int u) {
                return u == p[u] ? u : (p[u] = find_set(p[u]));
        }

        bool same_set(int u, int v) {
                return find_set(u) == find_set(v);
        }

        void union_set(int u, int v) {
                if(not same_set(u, v)) {
                        int x = find_set(u), y = find_set(v);
                        if(r[x] >= r[y]) {
                                p[y] = x;
                        } else {
                                p[x] = y;
                        }
                        if(r[x] == r[y]) ++r[x];
                }
        }
};

const int MAX_N = 1e4 + 5;

vector<int> graph[MAX_N], parents(MAX_N), dfs_num(MAX_N), dfs_low(MAX_N);
int dfs_counter;

void tarjan(int u, union_find& ufds) {
        dfs_num[u] = dfs_low[u] = ++dfs_counter;
        for(auto& v : graph[u]) {
                if(dfs_num[v]) {
                        if(v != parents[u])
                                dfs_low[u] = min(dfs_low[u], dfs_num[v]);
                } else {
                        parents[v] = u;
                        tarjan(v, ufds);

                        if(dfs_low[v] > dfs_num[u])
                                ufds.union_set(u, v);

                        dfs_low[u] = min(dfs_low[u], dfs_low[v]);
                }
        }
}

int main() {
        int n, m, q;
        while(scanf("%d %d %d", &n, &m, &q), n | m | q) {
                for(int i = 1; i <= m; ++i) {
                        int u, v;
                        scanf("%d %d", &u, &v);
                        graph[u].push_back(v);
                        graph[v].push_back(u);
                }
                union_find ufds(n);
                fill(begin(dfs_num), end(dfs_num), dfs_counter = 0);
                for(int u = 1; u <= n; ++u) {
                        if(dfs_num[u] == 0)
                                tarjan(u, ufds);
                }
                while(q--) {
                        int u, v;
                        scanf("%d %d", &u, &v);
                        printf(ufds.same_set(u, v) ? "Y\n" : "N\n");
                }
                printf("-\n");
                for(int u = 1; u <= n; ++u)
                        graph[u].clear();
        }
        return 0;
}
