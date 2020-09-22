#pragma once
#include "../template/template.cpp"
#include "PersistentArray.cpp"

struct PersistentUnionFind{
	using node=PersistentArray<P>::Node;
	PersistentArray<P>data;
	P find(int x,node *t){
		P p=data.get(x,t);
		if(p.first==x)return p;
		p=find(p.first,t);
		data.set(x,p,t);
		return p;
	}
	bool same(int x,int y,node *t){
		return find(x,t)==find(y,t);
	}
	int size(int x,node *t){
		return data.get(find(x,t).first,t).second;
	}
	node* merge(int x,int y,node *t){
		P u=find(x,t),v=find(y,t);
		if(u.first==v.first)return new node(*t);
		if(u.second>v.second)swap(u,v);
		node *res=data.set(u.first,{v.first,u.second},t);
		node *res2=data.set(v.first,{v.first,u.second+v.second},res);
		delete(res);
		return res2;
	}
	node* init(int x){
		node* root=new node();
		rep(i,x){
			data.destructive_set(i,{i,1},root);
		}
		return root;
	}
};