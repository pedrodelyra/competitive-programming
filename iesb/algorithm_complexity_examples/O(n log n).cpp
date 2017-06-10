#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

const int oo = 1e9;

int n, a[MAX];

void merge(int l1, int r1, int l2, int r2) {
        int x = 0, y = 0, p[r1 - l1 + 5], q[r2 - l2 + 5];
        for(int i = l1; i <= r1; ++i) p[x++] = a[i];
        for(int i = l2; i <= r2; ++i) q[y++] = a[i];
        p[x] = q[y] = oo;
        for(int i = 0, j = 0, k = l1; k <= r2; ++k) {
                a[k] = p[i] < q[j] ? p[i++] : q[j++];
        }
}

void merge_sort(int l = 1, int r = n) {
        if(l < r) {
                int m = l + r >> 1;
                merge_sort(    l, m);
                merge_sort(m + 1, r);
                merge(l, m, m + 1, r);
        }
}

int main() {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
                scanf("%d", &a[i]);
        }
        merge_sort();
        for(int i = 1; i <= n; ++i) {
                printf("%d%c", a[i], " \n"[i == n]);
        }
        return 0;
}
