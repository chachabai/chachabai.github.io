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
constexpr int N = 252;
LL fac[N],ifac[N];
void init(){
	fac[0]=1;
	for(int i=1;i<N;++i) fac[i]=fac[i-1]*i%M;
	ifac[N-1] = powmod(fac[N-1],M-2);
	for(int i=N-1;i;--i) ifac[i-1] = ifac[i]*i%M;
}
LL binom(int n,int k){
	return fac[n]*ifac[k]%M*ifac[n-k]%M;
}
int a[N][N];
int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	init();
	int n;
	LL k;
	cin>>n>>k;
	LL r = 0;
	LL c1 = powmod(k,n),c2=powmod(k-1,n),x=1;
	LL c3 = powmod(k,M-2)*(k-1)%M;
	for(int i=0;i<=n;++i){
		r+=x*binom(n,i)*powmod(c1-c2,n)%M;
		x=-x;
		c1=c1*c3%M;
	}
	cout<<(r%M+M)%M<<endl;
	return 0;
}

