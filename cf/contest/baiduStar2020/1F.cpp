#include <bits/stdc++.h>
using LL = long long;
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
const LL M = 1e9 + 7;
const int N = 1e6 + 2;

int mu[N];
void initmu() {
	mu[1] = 1;
	for (int i = 1; i < N; ++i) {
		for (int j = i * 2; j < N; j += i) {
			mu[j] -= mu[i];
		}
	}
}
int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	initmu();
	auto f = [](LL n) {
		LL ret = 0;
		for (LL l = 1, r; l <= n; l = r + 1) {
			r = n / (n / l);
			ret += ((n / l) % M) * ((l + r) % M) % M * ((r - l + 1) % M) % M;
		}
		return ret % M * ((M + 1) / 2) % M;
	};
	int cas;
	std::cin >> cas;
	while (cas--) {
		LL n, ans = 0;
		std::cin >> n;
		for (LL i = 1; i * i <= n; ++i) {
			if (mu[i] == 0) continue;
			ans += (M + mu[i]) * i % M * f(n / (i * i)) % M;
		}
		std::cout << ans%M << std::endl;
	}
	return 0;
}