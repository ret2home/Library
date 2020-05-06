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
vector<int>zalgo(T v){
	vector<int>res(v.size());
	int c=0;
	REP(i,(int)v.size()){
		if(i+res[i-c]<c+res[c])res[i]=res[i-c];
		else {
			int j=max(0ll,c+res[c]-i);
			while(i+j<(int)v.size()&&v[j]==v[i+j])++j;
			res[i]=j;c=i;
		}
	}res[0]=v.size();
	return res;
}
signed main(){
	string s;cin>>s;
	for(int i:zalgo(s))cout<<i<<" ";
	cout<<endl;
}


