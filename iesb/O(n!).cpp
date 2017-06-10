#include <bits/stdc++.h>

#define MAX 32

using namespace std;

int n, a[MAX];

void generate_permutations(int i = 1) {
        if(i == n) {
                for(int j = 1; j <= n; ++j) {
                        printf("%d%c", a[j], " \n"[j == n]);
                }
        } else {
                for(int j = i; j <= n; ++j) {
                        swap(a[i], a[j]);
                        generate_permutations(i + 1);
                        swap(a[i], a[j]);
                }
        }
}

int main() {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) a[i] = i;
        generate_permutations();
        return 0;
}
