#include <bits/stdc++.h>

#define MAX 2000005

using namespace std;

vector<string> comments[MAX];
char str[MAX];
int  max_dist;

int dfs(int d) {
	int n, r;
	if(~(r = scanf("%[^,],%d,", str, &n)) and str[0] != '\n') {
			comments[d].push_back(str);
			while(n--) {
				r = dfs(d + 1);
			}
			max_dist = max(max_dist, d);
	}
	return r;
}

int main(void) {
	int n, u = 1, k = 1;
	while(~dfs(0));
	printf("%d\n", max_dist + 1);
	for(int i = 0; i <= max_dist; ++i) {
		for(int j = 0; j < comments[i].size(); ++j) {
			if(j) printf(" ");
			printf("%s", comments[i][j].c_str());
		}
		printf("\n");
	}
	return 0;
}
