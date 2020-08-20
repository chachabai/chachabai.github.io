#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl
const int N = 2e5+4;
int a[N],p[N],b[N];
int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int cas;
	int n, m, k;
	LL x, y;
	cin >> n >> m >> x >> k >> y;
	x = min(x,k*y);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[a[i]] = i;
	}
	bool flag = true;
	int cur = 0;
	for(int i = 1, x; i <= m; ++i) {
		cin >> x;
		b[i] = p[x];
		if(p[x] <= cur){
			bool flag = false;
		}else{
			cur = p[x];
		}
	}
	if(flag){
		cout << -1 << endl;
		continue;
	}
	auto f = [&](int l,int r) -> LL {
		return (r-l)/k*x+(r-l)%k*y;
	}
	LL r = 0;
	for(int i = 1; i <= n; ++i) {
		r+=f(b[i-1]+1,b[i]);
	}
	cout << r << endl;
	return 0;
}
