// https://www.luogu.com.cn/problem/T137255?contestId=31074
// 裸线段树，注意到 次方要模(M-1)而非M
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const LL M = 998244353;
#define lrt rt<<1
#define rrt rt<<1|1
#define lson l,m,lrt
#define rson m+1,r,rrt
const int N = 1e5+2;
LL a[N*3],p[N*3],c[N*3];
LL powmod(LL x,LL n){
	LL r = 1;
	while(n){
		if(n&1) r=r*x%M;
		n>>=1;  x=x*x%M;
	}
	return r;
}
void build(int l,int r,int rt){
	c[rt]=1;p[rt]=1;
	if(l==r){
		cin>>a[rt];
		return;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
}
void pushDown(int rt){
	if(p[rt]!=1){
		p[lrt] = p[lrt]*p[rt]%(M-1);
		p[rrt] = p[rrt]*p[rt]%(M-1);
		c[lrt] = powmod(c[lrt],p[rt]);
		c[rrt] = powmod(c[rrt],p[rt]);
		p[rt] = 1;
	}
	if(c[rt]!=1){
		c[lrt] = c[lrt]*c[rt]%M;
		c[rrt] = c[rrt]*c[rt]%M;
		c[rt] = 1;
	}
}
void update(int L,int R,LL x,LL y,int l,int r,int rt){
	if(L<=l&&R>=r){
		p[rt] = p[rt]*x%(M-1);
		c[rt] = powmod(c[rt],x)*y%M;
		return;
	}
	pushDown(rt);
	int m = (l+r)>>1;
	if(L<=m) update(L,R,x,y,lson);
	if(R>m)  update(L,R,x,y,rson);
}
LL query(int z,int l,int r,int rt){
	if(l==r){
		return powmod(a[rt],p[rt])*c[rt]%M;
	}
	pushDown(rt);
	int m=(l+r)>>1;
	if(z<=m) return query(z,lson);
	return query(z,rson);
}
int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	build(1,n,1);
	while(m--){
		int q,l,r,y,z;
		cin>>q;
		if(q==1){
			LL x;
			cin>>l>>r>>x;
			update(l,r,x,1,1,n,1);
		}else if(q==2){
			cin>>l>>r>>y;
			update(l,r,1,query(y,1,n,1),1,n,1);
		}else{
			cin>>z;
			cout<<query(z,1,n,1)<<endl;
		}
	}
	return 0;
}