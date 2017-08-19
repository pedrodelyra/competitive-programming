#include <bits/stdc++.h>

using namespace std;
using lld = long long;
using ll  = pair<int, lld>;

const lld oo = 1LL << 30, MAX_N = 2e5 + 5;

vector<ll>  tree[MAX_N];
vector<int> st(MAX_N << 2, 0), f(MAX_N, 0), euler(MAX_N << 1);
vector<lld> dist(MAX_N);
int n, k;

void build_st(int p = 1, int l = 1, int r = k) {
        if(l == r) {
                st[p] = euler[l];
        } else {
                int m = l + r >> 1;
                build_st(p << 1, l, m);
                build_st(p << 1 | 1, m + 1, r);
                st[p] = dist[st[p << 1]] < dist[st[p << 1 | 1]] ? st[p << 1] : st[p << 1 | 1];
        }
}

int query(int i, int j, int p = 1, int l = 1, int r = k) {
        if(i > r or j < l) {
                return -1;
        } else if(i <= l and r <= j) {
                return st[p];
        } else {
                int m = l + r >> 1;
                int x = query(i, j, p << 1, l, m), y = query(i, j, p << 1 | 1, m + 1, r);
                if(!~x) return y;
                if(!~y) return x;
                return dist[x] < dist[y] ? x : y;
        }
}

void dfs(int u, lld d = 0) {
        dist[euler[f[u] = ++k] = u] = d;
        for(auto& edge : tree[u]) {
                int v = edge.first; lld w = edge.second;
                if(!~dist[v]) {
                        dfs(v, d + w);
                        euler[++k] = u;
                }
        }
}

int lca(int u, int v) {
        int a = min(f[u], f[v]), b = max(f[u], f[v]);
        return query(a, b);
}

int main() {
        const int root = 1;
        while(scanf("%d", &n), n) {
                for(int u = 1; u < n; ++u) {
                        int v, w;
                        scanf("%d %d", &v, &w);
                        tree[u + 1].push_back(ll(v + 1, w));
                        tree[v + 1].push_back(ll(u + 1, w));
                }
                fill(begin(dist), end(dist), -1), dfs(root, k = 0), build_st();
                int queries; scanf("%d", &queries);
                for(int q = 1; q <= queries; ++q) {
                        int u, v;
                        scanf("%d %d", &u, &v);
                        printf("%lld%c", dist[u + 1] + dist[v + 1] - 2 * dist[lca(u + 1, v + 1)], " \n"[q == queries]);
                }
                for(int u = 0; u < n; ++u)
                        tree[u + 1].clear();
        }
        return 0;
}
