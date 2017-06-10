#include <bits/stdc++.h>

int main() {
        int n;
        scanf("%d", &n);
        std::vector<int> a(n + 1);
        for(int i = 1; i <= n; ++i) {
                std::cin >> a[i];
        }
        for(int i = 1; i < n; ++i) {
                int min = a[i], idx = i;
                for(int j = i + 1; j <= n; ++j) {
                        if(a[j] < min) {
                                min = a[j];
                                idx = j;
                        }
                }
                std::swap(a[i], a[idx]);
        }
        for(int i = 1; i <= n; ++i) {
                std::cout << a[i] << " \n"[i == n];
        }
        return 0;
}
