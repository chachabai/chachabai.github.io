// https://www.luogu.com.cn/problem/T126268?contestId=28195
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using UI = unsigned int;
const int inf = 2e9+2;
struct Node{
	int id,val,par,ch[2];
	void init(int _id,int _val,int _par){
		id=_id,val=_val,par=_par,ch[0]=ch[1]=0;
	}
};
int cartesian_build(Node* tree,int n){
	for(int i=1;i<=n;++i){
		int k = i-1;
		while(tree[k].val<tree[i].val) k = tree[k].par;
		tree[i].ch[0] = tree[k].ch[1];
		tree[k].ch[1] = i;
		tree[i].par = k;
		tree[tree[i].ch[0]].par = i;
	}
	return tree[0].ch[1];
}
int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	UI a[n+1],s[n+1]={},s1[n+1]={},s2[n+1]={};
	Node tree[n+1];
	tree[0].init(0,inf,0);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		tree[i].init(i,a[i],0);
		s[i] = s[i-1]+a[i];
		s1[i] = s1[i-1] + a[i]*UI(i);
		s2[i] = s2[i-1] + a[i]*UI(i)*UI(i);
	}
	UI sz[n+1];
	function<int(int)> dfs = [&](int x) -> int{
		if(x == 0) return 0;
		sz[x] = 1 +  dfs(tree[x].ch[0]) + dfs(tree[x].ch[1]);
		return sz[x];
	};
	int root = cartesian_build(tree,n);
	dfs(root);
	UI l[n+1],r[n+1];
	function<void(int)> getinterval = [&](int x){
		if(x == 0) return;
		if(tree[tree[x].par].ch[0]==x){
			r[x] = tree[x].par-(tree[x].val != tree[tree[x].par].val);
			l[x] = l[tree[x].par];
		}else{
			l[x] = tree[x].par+(tree[x].val != tree[tree[x].par].val);
			r[x] = r[tree[x].par];
		}
		getinterval(tree[x].ch[0]);
		getinterval(tree[x].ch[1]);
	};
	l[root] = 1;r[root]=n;
	getinterval(tree[root].ch[0]);
	getinterval(tree[root].ch[1]);
	while(q--){
		UI ll,rr,v;
		cin>>ll>>rr>>v;
		UI ans = 0;
		function<void(int)> getans = [&](UI x){
			if(x == 0) return;
			if(a[x]<=v){
				if(ll<=r[x]&&l[x]<=rr){
					UI tl = max(ll,l[x]);
					UI tr = min(rr,r[x]);
					ans += (tl+tr)*(s1[tr]-s1[tl-1]);
					ans -= (tr+1)*(tl-1)*(s[tr]-s[tl-1]);
					ans -= (s2[tr]-s2[tl-1]);
				}
			}else{
				if(ll<=x) getans(tree[x].ch[0]);
				if(rr>=x) getans(tree[x].ch[1]);
			}
		};
		getans(root);
		cout<<ans<<endl;
	}
	return 0;
}