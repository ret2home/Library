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
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

struct UnionFind{
	vector<int>par,size;
	int find(int x){
		return (par[x]==x?x:par[x]=find(par[x]));
	}
	void merge(int x,int y){
		x=find(x);y=find(y);
		if(x==y)return;
		if(size[x]<size[y]){
			par[x]=y;
			size[y]+=size[x];
		}else {
			par[y]=x;
			size[y]+=size[x];
		}
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	UnionFind(int x){
		rep(i,x){
			par.pb(i);size.pb(1);
		}
	}
};
signed main(){
	int N,Q;
	cin>>N>>Q;
	UnionFind uf(N);
	while(Q--){
		int t,a,b;cin>>t>>a>>b;
		if(t==0)uf.merge(a,b);
		else cout<<uf.same(a,b)<<endl;
	}
}
