#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n;
	string a,b;
	cin>>n>>a>>b;
	vector<int> p,q;
	for(int i=0;i<n;++i){
		if(a[i]==b[i]) continue;
		if(a[i]=='a') p.emplace_back(i+1);
		else q.emplace_back(i+1);
	}
	if((p.size()+q.size())&1){
		cout<<-1<<endl;
		return 0;
	}
	vector<pair<int,int>> r;
	for(int i=0;i+1<p.size();i+=2){
		r.push_back({p[i],p[i+1]});
	}
	for(int i=0;i+1<q.size();i+=2){
		r.push_back({q[i],q[i+1]});
	}
	if(p.size()&1){
		r.push_back({p.back(),p.back()});
		r.push_back({p.back(),q.back()});
	}
	cout<<r.size()<<endl;
	for(auto &[x,y]:r) cout<<x<<" "<<y<<endl;
	return 0;
}

