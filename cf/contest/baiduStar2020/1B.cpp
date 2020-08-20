#include <bits/stdc++.h>
using LL = long long;
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
const int N = 402;
double a[N];
void init() {
	double x[] = {2.7, 3.0, 3.3, 3.7, 4.0, 4.3, 4.3, 4.3};
	auto f = [&](int n) -> double {
		if (n >= 70) return x[(n-70)/5];
		if (n >= 67) return 2.3;
		if (n >= 65) return 2.0;
		if (n >= 62) return 1.7;
		if (n >= 60) return 1.0;
		return 0.0;
	};
	auto cmax = [](double &x, double y) {
		if(x < y) x = y;
	};
	for(int i = 0; i< N; ++i) a[i] = 0.0;
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= i; ++j) {
			for (int k = 0; k <= j; ++k) {
				for (int t = 0; t <= k; ++t) {
					cmax(a[i+j+k+t], f(i) + f(j) + f(k) + f(t));
				}
			}
		}
	}
}

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	init();
	while (cas--) {
		int n;
		std::cin >> n;
		std::cout << std::fixed << std::setprecision(1) << a[n] << std::endl;
	}
	return 0;
}