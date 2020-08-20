#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL M = 998244353,ROOT=3;
LL powmod(LL x,LL n){
	LL r(1);
	while(n){
		if(n&1) r=r*x%M;
		n>>=1; x=x*x%M;
	}
	return r;
}
void bitreverse(vector<LL> &a){
	for(int i=0,j=0;i!=a.size();++i){
		if(i>j) swap(a[i],a[j]);
		for(int l=a.size()>>1;(j^=l)<l;l>>=1);
	}
}
void nft(vector<LL> &a,bool isInverse=false){
	LL g = powmod(ROOT,(M-1)/a.size());
	if(isInverse){
		g = powmod(g,M-2);
		LL invLen = powmod(LL(a.size()),M-2);
		for(auto &x:a) x=x*invLen%M;
	}
	bitreverse(a);
	vector<LL> w(a.size(),1);
	for(int i=1;i!=w.size();++i) w[i] = w[i-1]*g%M;
	auto addMod = [](LL x,LL y){return (x+=y)>=M?x-=M:x;};
	for(int step=2,half = 1;half!=a.size();step<<=1,half<<=1){
		for(int i=0,wstep=a.size()/step;i!=a.size();i+=step){
			for(int j=i;j!=i+half;++j){
				LL t = (a[j+half]*w[wstep*(j-i)])%M;
				a[j+half]=addMod(a[j],M-t);
				a[j]=addMod(a[j],t);
			}
		}
	}
}
vector<LL> mul(vector<LL> a,vector<LL> b){
	int sz=1,tot = a.size()+b.size()-1;
	while(sz<tot) sz*=2;
	a.resize(sz);b.resize(sz);
	nft(a);nft(b);
	for(int i=0;i!=sz;++i) a[i] = a[i]*b[i]%M;
	nft(a,1);
	a.resize(tot);
	return a;
}
constexpr int N = 3e5+2;
LL fac[N],ifac[N];
void init(){
	fac[0]=1;
	for(int i=1;i<N;++i) fac[i] = fac[i-1]*i%M;
	ifac[N-1] = powmod(fac[N-1],M-2);
	for(int i=N-1;i;--i) ifac[i-1] = ifac[i]*i%M;
}
LL binom(int n,int k){
	return fac[n]*ifac[k]%M*ifac[n-k]%M;
}

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	init();
	int n,k,x,q;
	cin>>n>>k;
	int cnt[N] = {};
	for(int i=0;i<n;++i){
		cin>>x;
		++cnt[x];
	}
	vector<LL> ans(2*N);
	while(k--){
		cin>>x;
		int c1=0,c2=0;
		for(int i=1;i<x;++i){
			if(cnt[i]>1) c2+=2;
			else if(cnt[i]==1) ++c1;
		}
		vector<LL> a(c1+1),b(c2+1);
		auto inc = [](LL &a,LL b){if((a+=b)>=M) a-=M;};
		LL p2=1;
		for(int i=0;i<=c1;++i){
			a[i] = binom(c1,i)*p2%M;
			inc(p2,p2);
		}
		for(int i=0;i<=c2;++i) b[i] = binom(c2,i);
		a = mul(a,b);
		for(int i=0;i!=a.size();++i){
			inc(ans[i+x+1],a[i]);
		}
	}
	cin>>q;
	while(q--){
		cin>>x;
		cout<<ans[x/2]<<endl;
	}
	return 0;
}