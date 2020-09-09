#pragma once
#include "../template/template.cpp"

template<class T>
struct RollingHash{
	int Base=283;
	const int MASK30=(1ll<<30)-1;
	const int MASK31=(1ll<<31)-1;
	const int MOD=(1ll<<61)-1;
	vector<int>hash,power;
	int calcmod(int v){
		v=(v&MOD)+(v>>61);
		if(v>MOD)v-=MOD;
		return v;
	}
	int mul(int x,int y){
		int xu=x>>31,xd=x&MASK31;
		int yu=y>>31,yd=y&MASK31;
		int mid=xd*yu+xu*yd,midu=mid>>30,midd=mid&MASK30;
		return calcmod(xu*yu*2+midu+(midd<<31)+xd*yd);
	}
	RollingHash(T s){
		int sz=s.size();
		hash.resize(sz+1,0);power.resize(sz+1,1);
		rep(i,sz){
			hash[i+1]=calcmod(mul(hash[i],Base)+s[i]);
			power[i+1]=calcmod(mul(power[i],Base));
		}
	}
	int get(int l,int r){
		return calcmod(hash[r]-mul(hash[l],power[r-l])+MOD);
	}
	int lcp(int x,int y){
		int len=min(hash.size()-1-y,hash.size()-1-x);
		int ok=0,ng=len+1;
		while(ng-ok>1){
			int mid=(ok+ng)/2;
			if(get(x,x+mid)==get(y,y+mid))ok=mid;
			else ng=mid;
		}
		return ok;
	}
};