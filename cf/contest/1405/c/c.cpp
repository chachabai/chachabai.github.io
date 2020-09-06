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
		int n, k;
		std::cin >> n >> k;
		std::string s;
		std::cin >> s;
		std::vector<int> a(k, -1);
		bool flag = true;
		for (int i = 0; i < n; ++i) if (s[i] != '?') {
			int t = s[i] - '0';
			if (a[i % k] == -1) {
				a[i % k] = t;
			} else if (a[i % k] != t){
				flag = false;
				break;
			}
		}
		if (flag) {
			int c[2] = {};
			for (int i = 0; i < k; ++i) if (a[i] != -1) {
				++c[a[i]];
			}
			if (c[0] * 2 > k || c[1] * 2 > k) flag = false;
		}
		std::cout << (flag ? "YES" : "NO") << std::endl;
	}
	return 0;
}