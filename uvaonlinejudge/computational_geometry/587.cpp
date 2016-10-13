#include <bits/stdc++.h>

#define pi 3.141592653589793

using namespace std;
using dd = pair<double, double>;

const double a = cos(pi / 4);

dd us[] {{0,  1}, { a,  a}, { 1, 0}, { a, -a},
	 {0, -1}, {-a, -a}, {-1, 0}, {-a,  a}};

map<string, int> dirs {{"N", 0}, {"NE", 1}, {"E", 2}, {"SE", 3},
		       {"S", 4}, {"SW", 5}, {"W", 6}, {"NW", 7}};

int main(void) {
	int tc = 0;
	string input;
	while(getline(cin, input), input != "END") {
		stringstream ss(input);
		dd current_pos;
		int steps; char dir;
		while(ss >> steps >> dir) {
			char c = ss.get();
			string direction;
			direction += dir;

			if(isalpha(c)) { direction += c; ss.get(); }

			int idx = dirs[direction];
			current_pos.first  += steps * us[idx].first;
			current_pos.second += steps * us[idx].second;
		}

		double dist = hypot(current_pos.first, current_pos.second);

		printf("Map #%d\nThe treasure is located at (%.3lf,%.3lf).\n"
		       "The distance to the treasure is %.3lf.\n\n", ++tc,
			current_pos.first, current_pos.second, dist);
	}

	return 0;
}
