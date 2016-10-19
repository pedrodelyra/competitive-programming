#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0), eps = 1e-9;

int main(void) {
	double R, H, V, G;
	while(~scanf("%lf %lf %lf %lf", &R, &H, &V, &G)) {
		double theta = atan2(V, sqrt(V * V + 2 * G * H)), Vox = V * cos(theta), Voy = V * sin(theta);
		double t = (Voy + sqrt(Voy * Voy + 2 * G * H)) / G;
		double x = Vox * t;
		printf(x + eps > R ? "Y\n" : "N\n");
	}
	return 0;
}
