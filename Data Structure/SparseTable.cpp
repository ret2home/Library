#pragma once
#include "../template/template.cpp"

template<class T>
struct SparseTable{
	using F=function<T(T,T)>;
	vector<T>table[20];
	vector<int>log;
	F f;
	SparseTable(vector<T>v,F f)
	:log(v.size()+1),f(f){
		int mx=0;
		while(1ll<<(mx+1)<=(int)v.size())++mx;
		rep(i,mx+1){
			table[i].resize(v.size());
			rep(j,v.size()-(1<<i)+1){
				if(i)table[i][j]=f(table[i-1][j],table[i-1][j+(1ll<<(i-1))]);
				else table[i][j]=v[j];
			}
		}
		for(int i=2;i<=(int)v.size();i++)log[i]=log[i>>1]+1;
	}
	T query(int l,int r){
		return f(table[log[r-l]][l],table[log[r-l]][r-(1<<log[r-l])]);
	}
};
