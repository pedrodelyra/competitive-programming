#include <bits/stdc++.h>

#define MAX 100005

using namespace std;
using ii = pair<int, int>;

char T[MAX], P[MAX];
int n, m, RA[MAX], tmpRA[MAX], SA[MAX], tmpSA[MAX], LCP[MAX], PLCP[MAX], Phi[MAX], c[MAX];

void counting_sort(int k) {
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof c);
	for(i = 0; i < n; ++i) c[i + k < n ? RA[i + k] : 0]++;

	for(i = sum = 0; i < maxi; ++i) { int t = c[i]; c[i] = sum; sum += t; }

	for(i = 0; i < n; ++i) tmpSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];

	for(i = 0; i < n; ++i) SA[i] = tmpSA[i];
}

void construct_suffix_array(void) {
	int i, k, r;
	for(i = 0; i < n; ++i) RA[i] = T[i];
	for(i = 0; i < n; ++i) SA[i] = i;
	for(k = 1; k < n; k <<= 1) {
		counting_sort(k);
		counting_sort(0);
		tmpRA[SA[0]] = r = 0;
		for(i = 1; i < n; ++i) tmpRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;

		for(i = 0; i < n; ++i) RA[i] = tmpRA[i];

		if(RA[SA[n - 1]] == n - 1) break;

	}
}

void compute_lcp(void) {
        int i, L;
        Phi[SA[0]] = -1;
        for(i = 1; i < n; ++i) Phi[SA[i]] = SA[i - 1];
        for(i = L = 0; i < n; ++i) {
                if(!~Phi[i]) { PLCP[i] = 0; continue; }
                while(T[i + L] == T[Phi[i] + L]) ++L;
                PLCP[i] = L;
                L = max(L - 1, 0);
        }

        for(i = 0; i < n; ++i) LCP[i] = PLCP[SA[i]];
}

ii string_matching(void) {
	int lo = 0, hi = n - 1, mid = lo;
	while(lo < hi) {
		mid = (lo + hi) / 2;
		int res = strncmp(T + SA[mid], P, m);
		if(res >= 0) hi = mid;
		else	     lo = mid + 1;
	}

	if(strncmp(T + SA[lo], P, m) != 0) return ii(-1, -1);

	ii ans; ans.first = lo;
	lo = 0; hi = n - 1; mid = lo;
	while(lo < hi) {
		mid = (lo + hi) / 2;
		int res = strncmp(T + SA[mid], P, m);
		if(res > 0) hi = mid;
		else	    lo = mid + 1;
	}

	if(strncmp(T + SA[hi], P, m) != 0) hi--;
	ans.second = hi;
	return ans;
}

int main(void) {
        int tc;
        scanf("%d\n", &tc);
        while(tc--) {
        	n = strlen(gets(T));
        	T[n++] = '$';
        	construct_suffix_array();
                compute_lcp();
                int lcp_index, max_lcp = 0;
                for(int i = 0; i < n; ++i) {
                        if(max_lcp < LCP[i]) {
                                max_lcp = LCP[i];
                                lcp_index = i;
                        }
                }

                if(max_lcp == 0) { printf("No repetitions found!\n"); continue; }

		m = 0;
                for(int i = SA[lcp_index], count = 0; count < max_lcp; ++count, ++i) {
                        printf("%c", P[m++] = T[i]);
                } 

		ii ans = string_matching();
                printf(" %d\n", ans.second - ans.first + 1);
        }
	return 0;
}
