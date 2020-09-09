#pragma once
#include "../template/template.cpp"
#include "mod_pow.cpp"

vector<int>perm,inv;
void init_perm(){
	int x=1e6+1;perm.resize(x);inv.resize(x);
	perm[0]=1;
	REP(i,x+1)perm[i]=perm[i-1]*i%mod;
	inv[x]=mod_pow(perm[x],mod-2);
	for(int i=x-1;i>=0;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
}
int nCk(int x,int y){
	if(x<y)return 0;
	return perm[x]*inv[x-y]%mod*inv[y]%mod;
}
