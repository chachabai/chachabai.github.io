#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL M = 1e9+7;
LL inv(LL a,LL p){
    return a==1?1:(p-p/a)*inv(p%a,p)%p;
}
LL C(LL n, int k){
	if(n<k) return 0;
	if(k==0) return 1;
	LL r = 1;
	for(int i=0;i<k;++i){
		r = r*(n-i)%M*inv(i+1,M)%M;
	}
	return r;
}
int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	cin >> cas;
	while(cas--){
		LL n ,r = 0;
		cin >> n;
		for(int i=(n+1)%2;i<=11;i+=2) {
			r+=C(11,i)*C((n-i+25)/2,15)%M;
		}
		cout<<r%M<<endl;
	}
	return 0;
}