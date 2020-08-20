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
		int r = n;
		for(int i=2; i*i <= n; ++i){
			if(n%i == 0){
				r = i;
				break;
			}
		}
		cout<<n/r<<" "<<n-n/r<<endl;
	}
	return 0;
}

