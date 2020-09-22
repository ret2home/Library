#pragma once
#include "../template/template.cpp"

template<class T>
class BIT{
	int N;
	vector<T>bit;
	void add_(int x,T y){
		while(x<=N){
			bit[x]+=y;x+=x&-x;
		}
	}
	T sum_(int x){
		T res=0;
		while(x>0){
			res+=bit[x];x-=x&-x;
		}
		return res;
	}
public:
	int lower_bound(T w){
		if(w<=0)return -1;
		int x=0;
		int k=1;while(k*2<=N)k*=2;
		for(;k>0;k/=2){
			if(x+k<=N&&bit[x+k]<w){
				w-=bit[x+k];
				x+=k;
			}
		}
		return x;
	}
	void add(int x,T y){add_(x+1,y);}
	T sum(int l,int r){return sum_(r)-sum_(l);}
	BIT(int x):N(x),bit(x+1){}
};
