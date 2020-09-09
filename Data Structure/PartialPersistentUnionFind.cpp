#pragma once
#include "../template/template.cpp"

struct PartialPersistentUnionFind{
	int version=0;
	vector<int>tim,par;
	vector<vector<P>>siz;
	int find(int x,int t){
		if(tim[x]>t)return x;
		return find(par[x],t);
	}
	int same(int x,int y,int t){
		return find(x,t)==find(y,t);
	}
	int size(int x,int t){
		x=find(x,t);
		return (--upper_bound(all(siz[x]),P(t,inf)))->second;
	}
	void merge(int x,int y){
		version++;
		x=find(x,version);
		y=find(y,version);
		if(x==y)return;
		int sx=size(x,version),sy=size(y,version);
		if(sx>sy)swap(x,y);
		tim[x]=version;par[x]=y;
		siz[y].push_back({version,sx+sy});
	}
	PartialPersistentUnionFind(int x):tim(x,inf){
		siz.resize(x);
		rep(i,x){
			par.push_back(i);
			siz[i].push_back(P(0,1));
		}
	}
};
