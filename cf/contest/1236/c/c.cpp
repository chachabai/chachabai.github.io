#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define watch(x) cout << (#x) << " is " << (x) << endl

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas=1;
	while(cas--){
		int n;
		cin>>n;
		int a[n][n],cx=0,cy=0,step = 0,d=1;
		while(step<n*n){
			a[cx][cy] = ++step;
			cx+=d;
			if(cx == n||cx == -1){
				++cy;
				cx -= d;
				d = -d;
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cout<<a[i][j]<<" \n"[j==n-1];
			}
		}
	}
	return 0;
}

