#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin)
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	cin>>cas;
	// cas = 1;
	while(cas--){
		int n;
		cin>>n;
		int a[n],v[n],c[n+1]={},step=n;
		for(int i=0;i<n;++i){
			cin>>a[i];
			++c[a[i]];
			v[i] = (a[i]==i);
			if(v[i]) --step;
		}
		vector<int> q;
		int mex = 0,l=0;
		while(c[mex]) ++mex;
		while(step--){
			if(mex == n){
				while(v[l]) ++l;
				q.push_back(l+1);
				--c[a[l]];
				++c[mex];
				mex = a[l];
				a[l] = n;
			}
			++c[mex];
			int nmex = mex;
			if(--c[a[mex]]==0&&a[mex]<mex){
				nmex = a[mex];
			}
			a[mex] = mex;
			v[mex] = true;
			q.push_back(mex+1);
			mex = nmex;
			while(c[mex]) ++mex;
		}
		cout<<q.size()<<endl;
		for(auto &x:q) cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}

