#include <bits/stdc++.h>

#define MAX 10005
#define ALPHA 30

using namespace std;

int visited[ALPHA][ALPHA][MAX], dp[ALPHA][ALPHA][MAX], num_elements, target_sum, visited_id = 1;

int num_ways(int i, int k, int current_sum) {
	if(k == 0 && current_sum == target_sum) {
		return 1;
	} else if(i > 26 || k < 0 || current_sum > target_sum) {
		return 0;
	} else if(visited[i][k][current_sum] == visited_id) {
		return dp[i][k][current_sum];
	}

	dp[i][k][current_sum] = num_ways(i + 1, k - 1, current_sum + i) + num_ways(i + 1, k, current_sum); 
	visited[i][k][current_sum] = visited_id;
	return dp[i][k][current_sum];
} 

int main(void) {
	int tc = 0;
	while(scanf("%d %d", &num_elements, &target_sum), num_elements | target_sum) {
		printf("Case %d: %d\n", ++tc, num_ways(1, min(num_elements, 26), 0));
		visited_id++;
	}
}
