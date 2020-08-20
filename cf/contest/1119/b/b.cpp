#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin)
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n,h;
	cin>>n>>h;
	int a[n];
	for(int i=0;i<n;++i) cin>>a[i];
	vector<int> q;
	int r = 0;
	for(int i=0;i<n;++i){
		auto it = lower_bound(q.begin(),q.end(),a[i]);
		q.insert(it,a[i]); 
		int s = 0;
		for(int i=q.size()-1;i>=0;i-=2) s+=q[i];
		if(s>h) break;
		++r;
	}
	cout<<r<<endl;
	return 0;
}

