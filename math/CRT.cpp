#pragma once
#include "../template/template.cpp"
#include "extgcd.cpp"

P CRT(vector<int>b,vector<int>m){
	int r=0,M=1;
	rep(i,len(b)){
		int p,q;
		int d=extGCD(M,m[i],p,q);
		if((b[i]-r)%d)return P(0,-1);
		int tmp=(b[i]-r)/d*p%(m[i]/d);
		r+=M*tmp;
		M*=m[i]/d;
	}
	return P((r%M+M)%M,M);
}