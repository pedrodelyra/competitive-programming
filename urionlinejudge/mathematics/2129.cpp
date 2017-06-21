#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

int main() {
        int a = 0, b = 0;
        vector<int> ans(MAX, 0);
        for(int i = 1; i < MAX; ++i) {
                int x = i;
                while(x % 2 == 0) ++a, x /= 2;
                while(x % 5 == 0) ++b, x /= 5;
                ans[i] = min(a, b) + 1;
        }
        int n, tc = 1;
        while(~scanf("%d", &n)) {
                printf("Instancia %d\n%d\n\n" ,tc++, ans[n]);
        }
        return 0;
}
