#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	const std::string s = "abacaba";
	while (cas--) {
		int n;
		std::string a;
		std::cin >> n >> a;
		auto f = [&](int n, bool strict = false) {
			for (int i = 0; i < 7; ++i) {
				if((!strict) && a[i+n] == '?') continue;
				if (a[i+n] != s[i]) return false;
			}
			return true;
		};
		int cnt = 0;
		for (int i = 0; i + 6 < n; ++i) if (f(i, 1)) ++cnt;
		if (cnt > 1) {
			std::cout << "No" << std::endl;
		} else if (cnt == 1) {
			std::cout << "Yes" << std::endl;
			for (auto &x : a) {
				std::cout << (x == '?' ? 'd' : x);
			}
			std::cout << std::endl;
		} else {
			int ci = -1;
			for (int i = 0; i + 6 < n; ++i) {
				if (ci != -1) break;
				if (f(i)) {
					ci = i;
					if (i >= 4 && f(i-4)) ci = -1;
					if (i >= 6 && f(i-6)) ci = -1;
					if (i + 10 < n && f(i+4)) ci = -1;
					if (i + 12 < n && f(i+6)) ci = -1;
				}
			}
			if (ci == -1) {
				std::cout << "No" << std::endl;
			} else {
				std::cout << "Yes" << std::endl;
				for (int i = 0; i < ci; ++ i) {
					std::cout << (a[i] == '?' ? 'd' : a[i]);
				}
				std::cout << s;
				for (int i = ci + 7; i < n; ++i) {
					std::cout << (a[i] == '?' ? 'd' : a[i]);
				}
				std::cout << std::endl;
			}
		}
	}
	return 0;
}