#include <bits/stdc++.h>

#define MAX 1024
#define oo  1 << 30

using namespace std;

string red = "VERMELHO", orange = "LARANJA", blue = "AZUL", green = "VERDE", colors[MAX];
int n, heights[MAX], radius[MAX] = {oo}, dp[MAX];

bool can_stack(int i, int j) {
	return radius[j] < radius[i] and ((colors[j] == red and colors[i] != orange) or
					  (colors[j] == orange and colors[i] != blue) or
					  (colors[j] == blue and colors[i] != green) or
					  (colors[j] == green and colors[i] != red));
}

int solve(int i) {
	if(~dp[i]) {
		return dp[i];
	}
	int max_height = 0;
	for(int j = 1; j <= n; ++j) {
		if(can_stack(i, j)) {
			max_height = max(max_height, solve(j));
		}
	}
	return dp[i] = max_height + heights[i];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	while(cin >> n, n) {
		for(int i = 1; i <= n; ++i) {
			cin >> heights[i] >> radius[i] >> colors[i];
		}
		memset(dp, -1, sizeof dp);
		cout << solve(0) << " centimetro(s)" << endl;
	}
	return 0;
}
