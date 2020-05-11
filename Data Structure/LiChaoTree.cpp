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

template<class T>
struct LiChaoTree{
	struct L{
		T a,b;
		L(T a,T b):a(a),b(b){}
		bool operator==(L l){return a==l.a&&b==l.b;};
	};
	T f(L line,T x){
		return line.a*x+line.b;
	}
	int size=1;
	L ini={0,inf};
	vector<L>dat;
	vector<T>X;
	void add(int a,int b,L li,int k=0,int l=0,int r=-1){
		if(r==-1)r=size;
		if(r<=a||b<=l)return;
		int m=(l+r)/2;
		if(!(a<=l&&r<=b)){
			add(a,b,li,2*k+1,l,m);
			add(a,b,li,2*k+2,m,r);
			return;
		}
		if(dat[k]==ini){
			dat[k]=li;
			return;
		}
		int lx=X[l],mx=X[m],rx=X[r-1];
		bool left=f(li,lx)<f(dat[k],lx);
		bool mid=f(li,mx)<f(dat[k],mx);
		bool right=f(li,rx)<f(dat[k],rx);

		if(left&&right){dat[k]=li;return;}
		if(!left&&!right)return;
		if(mid)swap(li,dat[k]);
		if(left!=mid){
			add(a,b,li,2*k+1,l,m);
		}else {
			add(a,b,li,2*k+2,m,r);
		}
	}
	T query(int a,int k=0,int l=0,int r=-1){
		if(r==-1)r=size;
		if(r-l==1)return f(dat[k],X[a]);
		if(a<(l+r)/2)return min(query(a,k*2+1,l,(l+r)/2),f(dat[k],X[a]));
		else return min(query(a,k*2+2,(l+r)/2,r),f(dat[k],X[a]));
	}
	LiChaoTree(vector<T>v):X(v){
		int N=len(v);
		while(size<N)size*=2;
		dat.resize(size*2-1,ini);
		X.resize(size*2-1,1e9);
	}
};

int N,Q;
int L[200005],R[200005],x[200005],y[200005];
int l[200005],r[200005],a[200005],b[200005];
vector<int>v;
signed main(){
	cin>>N>>Q;
	rep(i,N){
		cin>>L[i]>>R[i]>>x[i]>>y[i];
		v.pb(L[i]);v.pb(R[i]);
	}
	rep(i,Q){
		int type;cin>>type;
		if(type==0){
			cin>>l[i]>>r[i]>>a[i]>>b[i];
			v.pb(l[i]);v.pb(r[i]);
		}
		else {
			cin>>a[i];v.pb(a[i]);b[i]=inf;
		}
	}
	sort(all(v));v.erase(unique(all(v)),v.end());
	LiChaoTree<int>LCT(v);
	auto idx=[&](int &x){
		x=lower_bound(all(v),x)-v.begin();
	};
	rep(i,N){
		idx(L[i]);idx(R[i]);
		LCT.add(L[i],R[i],{x[i],y[i]});
	}
	rep(i,Q){
		if(b[i]!=inf){
			idx(l[i]);idx(r[i]);
			LCT.add(l[i],r[i],{a[i],b[i]});
		}
		else {
			idx(a[i]);
			int ans=LCT.query(a[i]);
			if(ans==inf)cout<<"INFINITY"<<endl;
			else cout<<ans<<endl;
		}
	}
}

