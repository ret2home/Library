#pragma once
#include "../template/template.cpp"

struct HLD{
    vector<vector<int>>G;
    vector<int>sz,in,out,top,par,depth;
    void dfs_sz(int x,int p){
        sz[x]=1;
        int mx=0;
        for(int &i:G[x])if(i!=p){
            dfs_sz(i,x);
            sz[x]+=sz[i];
            if(chmax(mx,sz[i]))swap(G[x][0],i);
        }
    }
    int t=0;
    void dfs_hld(int x,int p){
        in[x]=t++;
        for(int i:G[x])if(i!=p){
            if(i!=G[x][0]){
                par[i]=x;
                top[i]=i;
                depth[i]=depth[x]+1;
            }else {
                par[i]=par[x];
                top[i]=top[x];
                depth[i]=depth[x];
            }
            dfs_hld(i,x);
        }
        out[x]=t;
    }
    HLD(vector<vector<int>>&G):G(G){
        int N=len(G);
        sz.resize(N);
        in.resize(N);out.resize(N);
        par.resize(N);top.resize(N);depth.resize(N);
        dfs_sz(0,0);dfs_hld(0,0);
    }
};