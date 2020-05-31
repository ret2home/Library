#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back
#define fi first
#define se second

template<class T> inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
void cmps(vector<int>&v,int &i){
	i=lower_bound(all(v),i)-v.begin();
}
constexpr int mod = 998244353;
constexpr int inf = LLONG_MAX;

struct Tree{
	vector<int>depth;
	vector<vector<int>>G;
	vector<int>par[20];
	void dfs(int x,int p){
		for(int i:G[x])if(i!=p){
			depth[i]=depth[x]+1;
			par[0][i]=x;
			dfs(i,x);
		}
	}
	int lca(int x,int y){
		if(depth[x]>depth[y])swap(x,y);
		rep(i,20)if((depth[y]-depth[x])>>i&1)y=par[i][y];
		if(x==y)return x;
		for(int i=19;i>=0;i--)if(par[i][x]!=par[i][y]){
			x=par[i][x];y=par[i][y];
		}
		return par[0][x];
	}
	Tree(vector<vector<int>>G,int root=0):G(G){
		int N=G.size();
		depth.resize(N);
		rep(i,20)par[i].resize(N);
		dfs(root,root);
		rep(i,19)rep(j,N){
			if(par[i][j]==-1)par[i+1][j]=-1;
			else par[i+1][j]=par[i][par[i][j]];
		}
	}
};
signed main(){
	int N,Q;
	cin>>N>>Q;
	vector<vector<int>>G(N);
	REP(i,N){
		int a;cin>>a;G[a].pb(i);
	}
	Tree tree(G);
	while(Q--){
		int u,v;cin>>u>>v;
		cout<<tree.lca(u,v)<<endl;
	}
}

