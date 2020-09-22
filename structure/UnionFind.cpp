#pragma once
#include "../template/template.cpp"

class UnionFind{
	using size_type=int32_t;
	size_type N;
	vector<size_type>par,siz;
public:
	size_type find(size_type x){
		assert(x<N);
		return (par[x]==x?x:par[x]=find(par[x]));
	}
	void merge(size_type x,size_type y){
		assert(x<N&&y<N);
		x=find(x);y=find(y);
		if(x==y)return;
		if(siz[x]>siz[y])swap(x,y);
		par[x]=y;siz[y]+=siz[x];
	}
	bool same(size_type x,size_type y){
		return find(x)==find(y);
	}
	size_type size(size_type x){
		return siz[find(x)];
	}
	UnionFind(size_type N):N(N),siz(N,1),par(N){
		iota(all(par),0);
	}
};