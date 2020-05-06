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
constexpr int inf = 3e18;

template<typename Monoid,typename OperatorMonoid>
struct Segtree{
	using F=function<Monoid(Monoid,Monoid)>;
	using G=function<Monoid(Monoid,OperatorMonoid,int)>;
	using H=function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>;
	int size=1;
	vector<Monoid>dat;
	vector<OperatorMonoid>lazy;
	const F f;
	const G g;
	const H h;
	Monoid M,M1;
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
		if(r<=a||b<=l)return M1;
		if(a<=l&&r<=b)return dat[k];
		Monoid lv=query(a,b,k*2+1,l,(l+r)/2);
		Monoid rv=query(a,b,k*2+2,(l+r)/2,r);
		return f(lv,rv);
	}
	Segtree(int x,F f,G g,H h,Monoid M,OperatorMonoid OM,Monoid M1)
	:f(f),g(g),h(h),M(M),OM(OM),M1(M1){
		while(size<x)size*=2;
		dat.resize(size*2-1,M);
		lazy.resize(size*2-1,OM);
	}
};

void RUQ_RMQ(){
	auto f=[](int a,int b){
		return min(a,b);
	};
	auto g=[](int a,int b,int sz){
		return b;
	};
	auto h=[](int a,int b){
		return b;
	};
	int N,Q;cin>>N>>Q;
	Segtree<int,int>segtree(N,f,g,h,(1ll<<31)-1,(1ll<<31)-1,(1ll<<31)-1);
	while(Q--){
		int type;
		cin>>type;
		if(type==0){
			int s,t,x;cin>>s>>t>>x;
			segtree.update(s,t+1,x);
		}else {
			int l,r;cin>>l>>r;
			cout<<segtree.query(l,r+1)<<endl;
		}
	}
}
void RAQ_RSQ(){
	auto f=[](int a,int b){
		return a+b;
	};
	auto g=[](int a,int b,int sz){
		return a+b*sz;
	};
	auto h=[](int a,int b){
		return a+b;
	};
	int N,Q;cin>>N>>Q;
	Segtree<int,int>segtree(N,f,g,h,0,0,0);
	while(Q--){
		int type;cin>>type;
		if(type==0){
			int s,t,x;cin>>s>>t>>x;s--;t--;
			segtree.update(s,t+1,x);
		}else {
			int s,t;cin>>s>>t;s--;t--;
			cout<<segtree.query(s,t+1)<<endl;
		}
	}
}
void RAQ_RMQ(){
	auto f=[](int a,int b){
		return min(a,b);
	};
	auto g=[](int a,int b,int sz){
		return a+b;
	};
	auto h=[](int a,int b){
		return a+b;
	};
	int N,Q;cin>>N>>Q;
	Segtree<int,int>segtree(N,f,g,h,0,0,inf);
	while(Q--){
		int type;
		cin>>type;
		if(type==0){
			int s,t,x;cin>>s>>t>>x;
			segtree.update(s,t+1,x);
		}else {
			int s,t;cin>>s>>t;
			cout<<segtree.query(s,t+1)<<endl;
		}
	}
}
void RUQ_RSQ(){
	auto f=[](int a,int b){
		return a+b;
	};
	auto g=[](int a,int b,int sz){
		return b*sz;
	};
	auto h=[](int a,int b){
		return b;
	};
	int N,Q;cin>>N>>Q;
	Segtree<int,int> segtree(N,f,g,h,0,inf,0);
	while(Q--){
		int type;cin>>type;
		if(type==0){
			int s,t,x;cin>>s>>t>>x;
			segtree.update(s,t+1,x);
		}else {
			int s,t;cin>>s>>t;
			cout<<segtree.query(s,t+1)<<endl;
		}
	}
}
signed main(){

}
