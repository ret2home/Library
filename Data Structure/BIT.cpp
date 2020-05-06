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

struct BIT{
	int N;
	vector<int>bit;
	void add(int x,int y){
		while(x<=N){
			bit[x]+=y;x+=x&-x;
		}
	}
	int sum(int x){
		int res=0;
		while(x>0){
			res+=bit[x];x-=x&-x;
		}
		return res;
	}
	BIT(int x):N(x),bit(x+1){}
};
signed main(){
	int N,Q;
	cin>>N>>Q;
	BIT bit(N);
	rep(i,N){
		int a;cin>>a;bit.add(i+1,a);
	}
	while(Q--){
		int type;
		cin>>type;
		if(type==0){
			int p,x;cin>>p>>x;bit.add(p+1,x);
		}else {
			int l,r;cin>>l>>r;
			cout<<bit.sum(r)-bit.sum(l)<<endl;
		}
	}
}


