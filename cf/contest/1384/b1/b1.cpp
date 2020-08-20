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
		int n, k, len;
		std::cin >> n >> k >> len;
		int d[n];
		bool flag = false;
		for (int i = 0; i < n; ++i) {
			std::cin >> d[i];
			if (d[i] > len) flag = true;
			else d[i] = len - d[i];
		}
		if (flag) {
			std::cout << "No\n";
			continue;
		}
		int l = 0, r = k;
		for (int i = 0; i < n; ++ i){
			int li = std::min(k, d[i]);
			int ri = std::max(k, 2 * k - d[i]);
			if (r < 2 * k) {
				l = 0;
				r = std::max(r + 1, ri);
			} else if (++l > li) flag = true;
			l = std::min(l, k);
			if (d[i] >= k) r = k;
		}
		std::cout << (flag ? "No" : "Yes") << std::endl;
	}
	return 0;
}