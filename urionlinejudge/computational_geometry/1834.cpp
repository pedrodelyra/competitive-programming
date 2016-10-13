#include <bits/stdc++.h>

using namespace std;

class point {
public:
	double x;
	double y;

	point(double xv, double yv) : x(xv), y(yv) {}

	double dist(const point& q) {
		return hypot(x - q.x, y - q.y);
	}
};

double det(const point& p, const point& q, const point& r) {
	return (p.x * q.y + p.y * r.x + q.x * r.y) - (r.x * q.y + r.y * p.x + q.x * p.y);
}

int main(void) {
	double x1, y1, x2, y2;
	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	point p(x1, y1), q(x2, y2);

	int n, east_planets = 0, east_population = 0, west_planets = 0, west_population = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int x, y, h;
		scanf("%d %d %d", &x, &y, &h);
		double d = det(p, q, point(x, y));
		if(d > 0) {
			++east_planets;
			east_population += h;
		} else if(d < 0) {
			++west_planets;
			west_population += h;
		}
	}

	printf("Relatorio Vogon #35987-2\nDistancia entre referencias: %.2lf anos-luz\n", p.dist(q));
	printf("Setor Oeste:\n- %d planeta(s)\n- %d bilhao(oes) de habitante(s)\n", east_planets, east_population);
	printf("Setor Leste:\n- %d planeta(s)\n- %d bilhao(oes) de habitante(s)\n", west_planets, west_population); 
	printf("Casualidades: %d planeta(s)\n", n - east_planets - west_planets);

	return 0;
}
