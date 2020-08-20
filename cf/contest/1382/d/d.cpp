#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n, maxn;
		std::cin >> n;
		int a[2 * n];
		for (int i = 0; i < 2 * n; ++i) {
			std::cin >> a[i];
		}
		bool dp[n + 1] = {1};
		for (int i = 0, j = 0; i < 2 * n; i = j) {
			while (j < 2 * n && a[j] <= a[i]) ++j;
			int len = j - i;
			for (int k = n; k >= len; --k) {
				dp[k] |= dp[k - len];
			}
		}
		std::cout << (dp[n] ? "YES" : "NO") << std::endl;
	}
	return 0;
}