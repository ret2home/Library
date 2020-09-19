#pragma once
#include "../template/template.cpp"

struct SCC{
	vector<vector<int>>G,rG;
	vector<bool>used;
	vector<int>vs;
	void addEdge(int x,int y){
		G[x].push_back(y);
		rG[y].push_back(x);
	}
	void dfs(int x){
		used[x]=true;
		for(int i:G[x])if(!used[i])dfs(i);
		vs.push_back(x);
	}
	vector<int>cmp;
	void rdfs(int v,int k){
		used[v]=true;
		cmp[v]=k;
		for(int i:rG[v])if(!used[i])rdfs(i,k);
	}
	void scc(){
		fill(all(used),false);
		rep(i,len(G))if(!used[i])dfs(i);
		fill(all(used),false);
		int k=0;
		rev(i,len(vs))if(!used[vs[i]])rdfs(vs[i],k++);
	}
	SCC(int N):G(N),rG(N),used(N),cmp(N){}
};
