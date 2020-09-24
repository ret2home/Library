#pragma once
#include "../template/template.cpp"
#include "./SuffixArray.cpp"

template<class T>
T BWT(T S,SuffixArray<T>&SA){
    S+='$';
    T bwt;
    rep(i,len(S)){
        bwt.push_back(S[(SA[i]-1+len(S))%len(S)]);
    }
    return bwt;
}

template<class T>
T BWTInverse(T S){
    vector<ll>B(len(S));
    ll mx=-inf;
    rep(i,len(S)){
        B[i]=(S[i]=='$'?0:(ll)S[i]);
        chmax(mx,B[i]);
    }
    vector<vector<ll>>BB(mx+1),F(mx+1);
    vector<P>V;
    rep(i,len(S)){
        BB[B[i]].push_back(i);
        F[B[i]].push_back(i);
    }
    ll cnt=0;
    rep(i,mx+1){
        rep(j,len(F[i])){
            F[i][j]=cnt++;
            V.push_back({i,j});
        }
    }
    ll now=BB[0][0];
    T res;
    rep(i,len(S)-1){
        res.push_back(V[now].first);
        now=BB[V[now].first][V[now].second];
    }
    return res;
}
/*
@brief Burrows Wheeler Transform
@docs docs/BWT.md
*/