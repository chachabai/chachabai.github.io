#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n;
	cin>>n;
	int p[n+1],a[n+1];
	for(int i=1;i<=n;++i){
		cin>>a[i];
		p[a[i]]=i;
	}
	vector<pair<int,int>> q;
	for(int i=1;i<=n;++i){
		if(a[i]==i) continue;
		if(i>n/2){
			q.push_back({1,i});
			q.push_back({1,p[i]});
			q.push_back({1,i});
		}else if(p[i]>n/2){
			q.push_back({1,p[i]});
			if(i>1){
				q.push_back({i,n});
				q.push_back({1,n});
				q.push_back({i,n});
				q.push_back({1,p[i]});
			}
		}else{
			q.push_back({n,i});
			q.push_back({n,p[i]});
			q.push_back({n,i});
		}
		p[a[i]] = p[i];
		a[p[i]] = a[i];
	}
	cout<<q.size()<<endl;
	for(auto &[x,y]:q) cout<<x<<" "<<y<<endl;
	cout<<endl;
	return 0;
}

