// https://www.luogu.com.cn/problem/U122055?contestId=31675
#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
const LL M = 1e9 + 7;
const LL inv2 = (M + 1)/2;
const LL inv6 = (M + 1)/6;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	LL n, m;
	int k;
	std::cin >> n >> m >> k;
	LL a[k], b[k];
	for (int i = 0; i < k; ++i) {
		std::cin >> a[i] >> b[i];
	}
	std::sort(a, a + k);
	std::sort(b, b + k);
	LL sa[k] = {a[0]}, sb[k] = {b[0]};
	for (int i = 1; i < k; ++ i) {
		sa[i] = sa[i - 1] + a[i];
		sb[i] = sb[i - 1] + b[i];
	}

	auto f = [](LL m, LL n) -> LL {
		return m * m % M * (n - 1) % M * n % M * (n + 1) % M;
	};
	LL r0 = (f(m, n) + f(n, m)) * inv6 % M;
	
	LL r1 = 0;
	for (int i = 0; i < k; ++ i) {
		r1 += ((a[i] - 1) * a[i] + (n - a[i] + 1) * (n - a[i])) % M;
	}
	r1 = r1 % M * m % M * inv2 % M;
	
	LL r2 = 0;
	for (int i = 0; i < k; ++ i) {
		r2 += ((b[i] - 1) * b[i] + (m - b[i] + 1) * (m - b[i])) % M;
	}
	r2 = r2 % M * n % M * inv2 % M;
	
	LL r3 = 0;
	for (int i = 0; i < k; ++i) {
		r3 += (sa[k - 1] - sa[i] - a[i] * (k - 1 - i)) % M;
		r3 += (sb[k - 1] - sb[i] - b[i] * (k - 1 - i)) % M;
	}
	r3 %= M;

	LL r = (r0 - r1 - r2 + r3) % M;
	if(r < 0) r += M;
	std::cout << r << std::endl;
	
	return 0;
}