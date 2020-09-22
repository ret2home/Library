#pragma once
#include "../template/template.cpp"
#include "mod_pow.cpp"

int perm(int x,int y){
	int res=1;
	for(int i=x-y+1;i<=x;i++)(res*=i%mod)%=mod;
	return res;
}
int comb(int x,int y){
	if(y>x)return 0;
	return perm(x,y)*mod_pow(perm(y,y),mod-2)%mod;
}
