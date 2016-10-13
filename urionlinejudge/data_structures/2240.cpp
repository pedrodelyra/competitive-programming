#include <bits/stdc++.h>

#define MAX   10005
#define LEFT  0
#define RIGHT 1

using namespace std;
using iii = tuple<int, int, int>;

iii left_tree[MAX], right_tree[MAX];
int central_depth[2][MAX];

int dfs(int u, iii (&tree)[MAX], int id) {
	if(u == 0) return 0;

	int left_child, center_child, right_child;
	tie(left_child, center_child, right_child) = tree[u];
	dfs(left_child, tree, id);
	dfs(right_child, tree, id);
	return central_depth[id][u] = dfs(center_child, tree, id) + 1;
}

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int u, left_child, center_child;
		scanf("%d %d %d", &u, &left_child, &center_child);
		left_tree[u] = iii(left_child, center_child, 0);
	}

	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		int u, center_child, right_child;
		scanf("%d %d %d", &u, &center_child, &right_child);
		right_tree[u] = iii(0, center_child, right_child);
	}

	dfs(1, left_tree, LEFT);
	dfs(1, right_tree, RIGHT);

	int max_central_depth[2] = {0, 0};
	for(int u = 1; u <= n; ++u) {
		max_central_depth[LEFT] = max(max_central_depth[LEFT], central_depth[LEFT][u]);
	}

	for(int u = 1; u <= m; ++u) {
		max_central_depth[RIGHT] = max(max_central_depth[RIGHT], central_depth[RIGHT][u]);
	}

	printf("%d\n", n + m - max(min(max_central_depth[LEFT], central_depth[RIGHT][1]), min(central_depth[LEFT][1], max_central_depth[RIGHT])));

	return 0;
}
