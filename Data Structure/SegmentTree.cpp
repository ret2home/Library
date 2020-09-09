#pragma once
#include "../template/template.cpp"

template<typename Monoid,typename OperatorMonoid,typename F,typename G,typename H>
struct Segtree{
	int size=1;
	vector<Monoid>dat;
	vector<OperatorMonoid>lazy;
	const F f;
	const G g;
	const H h;
	Monoid M;
	OperatorMonoid OM;
	void set(int a,Monoid x){
		dat[a+size-1]=x;
	}
	void init(){
		for(int i=size-2;i>=0;i--){
			dat[i]=f(dat[i*2+1],dat[i*2+2]);
		}
	}
	void eval(int k,int l,int r){
		if(lazy[k]!=OM){
			dat[k]=g(dat[k],lazy[k],(r-l));
			if(r-l>1){
				lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);
				lazy[2*k+2]=h(lazy[2*k+2],lazy[k]);
			}
			lazy[k]=OM;
		}
	}
	void update(int a,int b,OperatorMonoid M,int k=0,int l=0,int r=-1){
		if(r==-1)r=size;
		eval(k,l,r);
		if(r<=a||b<=l)return;
		if(a<=l&&r<=b){
			lazy[k]=h(lazy[k],M);
			eval(k,l,r);
			return;
		}
		update(a,b,M,k*2+1,l,(l+r)/2);
		update(a,b,M,k*2+2,(l+r)/2,r);
		dat[k]=f(dat[k*2+1],dat[k*2+2]);
	}
	Monoid query(int a,int b,int k=0,int l=0,int r=-1){
		if(r==-1)r=size;
		eval(k,l,r);
		if(r<=a||b<=l)return M;
		if(a<=l&&r<=b)return dat[k];
		Monoid lv=query(a,b,k*2+1,l,(l+r)/2);
		Monoid rv=query(a,b,k*2+2,(l+r)/2,r);
		return f(lv,rv);
	}
	template<class C>
	int minLeft(int a,int b,C &check,Monoid x,int k=0,int l=0,int r=-1){
		if(r==-1)r=size;
		eval(k,l,r);
		if(r<=a||b<=l||!check(dat[k],x))return -1;
		if(r-l==1)return l;
		int lv=minLeft(a,b,check,x,k*2+1,l,(l+r)/2);
		if(lv!=-1)return lv;
		return minLeft(a,b,check,x,k*2+2,(l+r)/2,r);
	}
	template<class C>
	int maxRight(int a,int b,C &check,Monoid x,int k=0,int l=0,int r=-1){
		if(r==-1)r=size;
		eval(k,l,r);
		if(r<=a||b<=l||!check(dat[k],x))return -1;
		if(r-l==1)return l;
		int rv=maxRight(a,b,check,x,k*2+2,(l+r)/2,r);
		if(rv!=-1)return rv;
		return maxRight(a,b,check,x,k*2+1,l,(l+r)/2);
	}
	Segtree(int x,F f,G g,H h,Monoid M,OperatorMonoid OM)
	:f(f),g(g),h(h),M(M),OM(OM){
		while(size<x)size*=2;
		dat.resize(size*2-1,M);
		lazy.resize(size*2-1,OM);
	}
};
