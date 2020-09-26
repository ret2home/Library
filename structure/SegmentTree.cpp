#pragma once
#include "../template/template.cpp"

template<typename Monoid,typename OperatorMonoid,typename F,typename G,typename H>
class Segtree{
	using size_type=int32_t;
public:
	size_type size=1;
private:
	vector<Monoid>dat;
	vector<OperatorMonoid>lazy;
	const F f;
	const G g;
	const H h;
	Monoid M;
	OperatorMonoid OM;
public:
	void eval(size_type k,size_type l,size_type r){
		if(lazy[k]!=OM){
			dat[k]=g(dat[k],lazy[k],r-l);
			if(r-l>1){
				lazy[2*k+1]=h(lazy[2*k+1],lazy[k],r-l);
				lazy[2*k+2]=h(lazy[2*k+2],lazy[k],r-l);
			}
			lazy[k]=OM;
		}
	}
	void update(size_type a,size_type b,OperatorMonoid M,size_type k=0,size_type l=0,size_type r=-1){
		if(r==-1)r=size;
		eval(k,l,r);
		if(r<=a||b<=l)return;
		if(a<=l&&r<=b){
			lazy[k]=h(lazy[k],M,r-l);
			eval(k,l,r);
			return;
		}
		update(a,b,M,k*2+1,l,(l+r)/2);
		update(a,b,M,k*2+2,(l+r)/2,r);
		dat[k]=f(dat[k*2+1],dat[k*2+2],r-l);
	}
	Monoid query(size_type a,size_type b,size_type k=0,size_type l=0,size_type r=-1){
		if(r==-1)r=size;
		eval(k,l,r);
		if(r<=a||b<=l)return M;
		if(a<=l&&r<=b)return dat[k];
		Monoid lv=query(a,b,k*2+1,l,(l+r)/2);
		Monoid rv=query(a,b,k*2+2,(l+r)/2,r);
		return f(lv,rv,r-l);
	}
	template<class C>
	size_type minLeft(size_type a,size_type b,C &check,Monoid x,size_type k=0,size_type l=0,size_type r=-1){
		if(r==-1)r=size;
		eval(k,l,r);
		if(r<=a||b<=l||!check(dat[k],x))return -1;
		if(r-l==1)return l;
		size_type lv=minLeft(a,b,check,x,k*2+1,l,(l+r)/2);
		if(lv!=-1)return lv;
		return minLeft(a,b,check,x,k*2+2,(l+r)/2,r);
	}
	template<class C>
	size_type maxRight(size_type a,size_type b,C &check,Monoid x,size_type k=0,size_type l=0,size_type r=-1){
		if(r==-1)r=size;
		eval(k,l,r);
		if(r<=a||b<=l||!check(dat[k],x))return -1;
		if(r-l==1)return l;
		size_type rv=maxRight(a,b,check,x,k*2+2,(l+r)/2,r);
		if(rv!=-1)return rv;
		return maxRight(a,b,check,x,k*2+1,l,(l+r)/2);
	}
	Segtree(size_type x,F f,G g,H h,Monoid M,OperatorMonoid OM)
	:f(f),g(g),h(h),M(M),OM(OM){
		while(size<x)size*=2;
		dat.resize(size*2-1,M);
		lazy.resize(size*2-1,OM);
	}
};

/*
@brief Lazy Segment Tree
@docs docs/SegmentTree.md
*/