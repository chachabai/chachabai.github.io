#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e5+2;
int f[N],g[N],r[N],h[N];
void init(int *a, int n,int mod) {
	if(mod <= 0) return;
	a[0] = 1%mod;
	for(int i=1;i<n;++i) a[i]=a[i-1]*2%mod;
}
int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	for(int i=1;i<N;++i){
		h[i] = h[i%__builtin_popcount(i)]+1;
	}
	string s;
	int n;
	cin >> n >> s;
	int cnt = 0;
	for(auto &c:s) if(c=='1') ++cnt;
	init(f,n,cnt+1);
	init(g,n,cnt-1);
	auto inc = [](int &x,int y,int mod){
		if((x+=y)>=mod && (mod > 0)) x-=mod;
	};
	int rf = 0, rg = 0;
	for(int i=0; i<n; ++i) if(s[i]=='1'){
		inc(rf,f[n-1-i],cnt+1);
		inc(rg,g[n-1-i],cnt-1);
	}
	for(int i=0;i<n;++i){
		if(s[i]=='0'){
			int x = f[n-1-i];
			inc(x,rf,cnt+1);
			r[i] = h[x]+1;
		}else{
			int x = cnt-1 - g[n-1-i];
			inc(x,rg,cnt-1);
			if(cnt==1) r[i]=0;
			else r[i] = h[x]+1;
		}
	}
	for (int i=0;i<n;++i) {
		cout<<r[i]<<endl;
	}
	return 0;
}