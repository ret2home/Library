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

int mod_pow(int x,int y,int m=mod){
	int res=1;
	while(y>0){
		if(y&1)res=(__int128_t(res)*x)%m;
		y>>=1;x=(__int128_t(x)*x)%m;
	}
	return res;
}

bool prime(int n){
	if(n<2||n%2==0)return n==2;
	int d=n-1;while(d%2==0)d>>=1;
	for(int x:{2,325,9375,28178,450775,9780504,1795265022}){
		if(n<=x)break;
		int t=d,y=mod_pow(x,t,n);
		while(t!=n-1&&y!=1&&y!=n-1){
			y=(__int128_t(y)*y)%n;t<<=1;
		}
		if(y!=n-1&&t%2==0)return false;
	}return true;
}
int rho(int n){
	if(n%2==0)return 2;
	int MOD=n;
	auto f=[&](int x){return ((__int128_t)x*x+1)%MOD;};
	auto g=[](int x,int y){
		if(x<y)return y-x;
		return x-y;
	};
	for(int x1=0;;x1++){
		for(int x=x1,y=f(x);;x=f(x),y=f(f(y))){
			int d=gcd(g(y,x),n);
			if(1<d&&d<n)return d;
			if(d==n)break;
		}
	}
}
vector<int>factor(int n){
	if(n==1)return {};
	if(prime(n))return {n};
	int d=rho(n);
	vector<int>res=factor(d);
	for(int i:factor(n/d))res.pb(i);
	return res;
}
signed main(){
	int Q;cin>>Q;
	while(Q--){
		int n;cin>>n;
		vector<int>v=factor(n);
		sort(all(v));
		cout<<v.size()<<" ";
		for(int i:v)cout<<i<<" ";
		cout<<endl;
	}
}


