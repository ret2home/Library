#pragma once
#include "../template/template.cpp"

struct UnionFind{
	vector<int>par,size;
	int find(int x){
		return (par[x]==x?x:par[x]=find(par[x]));
	}
	void merge(int x,int y){
		x=find(x);y=find(y);
		if(x==y)return;
		if(size[x]>size[y])swap(x,y);
		par[x]=y;
		size[y]+=size[x];
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	UnionFind(int x):size(x,1),par(x){
		iota(all(par),0);
	}
};