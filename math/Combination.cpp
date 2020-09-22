#pragma once
#include "modint.cpp"

template<int32_t MOD>
struct Combination{
	using modint=mint<MOD>;
	vector<modint>perm,inv;
	
 	Combination(int32_t x=1e6){
		perm.resize(x);inv.resize(x);
		perm[0]=modint(1);
		REP(i,x+1)perm[i]=perm[i-1]*i;
		inv[x]=perm[x].pow(MOD-2);
		for(int32_t i=x-1;i>=0;i--){
			inv[i]=inv[i+1]*(i+1);
		}
	}
	modint nCk(int32_t x,int32_t y){
		if(x<y)return modint(0);
		return perm[x]*inv[x-y]*inv[y];
	}
};
/*
@brief Combination (nCk)
@docs docs/Combination.md
*/