#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	LL r = 0;
	for (int i = 1; i < n; ++i) if (a[i] < a[i - 1]) {
		r += a[i - 1] - a[i];
		a[i] = a[i - 1];
	}
	std::cout << r << std::endl;
	return 0;
}