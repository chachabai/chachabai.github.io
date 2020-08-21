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
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
			b[i] = a[i];
		}
		int mx = *std::min_element(a, a + n);
		std::sort(b, b + n);
		bool flag = true;
		for (int i = 0; i < n; ++i) if (a[i] != b[i]) {
			if ((a[i] % mx) || (b[i] % mx)) flag = false;
		}
		std::cout << (flag ? "YES" : "NO") << std::endl;
	}
	return 0;
}