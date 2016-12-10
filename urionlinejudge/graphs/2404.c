#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int u, v, w;
} edge;

int count, parents[512], rank[512];

void init_ufds(int n) {
	int i;
	for(i = 1; i <= n; ++i) {
		parents[i] = i;
		rank[i] = 0;
	}
	count = n;
}

int find_set(int u) {
	return u == parents[u] ? u : (parents[u] = find_set(parents[u]));
}

int same_set(int u, int v) {
	return find_set(u) == find_set(v);
}

void union_set(int u, int v) {
	if(!same_set(u, v)) {
		int x = find_set(u), y = find_set(v);
		if(rank[x] >= rank[y]) {
			parents[y] = parents[x];
		} else{
			parents[x] = parents[y];
		}
		if(rank[x] == rank[y]) ++rank[x];
		--count;
	}
}

int cmp(const void* a, const void* b) {
	return ((edge *) a)->w - ((edge *) b)->w;
}

int main(void) {
	int i, n, m, mst = 0;
	scanf("%d %d", &n, &m);
	edge edges[m + 1];
	for(i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
	}
	qsort(edges + 1, m, sizeof(edge), cmp);
	init_ufds(n);
	for(i = 1; count > 1 && i <= m; ++i) {
		if(!same_set(edges[i].u, edges[i].v)) {
			union_set(edges[i].u, edges[i].v);
			mst += edges[i].w;
		}
	}
	printf("%d\n", mst);
	return 0;
}
