#pragma once
#include "../template/template.cpp"

struct Mo{
    vector<int>left,right,order;
    vector<bool>v;
    int width,l=0,r=0,cur=0;
    Mo(int n):width(sqrt(n)),v(n){}
    void insert(int l,int r){
        left.push_back(l);right.push_back(r);
    }
    void init(){
        order.resize(len(left));
        iota(all(order),0);
        sort(all(order),[&](int a,int b){
            if(left[a]/width!=left[b]/width)return left[a]<left[b];
            return right[a]<right[b];
        });
    }
    int process(){
        int id=order[cur];
        while(l>left[id])dis(--l);
        while(r<right[id])dis(r++);
        while(l<left[id])dis(l++);
        while(r>right[id])dis(--r);
        return order[cur++];
    }
    inline void dis(int idx){
        v[idx].flip();
        if(v[idx])add(idx);
        else del(idx);
    }
    void add(int);
    void del(int);
};
