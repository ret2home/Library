#pragma once
#include "../template/template.cpp"
#include "BitVector.cpp"

template<class T,class C>
class WaveletMatrix{
    ll N,bitlen;
    vector<BitVector>index;
    vector<ll>st;
public:
    T body;
    ll rank(C c,ll idx){
        if(st[c]==-1)return 0;
        rev(i,bitlen){
            if(c>>i&1)idx=index[i].rank(1,idx)+index[i].rank(0,N);
            else idx-=index[i].rank(1,idx);
        }
        return max(0,idx-st[c]);
    }
    ll quantile(ll l,ll r,ll c){
        ll res=0;
        rev(i,bitlen){
            ll cnt=(r-l)-(index[i].rank(1,r)-index[i].rank(1,l));
            if(cnt<=c){
                c-=cnt;
                l=index[i].rank(0,N)+index[i].rank(1,l);
                r=index[i].rank(0,N)+index[i].rank(1,r);
                res+=1<<i;
            }else {
                l-=index[i].rank(1,l);
                r-=index[i].rank(1,r);
            }
        }
        return res;
    }
    WaveletMatrix(T V,ll bitlen):N(len(V)),bitlen(bitlen),body(V){
        vector<bool>bit(N);
        index.resize(bitlen,bit);
        rev(i,bitlen){
            T newV[2];
            rep(j,N){
                bit[j]=(V[j]>>i&1);
                newV[V[j]>>i&1].push_back(V[j]);
            }
            V=newV[0];V.insert(V.end(),all(newV[1]));
            index[i]=BitVector(bit);
        }
        st.assign(256,-1);
        rep(i,N)if(st[V[i]]==-1)st[V[i]]=i;
    }
};