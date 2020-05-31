#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
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

struct HLD{
	using V=vector<pair<int,P>>;
	struct heavy_set{
		vector<int>ele;
		int depth,par,cost1=1,cost2=1;
		heavy_set(int v,int d,int par)
		:ele(1,v),depth(d),par(par){}
	};
	vector<vector<int>>G;
	vector<heavy_set>S;
	vector<int>subsize,stidx,eleidx;
	int subtree(int v,int p){
		int &sz=subsize[v];
		if(sz)return sz;
		sz=1;
		for(int i:G[v])if(i!=p)sz+=subtree(i,v);
		return sz;
	}
	void make_path(int v,int p,int id){
		stidx[v]=id;
		eleidx[v]=S[id].ele.size()-1;
		int mxidx,mx=0;
		for(int i:G[v])if(i!=p){
			if(mx<subtree(i,v)){
				mx=subtree(i,v);mxidx=i;
			}
		}
		for(int i:G[v])if(i!=p){
			if(mxidx==i){
				S[id].ele.pb(i);
				make_path(i,v,id);
			}else {
				S.emplace_back(i,S[id].depth+1,v);
				make_path(i,v,S.size()-1);
			}
		}
	}
	int st(int v){return stidx[v];}
	int el(int v){return eleidx[v];}
	HLD(vector<vector<int>>&G):G(G){
		int N=G.size();
		subsize.resize(N);
		eleidx.resize(N);
		stidx.resize(N);
		S.emplace_back(0,0,0);
		make_path(0,0,0);
	}
};
signed main(){
	int N,Q;cin>>N>>Q;
	vector<vector<int>>G(N);
	vector<P>v(N-1);
	rep(i,N-1){
		cin>>v[i].first>>v[i].second;
		v[i].first--;v[i].second--;
		G[v[i].first].pb(v[i].second);G[v[i].second].pb(v[i].first);
	}
	auto f=[](int a,int b){return a+b;};
	auto g=[](int a,int b,int sz){return b;};
	auto h=[](int a,int b){return b;};

	HLD hld(G);
	vector<Segtree<int,int>>segtree1,segtree2;
	rep(i,len(hld.S)){
		segtree1.emplace_back(len(hld.S[i].ele)-1,f,g,h,0,0,0);
		segtree2.emplace_back(len(hld.S[i].ele)-1,f,g,h,0,0,0);
		rep(j,len(hld.S[i].ele)-1){
			segtree1[i].set(j,1);
			segtree2[i].set(j,1);
		}
		segtree1[i].init();
		segtree2[i].init();
	}

	while(Q--){
		char c;cin>>c;
		if(c=='I'){
			int r,s,t;cin>>r>>s>>t;r--;
			int i=v[r].first,j=v[r].second;

			if(hld.st(i)!=hld.st(j)){
				if(hld.S[hld.st(i)].depth>hld.S[hld.st(j)].depth){
					hld.S[hld.st(i)].cost1=s;
					hld.S[hld.st(i)].cost2=t;
				}else {
					hld.S[hld.st(j)].cost1=t;
					hld.S[hld.st(j)].cost2=s;
				}
			}else {
				if(hld.el(i)>hld.el(j)){
					segtree1[hld.st(i)].update(hld.el(j),hld.el(j)+1,s);
					segtree2[hld.st(i)].update(hld.el(j),hld.el(j)+1,t);
				}else {
					segtree1[hld.st(i)].update(hld.el(i),hld.el(i)+1,t);
					segtree2[hld.st(i)].update(hld.el(i),hld.el(i)+1,s);
				}
			}
		}else {
			int x,y;cin>>x>>y;x--;y--;
			int ans=0;
			while(hld.S[hld.st(x)].depth>hld.S[hld.st(y)].depth){
				int i=hld.st(x),j=hld.el(x);
				ans+=segtree1[i].query(0,j);
				ans+=hld.S[i].cost1;
				x=hld.S[i].par;
			}
			while(hld.S[hld.st(x)].depth<hld.S[hld.st(y)].depth){
				int i=hld.st(y),j=hld.el(y);
				ans+=segtree2[i].query(0,j);
				ans+=hld.S[i].cost2;
				y=hld.S[i].par;
			}
			while(hld.st(x)!=hld.st(y)){
				int i=hld.st(x),j=hld.el(x);
				ans+=segtree1[i].query(0,j);
				ans+=hld.S[i].cost1;
				x=hld.S[i].par;
				i=hld.st(y);j=hld.el(y);
				ans+=segtree2[i].query(0,j);
				ans+=hld.S[i].cost2;
				y=hld.S[i].par;
			}
			int u=hld.el(x),v=hld.el(y);
			if(u<v){
				ans+=segtree2[hld.st(x)].query(u,v);
			}else {
				ans+=segtree1[hld.st(x)].query(v,u);
			}
			cout<<ans<<endl;
		}
	}
}
