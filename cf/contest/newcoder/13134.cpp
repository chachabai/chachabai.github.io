#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	int a[n], pre[n] = {1}, dp[n] = {1};
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i-1]) pre[i] = pre[i - 1] + 1;
		else pre[i] = 1;
	}
	int r = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1]) {
			if (i > 1 && a[i - 2] > a[i] - 1) {
				dp[i] = std::max(dp[i - 1] + 1, pre[i - 2] + 2);
			} else {
				dp[i] = dp[i - 1] + 1
			}
		}
		else {
			dp[i] = 1 + pre[i - 1];
			if (i > 1 && a[i] > a[i - 2] + 1) {
				dp[i] = std::max(dp[i], 2 + pre[i - 2]);
			}
		}
		r = std::max(r, dp[i]);
	}
	print(r);
	return 0;
}