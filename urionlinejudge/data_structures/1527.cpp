#include <bits/stdc++.h>

using namespace std;

class union_find {
private:
        vector<int> p, s;

public:
        union_find(int n, int scores[]) : p(n + 1), s(n + 1) {
                for(int i = 1; i <= n; ++i) {
                        p[i] = i;
                        s[i] = scores[i];
                }
        }

        int find_set(int u) {
                return u == p[u] ? u : (p[u] = find_set(p[u]));
        }

        bool same_set(int u, int v) {
                return find_set(u) == find_set(v);
        }

        void join_sets(int u, int v) {
                if(not same_set(u, v)) {
                        int x = find_set(u), y = find_set(v);
                        p[y] = x;
                        s[x] = s[x] + s[y];
                }
        }

        int score(int u) {
                return u == p[u] ? s[u] : score(p[u]);
        }
};

int main() {
        ios_base::sync_with_stdio(false);
        int n, m;
        while(cin >> n >> m, n and m) {
                int scores[n + 1], wins = 0;
                for(int i = 1; i <= n; ++i) {
                        cin >> scores[i];
                }
                union_find ufds(n, scores);
                while(m--) {
                        int query, u, v;
                        cin >> query >> u >> v;
                        if(query == 1) {
                                ufds.join_sets(u, v);
                        } else {
                                int su = ufds.score(u), sv = ufds.score(v);
                                if(su != sv) {
                                        int winner = su > sv ? u : v;
                                        if(ufds.same_set(1, winner))
                                                ++wins;
                                }
                        }
                }
                cout << wins << endl;
        }
        return 0;
}
