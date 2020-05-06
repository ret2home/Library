#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
void cmps(vector<int>&v,int &i){
	i=lower_bound(all(v),i)-v.begin();
}
constexpr int mod = 998244353;
constexpr int inf = LLONG_MAX;

struct SegtreeBeats{
	vector<int>mx,smx,mxc;
	vector<int>mn,smn,mnc;
	vector<int>sum,lazy;
	int size=1;
	void update_node_max(int k,int x){
		sum[k]+=(x-mx[k])*mxc[k];
		if(mx[k]==mn[k]){
			mx[k]=mn[k]=x;
		}else if(mx[k]==smn[k]){
			mx[k]=smn[k]=x;
		}else {
			mx[k]=x;
		}
	}
	void update_node_min(int k,int x){
		sum[k]+=(x-mn[k])*mnc[k];
		if(mx[k]==mn[k]){
			mx[k]=mn[k]=x;
		}else if(smx[k]==mn[k]){
			smx[k]=mn[k]=x;
		}else {
			mn[k]=x;
		}
	}
	void update_node_add(int k,int len,int x){
		mx[k]+=x;
		if(smx[k]!=-inf)smx[k]+=x;
		mn[k]+=x;
		if(smn[k]!=inf)smn[k]+=x;
		sum[k]+=x*len;
		lazy[k]+=x;
	}
	void push(int k,int len){
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
	void update(int k){
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
	void update_min(int a,int b,int x,int k=0,int l=0,int r=-1){
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
	void update_max(int a,int b,int x,int k=0,int l=0,int r=-1){
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
	void update_add(int a,int b,int x,int k=0,int l=0,int r=-1){
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
	void set(int k,int x){
		k+=size-1;
		mx[k]=x;mn[k]=x;sum[k]=x;
	}
	void init(){
		for(int i=size-2;i>=0;i--)update(i);
	}
	int query_sum(int a,int b,int k=0,int l=0,int r=-1){
		if(r==-1)r=size;
		if(r<=a||b<=l)return 0;
		if(a<=l&&r<=b)return sum[k];
		push(k,r-l);
		int lv=query_sum(a,b,k*2+1,l,(l+r)/2);
		int rv=query_sum(a,b,k*2+2,(l+r)/2,r);
		return lv+rv;
	}
	SegtreeBeats(int x){
		while(size<x)size*=2;
		mx.resize(size*2-1);smx.resize(size*2-1,-inf);mxc.resize(size*2-1,1);
		mn.resize(size*2-1);smn.resize(size*2-1,inf);mnc.resize(size*2-1,1);
		sum.resize(size*2-1);lazy.resize(size*2-1);
	}
};

signed main(){
	int N,Q;
	cin>>N>>Q;
	SegtreeBeats segtree(N);
	rep(i,N){
		int a;cin>>a;segtree.set(i,a);
	}
	segtree.init();
	while(Q--){
		int type;cin>>type;
		if(type==0){
			int l,r,b;cin>>l>>r>>b;
			segtree.update_min(l,r,b);
		}else if(type==1){
			int l,r,b;cin>>l>>r>>b;
			segtree.update_max(l,r,b);
		}else if(type==2){
			int l,r,b;cin>>l>>r>>b;
			segtree.update_add(l,r,b);
		}else {
			int l,r;cin>>l>>r;
			cout<<segtree.query_sum(l,r)<<endl;
		}
	}
}

