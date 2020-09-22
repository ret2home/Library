#pragma once
#include "../template/template.cpp"

class UnionFind{
	size_t N;
	vector<size_t>par,siz;
public:
	size_t find(size_t x){
		assert(x<N);
		return (par[x]==x?x:par[x]=find(par[x]));
	}
	void merge(size_t x,size_t y){
		assert(x<N&&y<N);
		x=find(x);y=find(y);
		if(x==y)return;
		if(siz[x]>siz[y])swap(x,y);
		par[x]=y;siz[y]+=siz[x];
	}
	bool same(size_t x,size_t y){
		return find(x)==find(y);
	}
	size_t size(size_t x){
		return siz[find(x)];
	}
	UnionFind(size_t N):N(N),siz(N,1),par(N){
		iota(all(par),0);
	}
};