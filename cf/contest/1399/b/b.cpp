#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
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
		int a[n], b[n];
		for (int i = 0; i < n; ++i) std::cin >> a[i];
		for (int i = 0; i < n; ++i) std::cin >> b[i];
		int ma = *std::min_element(a, a + n);
		int mb = *std::min_element(b, b + n);
		LL r = 0;
		for (int i = 0; i < n; ++i) {
			r += std::max(a[i] - ma, b[i] - mb);
		}
		print(r);
	}
	return 0;
}