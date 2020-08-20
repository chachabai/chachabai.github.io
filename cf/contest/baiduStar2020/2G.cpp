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
		int n;
		std::cin >> n;
		LL a[n + 1], b[n + 1];
		for (int i = 1; i <= n; ++i) std::cin >> a[i];
		for (int i = 1; i <= n; ++i) std::cin >> b[i];
		LL dp[n + 1][n + 1];
		memset(dp, -1, sizeof (dp));
		dp[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (dp[i - 1][j] != -1 && dp[i - 1][j] >= a[i] - b[i]) {
					dp[i][j + 1] = dp[i - 1][j] + (b[i] - a[i]);
				}
			}
			for (int j = 0; j < i; ++j) {
				if (dp[i-1][j] != -1) {
					dp[i][j] = std::max(dp[i][j], dp[i-1][j] + b[i]);
				}
			}
		}
		int r = 0;
		for (int i = n; i ; --i) {
			if (dp[n][i] != -1) {
				r = i;
				break;
			}
		}
		std::cout << r << std::endl;
	}
	return 0;
}