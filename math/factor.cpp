#pragma once
#include "../template/template.cpp"

int mod_pow(int x,int y,int m=mod){
	int res=1;
	while(y>0){
		if(y&1)res=(__int128_t(res)*x)%m;
		y>>=1;x=(__int128_t(x)*x)%m;
	}
	return res;
}

bool prime(int n){
	if(n<2||n%2==0)return n==2;
	int d=n-1;while(d%2==0)d>>=1;
	for(int x:{2,325,9375,28178,450775,9780504,1795265022}){
		if(n<=x)break;
		int t=d,y=mod_pow(x,t,n);
		while(t!=n-1&&y!=1&&y!=n-1){
			y=(__int128_t(y)*y)%n;t<<=1;
		}
		if(y!=n-1&&t%2==0)return false;
	}return true;
}
int rho(int n){
	if(n%2==0)return 2;
	int MOD=n;
	auto f=[&](int x){return ((__int128_t)x*x+1)%MOD;};
	auto g=[](int x,int y){
		if(x<y)return y-x;
		return x-y;
	};
	for(int x1=0;;x1++){
		for(int x=x1,y=f(x);;x=f(x),y=f(f(y))){
			int d=gcd(g(y,x),n);
			if(1<d&&d<n)return d;
			if(d==n)break;
		}
	}
}
vector<int>factor(int n){
	if(n==1)return {};
	if(prime(n))return {n};
	int d=rho(n);
	vector<int>res=factor(d);
	for(int i:factor(n/d))res.push_back(i);
	return res;
}