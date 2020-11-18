#pragma once
#include "../template/template.cpp"

struct HLD{
	struct heavy_set{
		vector<int>ele;
		int depth,par,cost1=0,cost2=0;
		heavy_set(int v,int d,int par)
		:ele(1,v),depth(d),par(par){}
	};
	vector<vector<int>>G;
	vector<heavy_set>S;
	vector<int>subsize,stidx,eleidx;
	int subtree(int v,int p){
		int &sz=subsize[v];
		if(sz)return sz;
		sz=1;
		for(int i:G[v])if(i!=p)sz+=subtree(i,v);
		return sz;
	}
	void make_path(int v,int p,int id){
		stidx[v]=id;
		eleidx[v]=S[id].ele.size()-1;
		int mxidx,mx=0;
		for(int i:G[v])if(i!=p){
			if(mx<subtree(i,v)){
				mx=subtree(i,v);mxidx=i;
			}
		}
		for(int i:G[v])if(i!=p){
			if(mxidx==i){
				S[id].ele.push_back(i);
				make_path(i,v,id);
			}else {
				S.emplace_back(i,S[id].depth+1,v);
				make_path(i,v,S.size()-1);
			}
		}
	}
	int st(int v){return stidx[v];}
	int el(int v){return eleidx[v];}
	HLD(vector<vector<int>>&G):G(G){
		int N=G.size();
		subsize.resize(N);
		eleidx.resize(N);
		stidx.resize(N);
		S.emplace_back(0,0,0);
		make_path(0,0,0);
	}
};
