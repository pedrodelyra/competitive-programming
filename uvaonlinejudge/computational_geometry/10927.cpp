#include <bits/stdc++.h>

#define EPS 1e-12

using namespace std;
using ll = long long int;
using point = pair<int, int>;

bool equals(double x, double y) { return fabs(x - y) < EPS; }

class pole {
public:
	int x, y, z;
	double theta;

	pole(int xv = 0, int yv = 0, int zv = 0) : x(xv), y(yv), z(zv), theta(atan2(yv, xv)) {}

	bool operator<(const pole& p) const {
		if(equals(this->theta, p.theta)) {
			return (this->x * (ll) this->x + this->y * this->y) < (p.x * (ll) p.x + p.y * p.y);
		} else {
			return this->theta < p.theta - EPS;
		}
	}
};

int main(void) {
	int n, tc = 0;
	while(scanf("%d", &n), n) {
		vector<pole> poles(n);
		for(int i = 0; i < n; ++i) {
			ll x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			poles[i] = pole(x, y, z);
		}

		sort(poles.begin(), poles.end());

		set<point> invisible_points;
		int current_height = poles[0].z;
		for(int i = 1; i < n; ++i) {
			if(equals(poles[i].theta, poles[i - 1].theta) && poles[i].z <= current_height) {
				invisible_points.insert({ poles[i].x, poles[i].y });
			} else {
				current_height = poles[i].z;
			}
		}

		int num_inv_points;
		printf("Data set %d:\n", ++tc);
		if((num_inv_points = invisible_points.size()) > 0) {
			int count = 0;
			printf("Some lights are not visible:\n");
			for(auto& current_point : invisible_points) {
				printf("x = %d, y = %d", current_point.first, current_point.second);
				if(++count < num_inv_points) printf(";\n");
			}
			printf(".\n");
		} else {
			printf("All the lights are visible.\n");
		}
	}

	return 0;
}
