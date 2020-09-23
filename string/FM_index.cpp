#pragma once
#include "../template/template.cpp"
#include "../structure/WaveletMatrix.cpp"
#include "BWT.cpp"

template<class T,class C>
class FMIndex{
    ll N,base;
    T bwt;
    vector<ll>c;
    WaveletMatrix<T,C>WM;
    SuffixArray<T>SA;
    public:
    T ST;
    P occ(T &S){
        for(auto i:S)if((ll)i<base||(ll)i-base>=len(c))return P(0,0);
        ll sp=0,ep=N;
        rev(i,len(S)){
            sp=c[(ll)S[i]-base]+WM.rank(S[i],sp);
            ep=c[(ll)S[i]-base]+WM.rank(S[i],ep);
            if(sp>=ep)return P(0,0);
        }
        return P(sp,ep);
    }
    vector<ll>locate(T &S){
        vector<bool>v(len(ST)+1);
		P range=occ(S);
		for(ll i=range.first;i<range.second;i++)v[SA[i]]=true;
		vector<ll>res;
		rep(i,len(ST)+1)if(v[i])res.emplace_back(i);
		return res;
    }
    FMIndex(T S):N(len(S)+1),ST(S+'$'),WM("",0),SA(S){
        bwt=BWT(S,SA);
        WM=WaveletMatrix<T,C>(bwt,8);
        ll mn=inf,mx=-inf;
        for(C i:ST){
            chmin(mn,(ll)i);
            chmax(mx,(ll)i);
        }
        c.resize(mx-mn+2);
        for(C i:ST){
            c[(ll)i-mn+1]++;
        }
        rep(i,mx-mn+1)c[i+1]+=c[i];
        base=mn;
    }
};