#include <bits/stdc++.h>

int main(void) {
	int cows, cars, displayed_doors;
	while(scanf("%d %d %d", &cows, &cars, &displayed_doors) != EOF) {
		int total_doors = cows + cars;
		double pick_cow_first = cows / (double) total_doors * cars / ((double) total_doors - displayed_doors - 1);
		double pick_car_first = cars / (double) total_doors * (cars - 1) / ((double) total_doors - displayed_doors - 1);
		printf("%.5lf\n", pick_cow_first + pick_car_first);
	}

	return 0;
}
