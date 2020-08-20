#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	cin>>cas;
	while(cas--){
		int n;
		cin>>n;
		vector<int> a[n];
		for(int i=0,x,y;i<n;++i){
			cin>>x>>y;
			a[x].emplace_back(y);
		}
		LL r = 0;
		priority_queue<int,vector<int>,greater<int>> q; //白嫖的votes
		for(int i=n-1;i>=0;--i){
			for(auto &x:a[i]) q.push(x);
			while(n-q.size()<i){
				r+=q.top();
				q.pop();
			}
		}
		cout<<r<<endl;
	}
	return 0;
}