#pragma once
#include "../template/template.cpp"

struct Tree{
	vector<ll>depth;
	vector<vector<ll>>G;
	vector<ll>par[20];
	void dfs(ll x,ll p){
		for(ll i:G[x])if(i!=p){
			depth[i]=depth[x]+1;
			par[0][i]=x;
			dfs(i,x);
		}
	}
	ll lca(ll x,ll y){
		if(depth[x]>depth[y])swap(x,y);
		rep(i,20)if((depth[y]-depth[x])>>i&1)y=par[i][y];
		if(x==y)return x;
		for(ll i=19;i>=0;i--)if(par[i][x]!=par[i][y]){
			x=par[i][x];y=par[i][y];
		}
		return par[0][x];
	}
	Tree(vector<vector<ll>>G,ll root=0):G(G){
		ll N=G.size();
		depth.resize(N);
		rep(i,20)par[i].resize(N);
		dfs(root,root);
		rep(i,19)rep(j,N){
			if(par[i][j]==-1)par[i+1][j]=-1;
			else par[i+1][j]=par[i][par[i][j]];
		}
	}
};