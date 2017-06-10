#include <bits/stdc++.h>

using namespace std;

const int MAX = 20005, oo = 0x3f3f3f3f;

int dist[MAX];

int main() {
        int n, m;
        cin >> n >> m;
        memset(dist, oo, sizeof dist);
        queue<int> q;
        dist[n] = 0, q.push(n);
        while(not q.empty()) {
                int u = q.front(), edges[] = {2 * u, u - 1}; q.pop();

                if(u == m) break;

                for(auto& v : edges) {
                        if(0 < v and v < MAX and dist[v] == oo) {
                                dist[v] = dist[u] + 1;
                                q.push(v);
                        }
                }
        }
        cout << dist[m] << endl;
        return 0;
}
