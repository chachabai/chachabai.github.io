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
		int n, k, z;
		std::cin >> n >> k >> z;
		int a[n], b[n];
		for (int i = 0; i < n; ++i) std::cin >> a[i];
		for (int i = 0; i + 1 < n; ++i) b[i] = a[i] + a[i + 1];
		int s[n] = {a[0]};
		for (int i = 1; i < n; ++i) s[i] = s[i - 1] + a[i];
		int r = s[k];
		for (int i = 1; i <= z && 2 * i <= k; ++i) {
			r = std::max(r, s[k - 2 * i] + *std::max_element(b, b + 1 + k - 2 * i) * i);
		}
		std::cout << r << std::endl;
	}
	return 0;
}