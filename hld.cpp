#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back
#define fi first
#define se second

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
		int depth,par,cost;
		heavy_set(int v,int d,int par,int co)
		:ele(1,v),depth(d),par(par),cost(co){}
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
				S.emplace_back(i,S[id].depth+1,v,0);
				make_path(i,v,S.size()-1);
			}
		}
	}
	int st(int v){return stidx[v];}
	int el(int v){return eleidx[v];}
	pair<V,V>path(int u,int v){
		V res1,res2;

		while(S[stidx[u]].depth>S[stidx[v]].depth){
			res1.pb({stidx[u],{0,eleidx[u]+1}});
			u=S[stidx[u]].par;
		}
		while(S[stidx[u]].depth<S[stidx[v]].depth){
			res2.pb({stidx[v],{0,eleidx[v]+1}});
			v=S[stidx[v]].par;
		}
		while(stidx[u]!=stidx[v]){
			res1.pb({stidx[u],{0,eleidx[u]+1}});
			res2.pb({stidx[v],{0,eleidx[v]+1}});
			u=S[stidx[u]].par;v=S[stidx[v]].par;
		}
		int du=eleidx[u],dv=eleidx[v];
		if(du>dv){
			res1.pb({stidx[u],{dv,du+1}});
		}else {
			res2.pb({stidx[u],{du,dv+1}});
		}
		reverse(all(res2));
		return {res1,res2};
	}
	HLD(vector<vector<int>>&G):G(G){
		int N=G.size();
		subsize.resize(N);
		eleidx.resize(N);
		stidx.resize(N);
		S.emplace_back(0,0,0,0);
		make_path(0,0,0);
	}
};

signed main(){
	auto f=[](P a,P b){
		P res={a.first*b.first%mod,(a.second*b.first+b.second)%mod};
		return res;
	};
	auto g=[](P a,P b,int sz){
		return b;
	};
	auto f2=[](P a,P b){
		P res={a.first*b.first%mod,(b.second*a.first+a.second)%mod};
		return res;
	};

	int N,Q;
	cin>>N>>Q;
	vector<P>A(N);
	vector<vector<int>>G(N);
	for(P &i:A)cin>>i.first>>i.second;
	rep(i,N-1){
		int a,b;cin>>a>>b;
		G[a].pb(b);G[b].pb(a);
	}
	HLD hld(G);
	vector<Segtree<P,P>>segtree1,segtree2;
	rep(i,(int)hld.S.size()){
		segtree1.emplace_back(hld.S[i].ele.size(),f,g,f,P(1,0),P(1,0),P(1,0));
		segtree2.emplace_back(hld.S[i].ele.size(),f2,g,f2,P(1,0),P(1,0),P(1,0));
	}
	rep(i,N){
		segtree1[hld.st(i)].set(hld.el(i),A[i]);
		segtree2[hld.st(i)].set(hld.el(i),A[i]);
	}
	rep(i,(int)hld.S.size()){
		segtree1[i].init();
		segtree2[i].init();
	}

	while(Q--){
		int type;cin>>type;
		if(type==0){
			int p,c,d;cin>>p>>c>>d;
			segtree1[hld.st(p)].update(hld.el(p),hld.el(p)+1,{c,d});
			segtree2[hld.st(p)].update(hld.el(p),hld.el(p)+1,{c,d});
		}else {
			int u,v,x;cin>>u>>v>>x;
			auto vv=hld.path(u,v);
			P a={1,0};
			for(auto p:vv.first){
				a=f(a,segtree2[p.first].query(p.second.first,p.second.second));
			}
			for(auto p:vv.second){
				a=f(a,segtree1[p.first].query(p.second.first,p.second.second));
			}
			cout<<(a.first*x+a.second)%mod<<endl;
		}
	}
}

