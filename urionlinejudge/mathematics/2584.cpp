#include <bits/stdc++.h>

using namespace std;

const double theta = acos(-1.0) / 5;

int main() {
        int tc;
        scanf("%d", &tc);
        while(tc--) {
                int l;
                scanf("%d", &l);
                printf("%.3lf\n", 1.25 * l * l / tan(theta));
        }
        return 0;
}
