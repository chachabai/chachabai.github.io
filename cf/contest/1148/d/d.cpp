#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
using namespace std;
using LL = long long;
int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n,x,y;
	cin>>n;
	vector<tuple<int,int,int>> a,b;
	for(int i=1;i<=n;++i){
		cin>>x>>y;
		if(x<y) a.push_back({y,x,i});
		else if(x>y) b.push_back({x,y,i});
	}
	if(a.size()<b.size()){
		cout<<b.size()<<endl;
		sort(b.begin(),b.end());
		for(auto &[x,y,id]:b) cout<<id<<" ";
	}else{
		sort(a.begin(),a.end(),greater<tuple<int,int,int>>());
		cout<<a.size()<<endl;
		for(auto &[x,y,id]:a) cout<<id<<" ";
	}
	return 0;
}