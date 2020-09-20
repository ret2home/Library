#pragma once
#include "../template/template.cpp"

class BIT{
	int N;
	vector<int>bit;
	void add_(int x,int y){
		while(x<=N){
			bit[x]+=y;x+=x&-x;
		}
	}
	int sum_(int x){
		int res=0;
		while(x>0){
			res+=bit[x];x-=x&-x;
		}
		return res;
	}
public:
	int lower_bound(int w){
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
	void add(int x,int y){add_(x+1,y);}
	int sum(int l,int r){return sum_(r)-sum_(l);}
	BIT(int x):N(x),bit(x+1){}
};
