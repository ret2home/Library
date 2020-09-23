#pragma once
#include "../template/template.cpp"

struct HLD{
	using V=vector<pair<ll,P>>;
	struct heavy_set{
		vector<ll>ele;
		ll depth,par,cost1=1,cost2=1;
		heavy_set(ll v,ll d,ll par)
		:ele(1,v),depth(d),par(par){}
	};
	vector<vector<ll>>G;
	vector<heavy_set>S;
	vector<ll>subsize,stidx,eleidx;
	ll subtree(ll v,ll p){
		ll &sz=subsize[v];
		if(sz)return sz;
		sz=1;
		for(ll i:G[v])if(i!=p)sz+=subtree(i,v);
		return sz;
	}
	void make_path(ll v,ll p,ll id){
		stidx[v]=id;
		eleidx[v]=S[id].ele.size()-1;
		ll mxidx,mx=0;
		for(ll i:G[v])if(i!=p){
			if(mx<subtree(i,v)){
				mx=subtree(i,v);mxidx=i;
			}
		}
		for(ll i:G[v])if(i!=p){
			if(mxidx==i){
				S[id].ele.push_back(i);
				make_path(i,v,id);
			}else {
				S.emplace_back(i,S[id].depth+1,v);
				make_path(i,v,S.size()-1);
			}
		}
	}
	ll st(ll v){return stidx[v];}
	ll el(ll v){return eleidx[v];}
	HLD(vector<vector<ll>>&G):G(G){
		ll N=G.size();
		subsize.resize(N);
		eleidx.resize(N);
		stidx.resize(N);
		S.emplace_back(0,0,0);
		make_path(0,0,0);
	}
};
