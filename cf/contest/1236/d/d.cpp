#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	cin>>cas;
	while(cas--){
		int n,m,k;
		cin>>n>>m>>k;
		vector<pair<int,int>> c(k),r(k);
		for(int i=0,x,y;i<k;++i){
			cin>>x>>y;
			c[i] = {x,y};
			r[i] = {y,x};
		}
		sort(c.begin(),c.end());
		sort(r.begin(),r.end());
		vector<int> a[2][max(n,m)+1];
		for(auto &[x,y]:c){
			a[1][x].emplace_back(y);
		}
		for(auto &[y,x]:r){
			a[0][y].emplace_back(x);
		}
		int d = 1,cur[2] = {1,1};
		bool v[2][max(n,m)+1]={},flag = true;
		while(1){
			auto it = lower_bound(a[d%2][cur[d%2]].begin(),a[d%2][cur[d%2]].end(),cur[1-d%2]);
			if(it == a[d%2][cur[d%2]].end()){
				cur 
			}
		}
	}
	return 0;
}

