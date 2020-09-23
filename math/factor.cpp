#pragma once
#include "../template/template.cpp"

ll pow128(ll x,ll y,ll m){
	ll res=1;
	while(y>0){
		if(y&1)res=(__int128_t(res)*x)%m;
		y>>=1;x=(__int128_t(x)*x)%m;
	}
	return res;
}

bool prime(ll n){
	if(n<2||n%2==0)return n==2;
	ll d=n-1;while(d%2==0)d>>=1;
	for(ll x:{2,325,9375,28178,450775,9780504,1795265022}){
		if(n<=x)break;
		ll t=d,y=pow128(x,t,n);
		while(t!=n-1&&y!=1&&y!=n-1){
			y=(__int128_t(y)*y)%n;t<<=1;
		}
		if(y!=n-1&&t%2==0)return false;
	}return true;
}
ll rho(ll n){
	if(n%2==0)return 2;
	ll MOD=n;
	auto f=[&](ll x)->ll{return ((__int128_t)x*x+1)%MOD;};
	auto g=[](ll x,ll y)->ll{
		if(x<y)return y-x;
		return x-y;
	};
	for(ll x1=0;;x1++){
		for(ll x=x1,y=f(x);;x=f(x),y=f(f(y))){
			ll d=gcd(g(y,x),n);
			if(1<d&&d<n)return d;
			if(d==n)break;
		}
	}
}
vector<ll>factor(ll n){
	if(n==1)return {};
	if(prime(n))return {n};
	ll d=rho(n);
	vector<ll>res=factor(d);
	for(ll i:factor(n/d))res.push_back(i);
	return res;
}
/*
@brief Fast Prime Factorization
@docs docs/factor.md
*/