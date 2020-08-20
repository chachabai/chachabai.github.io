#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl
int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, m, k;
	LL x, y;
	cin >> n >> m >> x >> k >> y;
	int a[n+2]={}, p[n+2]={}, b[m+2]={};
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[a[i]] = i;
	}
	bool flag = true;
	for (int i = 1, t, cur = 0; i <= m; ++i) {
		cin >> t;
		if((b[i] = p[t]) <= cur) {
			flag = false;
		} else {
			cur = b[i];
		}
	}
	b[m + 1] = n + 1;
	if (!flag) {
		cout << -1 << endl;
		return 0;
	}
	auto f = [&](int l, int r) -> LL {
		if(l == r)  return 0;
		int mx = *max_element(a+l,a+r), n = r-l;
		LL ans = 0;
		if (mx > max(a[l-1],a[r])) {
			if(r - l < k) return -1;
			n -= k;
			ans += x;
		}
		return ans + min(n / k * x, n / k * k * y) + n % k * y;
	};
	LL r = 0;
	for (int i = 1; i <= m+1; ++i) {
		LL cur = f(b[i-1]+1,b[i]);
		if(cur == -1){
			flag = false;
			break;
		}
		r += cur;
	}
	
	cout << (flag?r:-1) << endl;
	return 0;
}

