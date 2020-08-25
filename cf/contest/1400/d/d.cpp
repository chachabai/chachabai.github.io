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
		int a[n] = {}, x[n];
		for (int i = 0; i < n; ++i){
			std::cin >> x[i];
			++a[--x[i]];
		}
		auto C4 = [](int n) -> LL {
			LL r = 1;
			for (int i = 0; i < 4; ++i) r *= n - i;
			return r / 24;
		};
		auto C2 = [](int n) -> int {
			return n * (n - 1) / 2;
		};
		int cnt = 0;
		for (int i = 0; i < n; ++i) cnt += C2(a[i]);
		LL r = 0;
		for (int i = 0; i < n; ++i) {
			r += 1LL * C2(a[i]) * (cnt - C2(a[i])); 
		}
		for (int i = 0; i < n; ++i) r += C4(a[i]);
		int b[n] = {};
		int lh = 0, rh = cnt;
		for (int i = 0; i < n; ++i) {
			int t = x[i];
			lh -= C2(b[t]);
			rh -= C2(a[t] - b[t]); 
			++b[t];
			lh += C2(b[t]);
			rh += C2(a[t] - b[t]);
			r -= LL(lh) * rh;
		}
		auto f = [](int n) -> LL {
			LL r = LL(n + 1) *  n * (n + 1) * n * (n - 1) / 3;
			r -= LL(2 * n + 2) * (n + 2) * (n + 1) * n * (n - 1) / 4;
			r += LL(n + 3) * (n + 2) * (n + 1) * n * (n - 1) / 5;
			return r / 4;
		};
		for(int i = 0; i < n; ++i) r += f(a[i]);
		std::cout << r << std::endl;
	}
	return 0;
}