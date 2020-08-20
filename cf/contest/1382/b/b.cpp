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
		int n;
		std::cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
		}
		bool flag = false;
		for (int i = n - 1 ; i >= 0; --i) {
			if (a[i] == 1) flag = !flag;
			else flag = true;
		}
		std::cout << (flag ? "First" : "Second") << std::endl;
	}
	return 0;
}