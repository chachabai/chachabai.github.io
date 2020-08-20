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
		LL n, m;
		std::cin >> n >> m;
		std::pair<int, int> a[m];
		int b[m];
		LL c[m+1]={};
		for (int i = 0; i < m; ++i) {
			std::cin >> a[i].second >> a[i].first;
			b[i] = a[i].second;
		}
		std::sort(a, a + m, std::greater<std::pair<int,int>>());
		std::sort(b, b + m);
		for (int i = 0; i < m; ++i) c[i+1] = c[i] + b[i];
		LL r = 0;
		for (int i = 0; i < m; ++i) {
			int id = std::lower_bound(b, b + m, a[i].first) - b;
			if (m-id >= n) r = std::max(r, c[m] - c[m-n]);
			else {
				LL t = c[m] - c[id];
				int nn = n - (m-id);
				if (a[i].first > a[i].second) {
					t += a[i].second;
					--nn;
				}
				r = std::max(r, t + LL(nn)*a[i].first);
			}
		}
		std::cout << r << std::endl;
	}
	return 0;
}