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

template<class T>
struct SparseTable{
	using F=function<T(T,T)>;
	vector<T>table[20];
	vector<int>log;
	F f;
	SparseTable(vector<T>v,F f)
	:log(v.size()+1),f(f){
		int mx=0;
		while(1ll<<(mx+1)<=(int)v.size())++mx;
		rep(i,mx+1){
			table[i].resize(v.size());
			rep(j,v.size()-(1<<i)+1){
				if(i)table[i][j]=f(table[i-1][j],table[i-1][j+(1ll<<(i-1))]);
				else table[i][j]=v[j];
			}
		}
		for(int i=2;i<=(int)v.size();i++)log[i]=log[i>>1]+1;
	}
	T query(int l,int r){
		return f(table[log[r-l]][l],table[log[r-l]][r-(1<<log[r-l])]);
	}
};
signed main(){
	int N,Q;
	cin>>N>>Q;
	vector<int>v(N);
	for(int &i:v)cin>>i;
	SparseTable<int>ST(v,[](int a,int b){return min(a,b);});
	while(Q--){
		int l,r;cin>>l>>r;cout<<ST.query(l,r)<<endl;
	}
}


