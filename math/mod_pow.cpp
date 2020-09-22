#pragma once
#include "../template/template.cpp"

int mod_pow(int x,int y,int m=mod){
	x%=m;
	int res=1;
	while(y>0){
		if(y&1)(res*=x)%=m;
		(x*=x)%=m;
		y>>=1;
	}
	return res;
}