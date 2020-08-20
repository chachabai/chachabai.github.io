// https://www.luogu.com.cn/problem/U122054?contestId=31675
#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const LL M = 998244353, ROOT = 3;
LL powMod(LL x, LL n) {
	LL r(1);
	while (n) {
		if (n & 1) r = r * x % M;
		n >>= 1;
		x = x * x % M;
	}
	return r;
}
void bitreverse(std::vector<LL> &a) {
	for (int i = 0, j = 0; i != a.size(); ++i) {
		if (i > j) std::swap(a[i], a[j]);
		for (int l = a.size() >> 1;
			(j ^= l) < l; l >>= 1);
	}
}
void nft(std::vector<LL> &a, bool isInverse = false) {
	LL g = powMod(ROOT, (M - 1) / a.size());
	if (isInverse) {
		g = powMod(g, M - 2);
		LL invLen = powMod(LL(a.size()), M - 2);
		for (auto & x: a) x = x * invLen % M;
	}
	bitreverse(a);
	std::vector<LL> w(a.size(), 1);
	for (int i = 1; i != w.size(); ++i) w[i] = w[i - 1] * g % M;
	auto addMod = [](LL x, LL y) {
		return (x += y) >= M ? x -= M : x;
	};
	for (int step = 2, half = 1; half != a.size(); step <<= 1, half <<= 1) {
		for (int i = 0, wstep = a.size() / step; i != a.size(); i += step) {
			for (int j = i; j != i + half; ++j) {
				LL t = (a[j + half] * w[wstep * (j - i)]) % M;
				a[j + half] = addMod(a[j], M - t);
				a[j] = addMod(a[j], t);
			}
		}
	}
}
std::vector<LL> mul(std::vector<LL> a, std::vector<LL> b) {
	int sz = 1, tot = a.size() + b.size() - 1;
	while (sz < tot) sz *= 2;
	a.resize(sz);
	b.resize(sz);
	nft(a);
	nft(b);
	for (int i = 0; i != sz; ++i) a[i] = a[i] * b[i] % M;
	nft(a, 1);
	a.resize(tot);
	return a;
}

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<LL> a(n);
	for (auto &x : a) std::cin >> x;
	std::vector<LL> b(a.rbegin(),a.rend());
	auto c = mul(a, b);

	LL inv[n] = {0, 1}, f[n + 1] = {1, 1};
	for (int i = 2; i <= n; ++i) inv[i] = (M - M / i) * inv[M % i] % M;
	for (int i = 2; i <= n; ++i) {
		f[i] = ((12 * i - 30)* f[i - 1] - (4 * i - 16) * f[i - 2]) % M * inv[i - 1] % M;
		if (f[i] < 0) f[i] += M;
	}
	
	LL r = 0;
	for (int i = 2; i <= n; ++i) {
		r += f[i] * f[n - i + 2] % M * c[n - i] % M;
	}
	r = r * inv[4] % M * powMod(f[n], M - 2) % M;
	std::cout << r << std::endl;

	return 0;
}
