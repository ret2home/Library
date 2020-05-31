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
vector<int>suffixarray(T v){
	vector<int>sa(len(v)+1),rank(len(v)+1),tmp(len(v)+1);
	int n=len(v),k=1;
	rep(i,n+1){
		sa[i]=i;rank[i]=i<n?v[i]:-1;
	}
	auto f=[&](int i,int j){
		if(rank[i]!=rank[j])return rank[i]<rank[j];
		int ri=i+k<=n?rank[i+k]:-1;
		int rj=j+k<=n?rank[j+k]:-1;
		return ri<rj;
	};
	while(k<=n){
		sort(all(sa),f);
		tmp[sa[0]]=0;
		REP(i,n+1){
			tmp[sa[i]]=tmp[sa[i-1]]+f(sa[i-1],sa[i]);
		}
		rep(i,n+1)rank[i]=tmp[i];
		k*=2;
	}
	return sa;
}
signed main(){
	string s;cin>>s;
	auto v=suffixarray(s);
	REP(i,len(v))cout<<v[i]<<" ";
	cout<<endl;
}


