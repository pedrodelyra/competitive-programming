#include <bits/stdc++.h>

using namespace std;

vector<int> roots, tree[2048];

int dfs(int u) {
        int curr_dist = 0;
        for(auto& v : tree[u]) {
                curr_dist = max(curr_dist, dfs(v));
        }
        return curr_dist + 1;
}

int main() {
        int n;
        cin >> n;
        for(int u = 1; u <= n; ++u) {
                int p; cin >> p;
                if(~p) {
                        tree[p].push_back(u);
                } else {
                        roots.push_back(u);
                }
        }
        int max_dist = 0;
        for(auto& u : roots) {
                max_dist = max(max_dist, dfs(u));
        }
        cout << max_dist << endl;
        return 0;
}
