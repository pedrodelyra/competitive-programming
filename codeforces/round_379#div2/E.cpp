#include <bits/stdc++.h>

#define MAX 200005

using namespace std;

vector<int> original_tree[MAX], compressed_tree[MAX];

int furthest_node, max_dist, dist[MAX], colors[MAX], id[MAX];

void dfs(int u, int x, int curr_dist, vector<int> (&tree)[MAX]) {
	dist[u] = curr_dist;
	if(max_dist < dist[u]) {
		max_dist = dist[u];
		furthest_node = u;
	}
        for(auto& v : tree[u]) {
                if(!~dist[v] and colors[u] == colors[v]) {
                        dfs(v, x, curr_dist + 1, tree);
                }
        }
	id[u] = x;
}

int main(void) {
        int n, k = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
                scanf("%d", &colors[i]);
        }

        for(int i = 1; i < n; ++i) {
                int u, v;
                scanf("%d %d", &u, &v);
                original_tree[u].push_back(v);
                original_tree[v].push_back(u);
        }

	memset(dist, -1, sizeof dist);
	for(int u = 1; u <= n; ++u) {
		if(!~dist[u]) {
			dfs(u, ++k, 0, original_tree);
		}
	}

	memset(colors, 0, sizeof colors);
	for(int u = 1; u <= n; ++u) {
		for(auto& v : original_tree[u]) {
			if(id[u] != id[v]) {
				compressed_tree[id[u]].push_back(id[v]);
			}
		}
	}
	max_dist = 0, memset(dist, -1, sizeof dist);
	dfs(1, 0, 0, compressed_tree);

	max_dist = 0, memset(dist, -1, sizeof dist);
	dfs(furthest_node, 0, 0, compressed_tree);

	printf("%d\n", dist[furthest_node] + 1 >> 1);
        return 0;
}
