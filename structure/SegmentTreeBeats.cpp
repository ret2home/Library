#pragma once
#include "../template/template.cpp"

struct SegtreeBeats{
	vector<ll>mx,smx,mxc;
	vector<ll>mn,smn,mnc;
	vector<ll>sum,lazy;
	ll size=1;
	void update_node_max(ll k,ll x){
		sum[k]+=(x-mx[k])*mxc[k];
		if(mx[k]==mn[k]){
			mx[k]=mn[k]=x;
		}else if(mx[k]==smn[k]){
			mx[k]=smn[k]=x;
		}else {
			mx[k]=x;
		}
	}
	void update_node_min(ll k,ll x){
		sum[k]+=(x-mn[k])*mnc[k];
		if(mx[k]==mn[k]){
			mx[k]=mn[k]=x;
		}else if(smx[k]==mn[k]){
			smx[k]=mn[k]=x;
		}else {
			mn[k]=x;
		}
	}
	void update_node_add(ll k,ll len,ll x){
		mx[k]+=x;
		if(smx[k]!=-inf)smx[k]+=x;
		mn[k]+=x;
		if(smn[k]!=inf)smn[k]+=x;
		sum[k]+=x*len;
		lazy[k]+=x;
	}
	void push(ll k,ll len){
		if(k>=size-1)return;
		if(lazy[k]!=0){
			update_node_add(k*2+1,len/2,lazy[k]);
			update_node_add(k*2+2,len/2,lazy[k]);
			lazy[k]=0;
		}
		if(mx[k*2+1]>mx[k])update_node_max(k*2+1,mx[k]);
		if(mx[k*2+2]>mx[k])update_node_max(k*2+2,mx[k]);
		if(mn[k*2+1]<mn[k])update_node_min(k*2+1,mn[k]);
		if(mn[k*2+2]<mn[k])update_node_min(k*2+2,mn[k]);
	}
	void update(ll k){
		sum[k]=sum[k*2+1]+sum[k*2+2];
		if(mx[2*k+1]<mx[2*k+2]){
			mx[k]=mx[2*k+2];
			mxc[k]=mxc[2*k+2];
			smx[k]=max(mx[2*k+1],smx[2*k+2]);
		}else if(mx[2*k+1]>mx[2*k+2]){
			mx[k]=mx[2*k+1];
			mxc[k]=mxc[2*k+1];
			smx[k]=max(smx[2*k+1],mx[2*k+2]);
		}else {
			mx[k]=mx[2*k+1];
			mxc[k]=mxc[2*k+1]+mxc[2*k+2];
			smx[k]=max(smx[2*k+1],smx[2*k+2]);
		}
		if(mn[2*k+1]<mn[2*k+2]){
			mn[k]=mn[2*k+1];
			mnc[k]=mnc[2*k+1];
			smn[k]=min(smn[2*k+1],mn[2*k+2]);
		}else if(mn[2*k+1]>mn[2*k+2]){
			mn[k]=mn[2*k+2];
			mnc[k]=mnc[2*k+2];
			smn[k]=min(mn[2*k+1],smn[2*k+2]);
		}else {
			mn[k]=mn[2*k+1];
			mnc[k]=mnc[2*k+1]+mnc[2*k+2];
			smn[k]=min(smn[2*k+1],smn[2*k+2]);
		}
	}
	void update_min(ll a,ll b,ll x,ll k=0,ll l=0,ll r=-1){
		if(r==-1)r=size;
		if(r<=a||b<=l||mx[k]<=x)return;
		if(a<=l&&r<=b&&smx[k]<x){
			update_node_max(k,x);
			return;
		}
		push(k,r-l);
		update_min(a,b,x,k*2+1,l,(l+r)/2);
		update_min(a,b,x,k*2+2,(l+r)/2,r);
		update(k);
	}
	void update_max(ll a,ll b,ll x,ll k=0,ll l=0,ll r=-1){
		if(r==-1)r=size;
		if(r<=a||b<=l||mn[k]>=x)return;
		if(a<=l&&r<=b&&smn[k]>x){
			update_node_min(k,x);
			return;
		}
		push(k,r-l);
		update_max(a,b,x,k*2+1,l,(l+r)/2);
		update_max(a,b,x,k*2+2,(l+r)/2,r);
		update(k);
	}
	void update_add(ll a,ll b,ll x,ll k=0,ll l=0,ll r=-1){
		if(r==-1)r=size;
		if(r<=a||b<=l)return;
		if(a<=l&&r<=b){
			update_node_add(k,r-l,x);
			return;
		}
		push(k,r-l);
		update_add(a,b,x,k*2+1,l,(l+r)/2);
		update_add(a,b,x,k*2+2,(l+r)/2,r);
		update(k);
	}
	void set(ll k,ll x){
		k+=size-1;
		mx[k]=x;mn[k]=x;sum[k]=x;
	}
	void init(){
		for(ll i=size-2;i>=0;i--)update(i);
	}
	ll query_sum(ll a,ll b,ll k=0,ll l=0,ll r=-1){
		if(r==-1)r=size;
		if(r<=a||b<=l)return 0;
		if(a<=l&&r<=b)return sum[k];
		push(k,r-l);
		ll lv=query_sum(a,b,k*2+1,l,(l+r)/2);
		ll rv=query_sum(a,b,k*2+2,(l+r)/2,r);
		return lv+rv;
	}
	SegtreeBeats(ll x){
		while(size<x)size*=2;
		mx.resize(size*2-1);smx.resize(size*2-1,-inf);mxc.resize(size*2-1,1);
		mn.resize(size*2-1);smn.resize(size*2-1,inf);mnc.resize(size*2-1,1);
		sum.resize(size*2-1);lazy.resize(size*2-1);
	}
};
