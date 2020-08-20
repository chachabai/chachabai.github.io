#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl
constexpr LL M = 1000000007;
LL powmod(LL x,LL n){
	LL r = 1;
	while(n){
		if(n&1) r=r*x%M;
		n>>=1;  x=x*x%M;
	}
	return r;
}

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	LL x,n;
	cin>>x>>n;
	auto f = [](LL n,LL p){
		LL r = 0;
		while(n){
			r+=n/p;
			n/=p;
		}
		return r;
	};
	auto g = [](LL x){
		vector<LL> a;
		for(LL i=2;i*i<=x;++i){
			if(x%i==0){
				a.emplace_back(i);
				while(x%i==0) x/=i;
			}
		}
		if(x>1) a.emplace_back(x);
		return a;
	};
	LL r = 1;
	for(auto &p:g(x)){
		r = r*powmod(p,f(n,p))%M;
	}
	cout<<r<<endl;
	return 0;
}

