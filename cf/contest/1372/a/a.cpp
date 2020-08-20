#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int cas;
	cin >> cas;
	while (cas--) {
		int n;
		cin >> n;
		for (int i=0; i<n; ++i){
			cout << 1 << " \n"[i==n-1];
		}
	}
	return 0;
}

