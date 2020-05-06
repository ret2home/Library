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
struct RollingHash{
	int Base=283;
	const int MASK30=(1ll<<30)-1;
	const int MASK31=(1ll<<31)-1;
	const int MOD=(1ll<<61)-1;
	vector<int>hash,power;
	int calcmod(int v){
		v=(v&MOD)+(v>>61);
		if(v>MOD)v-=MOD;
		return v;
	}
	int mul(int x,int y){
		int xu=x>>31,xd=x&MASK31;
		int yu=y>>31,yd=y&MASK31;
		int mid=xd*yu+xu*yd,midu=mid>>30,midd=mid&MASK30;
		return calcmod(xu*yu*2+midu+(midd<<31)+xd*yd);
	}
	RollingHash(T s){
		int sz=s.size();
		hash.resize(sz+1,0);power.resize(sz+1,1);
		rep(i,sz){
			hash[i+1]=calcmod(mul(hash[i],Base)+s[i]);
			power[i+1]=calcmod(mul(power[i],Base));
		}
	}
	int get(int l,int r){
		return calcmod(hash[r]-mul(hash[l],power[r-l])+MOD);
	}
	int lcp(int x,int y){
		int len=min(hash.size()-1-y,hash.size()-1-x);
		int ok=0,ng=len+1;
		while(ng-ok>1){
			int mid=(ok+ng)/2;
			if(get(x,x+mid)==get(y,y+mid))ok=mid;
			else ng=mid;
		}
		return ok;
	}
};
signed main(){
	string s;cin>>s;
	RollingHash<string>RH(s);
	rep(i,s.size())cout<<RH.lcp(0,i)<<" ";
	cout<<endl;
}


