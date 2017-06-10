#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;

int main() {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
                scanf("%d", &a[i]);
        }
        int min_element = oo;
        for(int i = 0; i < n; ++i) {
                min_element = min(min_element, a[i]);
        }
        printf("Minimum equals %d\n", min_element);
        return 0;
}
