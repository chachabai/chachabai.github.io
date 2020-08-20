// https://www.luogu.com.cn/problem/T134867?contestId=31074
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const LL M = 998244353;
const int N = 132;
LL f[N],invf[N];
LL pow_mod(LL x,LL n){
	LL r = 1;
	while(n){
		if(n&1) r=r*x%M;
		n>>=1; x=x*x%M;
	}
	return r;
}
void init(){
	f[0]=1;
	for(int i=1;i<N;++i) f[i]=f[i-1]*i%M;
	invf[N-1] = pow_mod(f[N-1],M-2);
	for(int i=N-2;i>=0;--i) invf[i] = invf[i+1]*(i+1)%M;
}
LL C(int n,int k){
	if(k>n) return 0;
	return f[n]*invf[n-k]%M*invf[k]%M;
}
int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	init();
	string ss;
	cin>>ss;
	vector<int> s={0};
	for(auto &c:ss) s.emplace_back(c-'0');
	auto plusOne = [&](int l,int r){
		int id = r-1;
		while(s[id]==9) --id;
		++s[id];
		for(int i=id+1;i<r;++i) s[i] = 0;
	};
	auto minusOne = [&](int l,int r){
		int id = r-1;
		while(s[id]==0) --id;
		--s[id];
		for(int i=id+1;i<r;++i) s[i] = 9;
	};
	function<map<int,LL>(int,int)> f = [&](int l,int r) -> map<int,LL>{
		if(all_of(s.begin()+l,s.begin()+r,[](int x){ return x == 0;})){
			return map<int,LL>{{0,1}};
		}
		map<int,LL> ret;
		for(int i=l;i<r;++i){
			if(s[i]){
				int x = s[i];
				s[i]=0;
				if(x>4) plusOne(l,i);
				for(auto &ia:f(l,i)){
					for(auto &ib:f(i,r)){
						int t1 = 1+ia.first+ib.first;
						LL t2 = ia.second*ib.second%M*C(ia.first+ib.first,ia.first)%M;
						if(ret.find(t1)==ret.end()){
							ret[t1] = t2;
						}else ret[t1] = (ret[t1]+t2)%M;
					}
				}
				if(x>4) minusOne(l,i);
				s[i]=x;
			}
		}
		return ret;
	};
	LL res = 0;
	for(auto &x:f(0,s.size())){
		//cout<<x.first<<" "<<x.second<<endl;
		res+=x.second;
	}
	cout<<res%M<<endl;
	return 0;
}