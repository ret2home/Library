#pragma once
#include "../template/template.cpp"

template<int MOD>
struct mint{
	int n;
	mint():n(0){}
	mint(int x):n(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD){}

	mint &operator+=(const mint &p){
		if((n+=p.n)>=MOD)n-=MOD;
		return *this;
	}
	mint &operator-=(const mint &p){
		if((n+=MOD-p.n)>=MOD)n-=MOD;
		return *this;
	}
	mint &operator*=(const mint &p){
		n=n*p.n%MOD;
		return *this;
	}
	mint &operator/=(const mint &p){
		*this*=p.inverse();
		return *this;
	}
	mint operator-()const{return mint(-n);}
	mint operator+(const mint &p)const{return mint(*this)+=p;}
	mint operator-(const mint &p)const{return mint(*this)-=p;}
	mint operator*(const mint &p)const{return mint(*this)*=p;}
	mint operator/(const mint &p)const{return mint(*this)/=p;}
	mint operator==(const mint &p)const{return n==p.n;}
	mint operator!=(const mint &p)const{return n!=p.n;}

	friend ostream &operator<<(ostream &os,const mint &p){
		return os<<p.n;
	}
	friend istream &operator>>(istream &is,mint &p){
		int x;is>>x;
		p=mint(x);
		return is;
	}
	mint pow(int x)const{
		mint res(1),mul(n);
		while(x>0){
			if(x&1)res*=mul;
			mul*=mul;
			x>>=1;
		}
		return res;
	}
	mint inverse()const{
		return pow(MOD-2);
	}
};
using modint=mint<mod>;

