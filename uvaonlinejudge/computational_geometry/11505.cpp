#include <bits/stdc++.h>

#define pi 3.141592653589793

using namespace std;

class point {
public:
	double x;
	double y;

	point(double xv = 0, double yv = 0) : x(xv), y(yv) {}
};

int main(void) {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n;
		scanf("%d", &n);
		point current_pos;
		int theta = 0;
		while(n--) {
			char command[3]; int x;
			scanf(" %s %d", command, &x); 
			if(!strcmp(command, "fd")) {
				current_pos.x += x * cos(pi * theta / 180.0);
				current_pos.y += x * sin(pi * theta / 180.0);
			}

			if(!strcmp(command, "bk")) {
				current_pos.x -= x * cos(pi * theta / 180.0);
				current_pos.y -= x * sin(pi * theta / 180.0);
			}

			if(!strcmp(command, "lt")) {
				theta += x;
			}

			if(!strcmp(command, "rt")) {
				theta -= x;
			}
		}

		printf("%d\n", (int) (hypot(current_pos.x, current_pos.y) + 0.5));
	}

	return 0;
}
