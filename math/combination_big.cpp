#pragma once
#include "modint.cpp"

template<int MOD>
struct BigCombination{
	using modint=mint<MOD>;
	modint perm(ll x,ll y){
		modint res=1;
		for(ll i=x-y+1;i<=x;i++)res*=i;
		return res;
	}
	modint comb(ll x,ll y){
		if(y>x)return 0;
		return perm(x,y)*perm(y,y).pow(MOD-2);
	}
};
